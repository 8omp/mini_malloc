#include <unistd.h>
#include <stdio.h>

int main(void){

    void *a = sbrk(0);
    void *b = sbrk(15);
    void *c = sbrk(0);

    printf("a: %p\n", a);
    printf("b: %p\n", b);
    printf("c: %p\n", c);

    return 0;
}