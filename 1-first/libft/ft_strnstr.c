/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:42:16 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/29 16:26:30 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (n && *big != '\0')
	{
		if (ft_strncmp(big, little, ft_strlen(little)) == 0
			&& ft_strlen(little) <= n)
			return ((char *)big);
		big++;
		n--;
	}
	return (NULL);
}

/*
int	main(void)
{
	printf("%s\n", strnstr("test", "", 1));
}
*/
