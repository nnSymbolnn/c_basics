#include <stdio.h>

#include "files.h"


int main (int *argc, int **argb){

    char file1[50] = { 0 };
    char file2[50] = { 0 };

    printf ("Enter source and destination files:\n");
    scanf ("%s%s", file1, file2);

    file_copy(file1, file2);

}