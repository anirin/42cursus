#include <libc.h>

int main()
{
    void *p;

    printf("%d\n", sizeof(p));
    write(1, "----\n", 5);
    write(1, p, 1);
    write(1, "\n", 1);
    write(1, "----\n", 5);
    return 0;
}