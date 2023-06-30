/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 17:18:38 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 19:42:52by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/ft_lst.h"
#include "../header/operate.h"
#include "../header/sort.h"
#include "../header/push_swap.h"
#include "../header/algorithm.h"

int can_rotate(t_list **list, t_list **swap_result)
{
    if ((int)(*list)->content == (int)ft_lstlast(*list)->content + 1)
    {
        rotate(list, A, swap_result);
        return (OK);
    }
    else
        return (NG);
}

int can_swap_rotate(t_list **list, t_list **swap_result)
{
    if ( ((int)(*list)->content == (int)ft_lstlast(*list)->content + 2) && ((int)(*list)->content == (int)(*list)->next->content + 1) )
    {
        swap(list, A, swap_result);
        rotate(list, A, swap_result);
        rotate(list, A, swap_result);
        return (OK);
    }
    else
        return (NG);
}

void get_three_pivot(t_list **list, int size, int *pivot)
{
    int arry[size];

    set_arry_num(arry, *list);
    bub_sort_arry(arry, size);
    pivot[0] = arry[(size / 4) - 1];
    pivot[1] = arry[(size / 2) - 1];
    pivot[2] = arry[(size / 2) + (size / 4) - 1];
}
