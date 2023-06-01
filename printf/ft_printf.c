/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:24:30 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/01 11:34:19 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void print(const char* format, ...);
int c_case(va_list args);
int d_case(va_list args);
int s_case(va_list args);
int lf_case(va_list args);
int ft_putchar(char c);

int main(void)
{
    print("%d-%d-%c-%d", 10, 20, 'x', 30);
    print("%s-%s", "abc", "def");
    print("%d-%f-%c", 50, 3.3, 'Z');
}

int get_func(char c)
{
    char format[5] = "csdf";
    int  i;

    i = 0;
    while(format[i] != '\0') 
    {
        if (format[i] == c)
            return(i);
        i++; 
    }
    return(-1);
}

void print(const char* format, ...)
{
    va_list args;
    va_start(args, format);

    int (*case_func[4])(va_list args);

    case_func[0] = c_case;
    case_func[1] = s_case;
    case_func[2] = d_case;
    case_func[3] = lf_case;
    
    while (*format != '\0')
    {
    //for (const char* p = format; *p != '\0'; ++p) {
        if (*format == '%' && get_func(*(format + 1)) != -1)
        {
            format++;
            case_func[get_func(*format)](args);
            format++;
        }
        ft_putchar(*format);
        format++;
    }
    printf("\n");

    va_end(args);
}

int ft_putchar(char c)
{
    printf("%c", c);
    return 0; 
}

int c_case(va_list args)
{
    printf("%c", va_arg(args, char));
    return 0;
}

int d_case(va_list args)
{
    printf("%d", va_arg(args, int));
    return 0;
}

int lf_case(va_list args)
{
    printf("%lf", va_arg(args, double));
    return 0;
}

int s_case(va_list args)
{
    printf("%s", va_arg(args, char *));
    return 0;
}

int s_case(va_list args)
{
    printf("%s", va_arg(args, char *));
    return 0;
}