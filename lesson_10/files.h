#include <stdio.h>
/*
Написать программу, которая копирует файл, имя которого введено пользователем в файл,
имя которого введено пользователем после.
После копирования вывести количество скопированных байт.
В случае ошибки открытия файла, вывести сообщение о невозможности открытия исходного файла.
Режим работы в файлами - двоичный( "rb", "wb" ) и так далее

например:
Enter source and destination files:
file1 file2
Сopy done. Transfered 100500 bytes

Или
Enter source and destination files:
file1 file2
Error. file1 not exists

Файл любой(текстовый, двоичный и тд)
*/

int file_copy (const char *file1, const char *file2);