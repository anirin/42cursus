#include "ft_printf.h"
#include "libft.h"
#include <libc.h>
#include <limits.h>

int	main(void)
{
	int	i;

	// char c;
	i = 10000;
	// c = '0';
	printf("%d\n", printf("%p\n", 17));
	printf("%d\n", ft_printf("%p\n", 17));
	// i = -1234;
	// for (int n = 0;  n < 5; n++)
	// {
	//     printf("%d\n", i / 10);
	//     i /= 10;
	// }
	//gcc *.c -g -I ./libft libftprintf.a
}
