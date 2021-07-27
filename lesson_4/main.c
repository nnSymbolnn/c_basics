#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main (void) {

    uint32_t a;
    int8_t b;

    printf("Enter number and shift value\n");
  
    scanf("%d%" SCNi8, &a, &b);
     
    if (b > 0){
        printf ("input 0x%X shift right %d\n", a, b);     
        a = a >> b;
        printf ("Result: 0x%X\n", a);     
    } else if (b == 0){
        printf ("Zero shift is not defined!\n");     
    } else 
        {
        b = ~b + 1;
        printf ("input 0x%X shift left %d\n", a, b);     
        a = a << b;
        printf ("Result: 0x%X\n", a);
        }    
    return 0;
}