/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:20:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/03 21:18:32 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ret;

	if (size != 0 && num > SIZE_MAX / size)
		return (NULL);
	ret = malloc(num * size);
	if (ret == NULL)
		return (NULL);
	ft_memset(ret, 0, num * size);
	return (ret);
}
