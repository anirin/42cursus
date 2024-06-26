/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:34:48 by atokamot          #+#    #+#             */
/*   Updated: 2023/05/30 09:28:47 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[end - 1]) && start < end)
		end--;
	return (ft_substr(s1, start, end - start));
}

/*
int	main(void)
{
    printf("%s\n", ft_strtrim("  hello world  ", ""));
}
*/
