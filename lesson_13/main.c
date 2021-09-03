#include "temp_functions.h"
#include <string.h>

int main (int argc, char **argv){

    int i = 0, cur_size = DEF_ST_SIZE, plug[3], current_month, current_year;
    FILE *data_file;
    char user_file[50] = { 0 };
    const char *opts = "alm:f:h";
    int ret;
    int out_of_memory_check;
    get_cur_time(&current_month, &current_year);
    struct measures_t *my_m;
    my_m = (struct measures_t *)malloc(sizeof(struct measures_t) * cur_size);

    while ((ret = getopt(argc, argv, opts)) != -1){
        switch (ret){
            case 'f' : 
                strcpy (user_file,optarg);
                strcat (user_file,".csv");
                data_file = fopen(user_file,"r");
                if (data_file == NULL) {printf("Can't open %s file.\n", user_file);
                    return 0;}
                out_of_memory_check = scan_file(my_m, data_file, &cur_size);
                if (out_of_memory_check == 1)
                    do {
                        my_m = (struct measures_t *)realloc(my_m, (sizeof(struct measures_t) * cur_size));
                        out_of_memory_check = scan_file(my_m, data_file, &cur_size);
                    } while (out_of_memory_check == 1);
                break;
            case 'a' :
                printf ("===============================================\n");
                print_all(my_m, current_year, 0);
                printf ("===============================================\n"); break; 
            case 'l' : print_data(my_m); break;
            case 'm' : print_month_data(my_m, atoi(optarg), current_year, plug, 0); break;
            case 'h' : help_function(argv[0]); break;
            case '?' : printf("Error!"); break;
        }
    }

    //Default current month + year summary printing
    printf ("-----------------------------------------------\n"); 
    print_month_data(my_m, current_month, current_year, plug, 0);
    print_all(my_m, current_year, current_year);
    printf ("===============================================\n");

    free (my_m);
    if (data_file != NULL) fclose(data_file);
    return 0;
}
