/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 21:38:43 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 11:18:12 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"

t_list	*ft_lstseclast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (ft_lstsize(lst) < 2)
		return(lst);
	while (lst->next->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
