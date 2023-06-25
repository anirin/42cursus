/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 18:20:26 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/25 18:49:55by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sort_four_a(t_list **list_1, t_list **list_2, int alpha_flag)
{
    int count;
    int half_size;
    t_arry arry_info;
    
    count = 0;
    arry_info.size = ft_lstsize(*list_1);
    arry_info.arry = malloc(sizeof(int) * arry_info.size);
    if (arry_info.arry == NULL)
        return (-1);
    set_arry(*list_1, arry_info.arry);
    while (count < 1)
    {
        if (check_num_arry(*list_1, arry_info, 1) == OK)
        {
            push(list_1, list_2, rev_flag(alpha_flag));
            count++;
        }
        else
            rotate(list_1, alpha_flag);
    }
    free(arry_info.arry);
    sort_three_a(list_1, A);
    all_push_rotate(list_1, list_2);
    return (count);
}

int sort_four_b(t_list **list_1, t_list **list_2, int alpha_flag)
{
    int count;
    int half_size;
    t_arry arry_info;
    
    count = 0;
    arry_info.size = ft_lstsize(*list_1);
    arry_info.arry = malloc(sizeof(int) * arry_info.size);
    if (arry_info.arry == NULL)
        return (-1);
    set_arry(*list_1, arry_info.arry);
    while (count < 1)
    {
        if (check_num_arry(*list_1, arry_info, 1) == OK)
        {
            push(list_1, list_2, rev_flag(alpha_flag));
            count++;
        }
        else
            rotate(list_1, alpha_flag);
    }
    free(arry_info.arry);
    sort_three_b(list_1, B);
    all_push_rotate(list_1, list_2);
    return (count);
}

int sort_five_a(t_list **list_1, t_list **list_2, int alpha_flag)
{
    int count;
    int half_size;
    t_arry arry_info;
    
    count = 0;
    arry_info.size = ft_lstsize(*list_1);
    arry_info.arry = malloc(sizeof(int) * arry_info.size);
    if (arry_info.arry == NULL)
        return (-1);
    set_arry(*list_1, arry_info.arry);
    while (count < 2)
    {
        if (check_num_arry(*list_1, arry_info, 2) == OK)
        {
            push(list_1, list_2, rev_flag(alpha_flag));
            count++;
        }
        else
            rotate(list_1, alpha_flag);
    }
    free(arry_info.arry);
    sort_three_a(list_1, A);
    sort_two_b(list_2, B);
    all_push_rotate(list_1, list_2);
    return (count);
}