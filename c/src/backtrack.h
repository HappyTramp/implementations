#ifndef __BACKTRACKING_H__
# define __BACKTRACKING_H__

# include <stddef.h>
# include <stdbool.h>

typedef struct
{
    int *cols_positions;
    size_t size;
    int curr_x;
    int curr_y;
} Queens;

void backtrack(void *data, bool (*reject)(void *), bool (*accept)(void *),
               void *(*first)(void *), void *(*next)(void *), void (*output)(void *));
void backtrack_queens(size_t board_size);

#endif
