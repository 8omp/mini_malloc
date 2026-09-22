#include <unistd.h>
#include <stdio.h>
#include "../include/mini_malloc.h"

#define METASIZE sizeof(META)

struct block_meta *find_free_block(struct block_meta *head, size_t size)
{
    struct block_meta *current = head;

    while (current != NULL)
    {
        if ((current->isfree == true) && (current->block_size >= size))
        {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

struct block_meta *request_block(struct block_meta *head, size_t size)
{
    
}

void *mini_malloc(size_t size)
{
    void *ptr = sbrk(0);
    void *req = sbrk(size + METASIZE);

    META *head = NULL;

    if (req == (void *)-1)
    {
        return NULL;
    }
    else
    {
        if (ptr == req)
        {
            struct block_meta *block = (struct block_meta *)req;
            block->block_size = size;
            block->isfree = false;

            head->next = block;
            block->next = head;

            // METASIZE分、アドレスを進めたものを返すので +1だけ。 +METASIZEではない。
            // return すると強制的に void *型になる
            return block + 1;
        }
    }

    // これ二度と忘れるなよ、未定義動作
    return NULL;
}

void *mini_free(void *ptr)
{
}