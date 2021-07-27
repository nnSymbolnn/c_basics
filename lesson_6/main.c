#include <stdio.h>
#include <stdint.h>
#include <locale.h>
/*
С помощью getchar() и putchar() организовать от пользователя ввод данных с клавиатуры и заменить все символы в строке на следующее:
маленькие буквы английского алфавита на символ 'l'
большие буквы английского алфавита на символ 'u'
цифры на 'd'
пробелы удалить
все прочие символы на символ '*'

например:
input 12ёжз3 45 abc FG H53
output dd***dddllluuudd
*/
int main (void){
    setlocale(LC_ALL, "Russian");
    printf ("\nКириллица работает, но вывод все равно идет 1 символ = 2 считывания\n");
    char user_text;
    
    while ((user_text = getchar()) != '\n' ){
        
        if (user_text >= 'a' && user_text <= 'z') 
            user_text = ((user_text - user_text) + 'l');
        else if (user_text >= 'A' && user_text <= 'Z') 
            user_text = ((user_text - user_text) + 'u');
        else if (user_text >= '0' && user_text <= '9') 
            user_text = ((user_text - user_text) + 'd');
        else if (user_text == ' ') user_text = '\0';
        else user_text = '*';

        putchar (user_text);
    }
    printf ("\n");
    return 0;
}