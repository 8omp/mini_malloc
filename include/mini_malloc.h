#ifndef MINI_MALLOC_H
#define MINI_MALLOC_H

#include <stdbool.h>

typedef struct block_meta
{

    size_t block_size;
    bool isfree;
    struct block_meta *next;

} META;

struct block_meta *find_free_block(struct block_meta **tail, size_t size);
struct block_meta *add_new_block(struct block_meta *tail, size_t size);
void *mini_malloc(size_t size);
void *mini_free(void *ptr);

#endif // MINI_MALLOC_H