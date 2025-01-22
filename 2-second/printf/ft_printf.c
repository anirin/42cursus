/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:24:30 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/04 00:32:52 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_format_func	*set_func(void)
{
	t_format_func	*case_func;

	case_func = malloc(sizeof(case_func) * 9);
	case_func[0] = c_format;
	case_func[1] = s_format;
	case_func[2] = p_format;
	case_func[3] = d_format;
	case_func[4] = i_format;
	case_func[5] = u_format;
	case_func[6] = lo_x_format;
	case_func[7] = up_x_format;
	case_func[8] = per_format;
	return (case_func);
}

int	get_func(char c)
{
	int			i;
	const char	format[] = "cspdiuxX%";

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	size_t			count;
	t_format_func	*case_func;

	va_start(args, format);
	case_func = set_func();
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%' && get_func(*(format + 1)) != -1)
		{
			format++;
			count += case_func[get_func(*format)](args);
			format++;
		}
		else
		{
			ft_putchar_fd(*format, FD);
			format++;
			count++;
		}
	}
	va_end(args);
	free(case_func);
	return (count);
}
