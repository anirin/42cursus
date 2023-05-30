#include "get_next_line.h"

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int main()
{
    int fd1;
    char *result;

    result = strdup("");
    fd1 = open("sample1.txt", O_RDONLY);
    //fd2 = open("sample2.txt", O_RDONLY);
    if (fd1 < 0)
    {
        printf("open error\n");
        return 0;
    }
    while (result != NULL)
    {
        result = get_next_line(fd1);
        printf("--\n");
        printf("%s\n", result);
        free(result);
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
}