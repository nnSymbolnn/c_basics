#include <stdio.h>
/*
Реализовать функцию, которая возвращает сумму цифр в переданной ей строке. str_sum_digits(const char *cs)
*/
int str_sum_digits(const char *cs);


void main (int *argc, int **argb){
    char array[100];
    scanf ("%s",array);
    printf ("Sum of digits in array: %d\n",str_sum_digits(array));
}


int str_sum_digits(const char *cs)
{
    int sum = 0; 

    while (*cs){
        if (cs[0] > '0' && cs[0] <= '9') sum += *cs - '0';
    *cs++;
    }
    return sum;
}