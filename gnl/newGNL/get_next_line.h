#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

typedef struct s_getchar{
    char    buf[BUFFER_SIZE];
    char    *bufp;
    int     check;
}       t_getchar;

//utils

//gnl

#endif