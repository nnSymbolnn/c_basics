#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
/*
Написать программу, принимающую со стандартного потока ввода целое число, и затем выводит все простые числа до указанного числа. Задачу разбить на функции. Использовать оба вида циклов(while и for)
Первая функция(не main) читает значение со стандартного потока ввода(scanf) и возвращает это значение(через return)
Вторая функция с помощью цикла while считает простые числа
Третья функция с помощью цикла for считает простые числа
*/

int scan_val(void);
void sum_dig_while(int number);
void sum_dig_for(int number);


void main () {

    int usr_value = scan_val();
    
    printf("\nReturn all values behind %d\n", usr_value);
    sum_dig_while(usr_value);
    printf("\nNow with 'for'\n");
    sum_dig_for(usr_value);

}


int scan_val(){
    uint32_t scan_num;

    printf("insert value:\n");
    scanf ("%d", &scan_num);

    return scan_num;
}

void sum_dig_while(int number){
    int cntr = 0, summ = 0;

    while (cntr < number - 1){
        cntr++;
        //if (cntr == 0) continue;
        printf ("number %d, count = %d\n", cntr, summ+=cntr);
    }
    
}

void sum_dig_for(int number){
    int summ = 0;

    for (int i = 0; i < number; i ++){
        printf ("number %d, count = %d\n", i, summ+=i);
    }
    
}