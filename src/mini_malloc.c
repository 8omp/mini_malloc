#include <unistd.h>
#include <stdio.h>
#include "../include/mini_malloc.h"

#define METASIZE sizeof(META);

void *mini_malloc(int size)
{
    void *ptr = sbrk(0);
    void *req = sbrk(size);

    if (ptr == (void *)-1)
    {
        return NULL;
    }
    else
    {
        if (ptr == req)
        {
            return req + METASIZE;
        }
    }
}

void *mini_free(void *ptr)
{
}