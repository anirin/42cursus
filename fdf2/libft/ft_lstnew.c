/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:39:06 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/02 18:23:47 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (p == NULL)
		return (NULL);
	p->content = content;
	p->next = NULL;
	return (p);
}
