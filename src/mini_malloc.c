#include <unistd.h>
#include <stdio.h>
#include "../include/mini_malloc.h"

#define METASIZE sizeof(META)
static struct block_meta *global_head = NULL;

struct block_meta *find_free_block(struct block_meta *tail, size_t size)
{
    struct block_meta *current = global_head;

    while (current != NULL)
    {
        if ((current->isfree == true) && (current->block_size >= size))
        {
            tail = current;
            return current;
        }

        current = current->next;
    }

    return NULL;
}

struct block_meta *add_new_block(struct block_meta *tail, size_t size)
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
            struct block_meta *block = (struct block_meta *)req;
            block->block_size = size;
            block->isfree = false;

            if (tail != NULL)
            {
                tail->next = block;
            }
            block->next = NULL;

            return block;
        }
    }

    return NULL;
}

void *mini_malloc(size_t size)
{   
    struct block_meta *block;
    // First call
    if (global_head == NULL)
    {
        block = (struct block_meta *)add_new_block(global_head, size);
        global_head = block;
    }
    else
    {   
        struct block_meta* tail = global_head;
        block = find_free_block(tail, size); // TODO: tailはこれで伝えられているか？
        if (block != NULL)
        {   
            block->isfree = false;
        }
        else
        {
            block = add_new_block(tail, size);
        }
    }

    return block + 1;
}

void *mini_free(void *ptr)
{
}