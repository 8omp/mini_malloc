#include <unistd.h>
#include <stdio.h>
#include "../include/mini_malloc.h"

#define METASIZE sizeof(META)

void *mini_malloc(size_t size)
{
    void *ptr = sbrk(0);
    void *req = sbrk(size + METASIZE);

    if (req == (void *)-1)
    {
        return NULL;
    }
    else
    {
        if (ptr == req)
        {   
            struct block_meta* true_req = (struct block_meta*) req;
            true_req->block_size = size;
            true_req->isfree = false;
            true_req->next = NULL; //TODO: 多分ここ直さなあかん

            // METASIZE分、アドレスを進めたものを返すので +1だけ。 +METASIZEではない。
            // return すると強制的に void *型になる
            return true_req + 1;
        }
    }

    // これ二度と忘れるなよ、未定義動作
    return NULL;
}

void *mini_free(void *ptr)
{
}