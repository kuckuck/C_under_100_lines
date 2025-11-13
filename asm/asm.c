#include <stdio.h>


void print()
{
    printf("print function\n");
}

int main()
{
    asm ("call print");
    //print();
    printf("complete\n");
}
