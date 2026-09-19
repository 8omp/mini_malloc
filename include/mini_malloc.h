#include <stdbool.h>

typedef struct block_meta
{

    int block_size;
    bool isfree;
    struct block_meta *next;

} META;