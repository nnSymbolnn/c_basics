#include <stdio.h>
#include <stdint.h>
                    //  сумма      разность   произв     деление     
void math_with_args(int *summ, int *diff, int *mult, int *div);

int32_t main (int *argc, int **argb){

    int32_t summ, diff, mult = 1, div = 1;

    math_with_args(&summ, &diff, &mult, &div);
    printf ("Sum: %d\nDiff: %d\nMult: %d\nDivision: %d\n", summ, diff, mult, div);

    return 0;
}

void math_with_args(int *summ, int *diff, int *mult, int *div){
    int32_t val1, val2;
    printf ("Insert 2 values:\n");
    scanf ("%d%d", &val1, &val2);

    *summ = val1 + val2;
    *diff = val1 - val2;
    *mult = val1 * val2;
    *div = val1 / val2;
}

/*
    Написать программу, которая просит пользователя ввести 2 десятичных числа,
    и в качестве результата выводит сумму, произведение, разность и частное 
    этих двух чисел.

    Реализовать с помощью ОДНОЙ функции(указатели)

    пример заголовка функции: 
    void multi_ariphmetics(int *summ, int *diff, int *mult, int *div)
пример:
ввод:
123
456
вывод:
summ 579
diff -333
mult 56088
div 0
*/