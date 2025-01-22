#include <libc.h>

int main()
{
	char *str;
	int len = 10000000;

	for(int i = 0; i < len; i++)
		write(1, "a", 1);
}