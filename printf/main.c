#include <libc.h>
#include "libft.h"
#include "ft_printf.h"
#include <limits.h>

int main()
{
    int i;
    // char c;

     i = 10000;
    // c = '0';
    printf("%d\n", printf("%p %d\n", NULL, 12));
    printf("%d\n", ft_printf("%p\n", NULL));

    // i = -1234;
    // for (int n = 0;  n < 5; n++)
    // {
    //     printf("%d\n", i / 10);
    //     i /= 10;
    // }
    //gcc *.c -g -I ./libft libftprintf.a
}