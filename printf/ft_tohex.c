#include <libc.h>

char *rev_arry(char *s)
{
    int len;
    int i;
    char tmp[17];

    if (s == NULL)
        return (NULL);
    len = strlen(s);
    i = 0;
    while(len)
    {
        tmp[i++] = s[len-- - 1];
    }
    strlcpy(s, tmp, strlen(s));
    return (s);
}

char *to_hex(long num)
{
    char *hex_num;
    const char hex[] = "0123456789ABCDEF";
    int i;

    i = 0;
    hex_num = calloc(17, 1);
    if (hex_num == NULL)
        return (NULL);
    if (num == 0)
    {
        hex_num[i] = hex[0];        
        return (hex_num);
    }
    if (num < 0)
    {
        hex_num[i++] = '-';
        num *= -1;
    }
    while (num > 0)
    {
        hex_num[i++] = hex[num % 16];
        num /= 16;
    }
    return (hex_num);
}

//test
int main()
{
    char *s;

    s = to_hex(111111111);
    s = rev_arry(s);
    printf("%s\n", s);
    return 0;
}