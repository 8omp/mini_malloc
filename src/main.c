#include <stdio.h>
#include "../include/mini_malloc.h"

int main(void){

    struct block_meta* a = (struct block_meta*)mini_malloc(100) - 1;
    struct block_meta* b = (struct block_meta*)mini_malloc(50) - 1;

    mini_free(a + 1);
    mini_free(b + 1);

    return 0;

} 