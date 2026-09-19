#include <stdbool.h>

typedef struct block_meta
{

    size_t block_size;
    bool isfree;
    struct block_meta *next;

} META;