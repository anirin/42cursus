#include "get_next_line.h"

__attribute__((destructor))
static void	destructor(void) {
    system("leaks -q a.out");
}

int	main(void)
{
	int		fd1;
	char	*result;
	int		i;

	result = NULL;
	fd1 = open("sample1.txt", O_RDONLY);
	//fd2 = open("sample2.txt", O_RDONLY);
	if (fd1 < 0)
	{
		printf("open error\n");
		return (0);
	}
	i = 0;
	while (1)
	{
		printf("------------------\n");
		result = get_next_line(fd1);
		printf("%s\n", result);
		free(result);
		//system("leaks -q a.out");
		if (result == NULL)
			break ;
	}
	// int i;
	// i = 0;
	// while (i < 1)
	// {
	//     result = get_next_line(fd1);
	//     printf("/--\n");
	//     printf("%s\n", result);
	//     printf("--/\n\n");
	//     free(result);
	//     i++;
	// }
	close(fd1);
}
