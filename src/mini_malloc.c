#include <unistd.h>
#include <stdio.h>
#include "../include/mini_malloc.h"

#define METASIZE sizeof(META)
static struct block_meta *global_head = NULL;

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

struct block_meta *request_block(struct block_meta *head, struct block_meta *tail, size_t size)
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

            if(tail != NULL){
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
    // First call
    if(global_head == NULL){
        global_head = (struct block_meta *)request_block(global_head, global_head, size);
        return global_head;
    }

    // これ二度と忘れるなよ、未定義動作
    return NULL;
}

void *mini_free(void *ptr)
{
}