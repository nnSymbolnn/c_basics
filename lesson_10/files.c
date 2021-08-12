#include <stdio.h>
#include <stdint.h>

#include "files.h"

int file_copy (const char *file1, const char *file2)
{
    size_t sz = 0;
    FILE *f_orig, *f_copy;
    int error_flag = 0;
    char ch;

    f_orig = fopen(file1,"rb");
    if (f_orig == NULL) error_flag = 1;

    if (error_flag == 1) {
        printf ("Error! File doesn't exist!\n");
        fclose(f_orig);
        return -1;
    }

    f_copy = fopen(file2,"wb");
    while ((ch = fgetc(f_orig)) != EOF) fputc(ch, f_copy);

    fseek(f_copy, 0, SEEK_END);
    sz = ftell(f_copy);
    printf("Сopy done. Transfered %lu bytes\n", sz);

    fclose(f_orig);
    fclose(f_copy);
    return 0;
}