#include "temp_functions.h"

#ifdef DEBUG
#define D if(1)
#else
#define D if(0)
#endif

int main (int argc, char **argv){

    int i = 0, cur_size = DEF_ST_SIZE, plug[3], current_month, current_year;
    FILE *data_file;
    char user_file[50] = { 0 };
    const char *opts = "alm:f:h";
    int ret;
    
    struct measures_t *my_m;
    my_m = malloc(sizeof(struct measures_t) * cur_size);
    get_cur_time(&current_month, &current_year);
    
    /*while ((ret = getopt(argc, argv, opts)) != -1){
        if (ret == 'f') strcpy (user_file,optarg);}   */
    
    //temporary solution
    scanf("%s", &user_file[0]);
    strcpy (user_file,user_file);


D printf("cur sz1=%d\n",cur_size);
    strcat (user_file,".csv");
    data_file = fopen(user_file,"r");
    if (data_file == NULL) printf("Can't open %s file.\n", user_file); 
    else scan_file(my_m, data_file, &cur_size);

    //Default current month + year summary printing
    print_month_data(my_m, current_month, current_year, plug, 0);
    print_all(my_m, current_year, current_year);
    printf ("===============================================\n");
D printf("cur sz2=%d\n",cur_size);
    while ((ret = getopt(argc, argv, opts)) != -1){
        switch (ret){
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
D printf("cur sz3=%d\n",cur_size);
    free(my_m);
    if (data_file != NULL) fclose(data_file);
    return 0;
}
