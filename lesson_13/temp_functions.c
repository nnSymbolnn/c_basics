#include "temp_functions.h"


void scan_file(measures *st, FILE *data_file, int *cur_size)
{
    int i = 0, j = 0;
    char *file_str;
    int check;

    while (fgets(file_str, 22, data_file))
    {
        check = sscanf(file_str, "%4d;%2d;%2d;%2d;%2d;%3d",&st[i].year,&st[i].month,&st[i].day,&st[i].hour,&st[i].minute,&st[i].temp);
        if (check == 6) {
            st->crt = i;
            i++;

            if (i >= (*cur_size - 2))
            {
            printf ("Run out of memory, incrissing array size (%d)\n", *cur_size);
            *cur_size = *cur_size * 2;
            st = realloc (st, (sizeof(measures) * *cur_size));
            }

        } else printf ("ERROR! line:%d data:%s", j+1, file_str);
    j++;
    }
}


void print_data(measures *st)
{
    for (int i = 0; i <= st->crt; i ++) 
        printf  ("[%d]\tDATE:%d-%d-%d\tTIME: %d:%d\tTEMP:%d\n", i+1, st[i].year,st[i].month,st[i].day,st[i].hour,st[i].minute,st[i].temp);
}


int print_month_data(measures *st, int my_month, int my_year, int *year_calculate, int year_only)
{
    int mean, i, str_count, min, max, flag;
    mean = i = str_count = min = max = flag = 0;
    while (i <= st->crt){
        if ((st[i].year == my_year) && (st[i].month == my_month)){

            if (flag == 0){
                min = st[i].temp;
                max = st[i].temp;
                flag = 1;}

            if (st[i].temp < min) min = st[i].temp;
            if (st[i].temp > max) max = st[i].temp;
            str_count ++;
            mean += st[i].temp;
        }
    i++;
    }
        
    if (flag == 0 ) {
        return 0;
    } else {
        mean = mean / str_count;
        if (year_only == 0) printf ("\t[%d-%d]\tMIN:%d\tMAX:%d\tMEAN:%d\n", my_year, my_month, min, max, mean);
        year_calculate[0] = min;
        year_calculate[1] = max;
        year_calculate[2] = mean;
        return 1;
    }
}


void get_cur_time(int *month, int *year)
{
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    *month = tm->tm_mon + 1;
    *year = tm->tm_year + 1900;
    //printf ("current date %d-%d\n", *year ,*month);
}


void print_all(measures *st, int year, int is_cur)
{
    int y_min, y_max, y_mean, mean_crt, start;
    if (is_cur == 0) start = 2000;
    else start = is_cur;

    for (int y = start; y <= year; y++){
            int year_calculate[3] = { 0 };
            mean_crt = y_mean = 0;
            y_max = -1000;
            y_min = 1000;

            for (int m = 1; m < 13; m ++){
                if (print_month_data(st, m, y, year_calculate, is_cur) !=0){
                    if (year_calculate[0] < y_min) y_min = year_calculate[0];
                    if (year_calculate[1] > y_max) y_max = year_calculate[1];
                    y_mean +=year_calculate[2];
                    mean_crt++;
                }
            }
        if (y_mean != 0) y_mean = y_mean / mean_crt;
        if ((y_min != 1000) && (y_max != -1000)) printf ("[%d]__________________MIN:%d\tMAX:%d\tMEAN:%d/\n",y ,y_min, y_max, y_mean);
    }
}


void help_function(char *arg)
{
    printf ("\tYou are running %s\n\tHeres list of applied commands:\n", arg);
    printf ("\t\t'-a'   - show DATA from all file, separeta by year + month\n");
    printf ("\t\t'-l'   - show all file content\n");
    printf ("\t\t'-m #' - show DATA from entered month in current year\n");
    printf ("\t\t'-f <path>' - input file name, file type 'csv' will add automatically\n");
}
