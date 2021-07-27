#include <stdio.h>
/*
Ввести число типа float с клавиатуры и вывести второй знак после запятой
Например: ввели число 123.4567

result 5
*/
int main (void){
    float a;
    int b;
    printf("Please insert a value: \n");
    scanf("%f", &a);
    b = a *= 10;
    a *= 10;
    b *= 10;

    int c = a; //Переменная, что бы число не округлялось
    c = a - b;
    
    printf("\nsecond num after point: %d\n", c);

    return 0;
}