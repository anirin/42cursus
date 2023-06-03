/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:28:53 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/02 22:04:13 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define OK 1
# define NG 0
# define FD 1

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <sys/types.h>

typedef size_t	(*format_func)(va_list args);

size_t			c_format(va_list ap);
size_t			s_format(va_list ap);
size_t			p_format(va_list ap);
size_t			d_format(va_list ap);
size_t			i_format(va_list ap);
size_t			u_format(va_list ap);
size_t			lo_x_format(va_list ap);
size_t			up_x_format(va_list ap);
size_t			per_format(va_list ap);
char			*rev_arry(char *s);
char			*tohex(unsigned long num, const char *hex);
int				get_func(char c);
int				ft_get_numlen(long num);
format_func		*set_func(void);
int	ft_get_unumlen(unsigned int num);
void	ft_putunbr_fd(unsigned int n, int fd);
int				ft_printf(const char *format, ...);

#endif
