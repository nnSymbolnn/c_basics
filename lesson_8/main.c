#include <stdio.h>
#include <stdint.h>
    
/*
tasks:
1. На стандартном потоке ввода задан текст, состоящий из латинских букв и цифр и оканчивающийся точкой.
   На стандартный поток вывода вывести цифру, наиболее часто встречающуюся в тексте 
   (если таких цифр несколько, вывести любую из них).

2. Циклически сдвинуть массив влево на 1 элемент
   (Первый элемент становится вторым, второй - третим и так далее. Последний становится первым).

3. Сделать реверс массива(первый элемент становится последним, последний - первым и так далее)

4. Отсортировать массив по возрастанию.
*/

void print_array(int array[], int sz);

void max_common_symbol(void);
void array_shift_left(void);
int array_reverse(int my_array[], int sz);
void task_3(void);
void sort_array();


int32_t main (int *argc, int **argb){

    //max_common_symbol(); //task_1
    //array_shift_left(); //task_2
    //task_3();
    //sort_array(); //task_4
    return 0;
}

void sort_array(){

    int array[5] = { 0 };
    printf ("Enter a array (5)\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &array[i]);
    
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5-1; j++){
            if (array[j] > array[j+1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
            }
        }
    }
    print_array(array, 5);
    printf ("\n");
}

void task_3(void){
    int my_array[5] = { 0 };
    printf ("Enter a array (5)\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &my_array[i]);

    array_reverse(my_array, 5-1);
    printf ("\n");
}

int array_reverse(int my_array[], int sz){

    if (sz < 0) return 0;
    printf("%d", my_array[sz]);
    return array_reverse(my_array, sz-1);
}

void print_array(int array[], int sz){
    for (int i = 0; i < sz; i++)
        printf("%d\t", array[i]);
}

void max_common_symbol(void){
    int counters[256] = { 0 };
    char c = 0;
    int max = counters[0];
    int max_pos = counters[0];

    printf("Enter a prompt, and end it with '.'\n");

    while ((c = getchar()) != '.'){
        //printf ("~ %d \n", counters[c]);
        counters[c]++;
    }

    for (int i = 1; i < 256; i++){
        if (counters[i] > max) {
            max = counters[i];
            max_pos = i;
            }
       
    }
    printf ("\nMost common symbol is: %c, meet %d times.\n", max_pos, max);
}

void array_shift_left(void)
    {
    int my_array[5] = { 0 };
    printf ("Enter a array (5)\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &my_array[i]);

    printf ("\nWe got array:\n");
    print_array(my_array, 5);

    int tmp = my_array[4];
    for (int i = 4; i >= 0; i--){
        my_array[i] = my_array[i-1];
    }
    my_array[0] = tmp;
    
    
    printf ("\nWe got NEW array:\n");
    print_array(my_array, 5);
    printf ("\n");
    }