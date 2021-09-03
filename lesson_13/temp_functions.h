#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>


#define DEF_ST_SIZE 100

typedef struct measures_t{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
    int crt;
} measures;

int scan_file(measures *st, FILE *data_file, int *cur_size);
void print_data(measures *st);

void print_all(measures *st, int year, int is_cur);
int print_month_data(measures *st, int my_month, int my_year, int *year_calculate, int year_only);

void get_cur_time(int *month, int *year);
void help_function(char *arg);

#endif
