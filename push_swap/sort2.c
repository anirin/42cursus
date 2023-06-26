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

int sort_four_a(t_list **list_1, t_list **list_2, int alpha_flag, int size)
{
    int count;
    int half_size;
    int arry[size];
    t_arry arry_info;
    
    count = 0;
    arry_info.size = size;
    arry_info.arry = arry;
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
    sort_three_a(list_1, A);
    push(list_2, list_1, A);
    rotate(list_1, A);
    return (count);
}

int sort_four_b(t_list **list_1, t_list **list_2, int alpha_flag, int size)
{
    int count;
    int half_size;
    int arry[size];
    t_arry arry_info;
    
    count = 0;
    arry_info.size = size;
    arry_info.arry = arry;
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
    sort_three_b(list_1, B);
    push(list_2, list_1, B);
    return (count);
}

int sort_five_a(t_list **list_1, t_list **list_2, int alpha_flag, int size)
{
    int count;
    int half_size;
    int arry[size];
    t_arry arry_info;
    
    count = 0;
    arry_info.size = size;
    arry_info.arry = arry;
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
    sort_three_a(list_1, A);
    sort_two_b(list_2, B);
    push(list_2, list_1, A);
    push(list_2, list_1, A);
    rotate(list_1, A);
    rotate(list_1, A);
    return (count);
}


int sort_five_b(t_list **list_1, t_list **list_2, int alpha_flag, int size)
{
    int count;
    int half_size;
    int arry[size];
    t_arry arry_info;
    
    count = 0;
    arry_info.size = size;
    arry_info.arry = arry;
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
    sort_three_b(list_1, B);
    sort_two_a(list_2, A);
    push(list_2, list_1, B); //なんとかしろ
    push(list_2, list_1, B);
    return (count);
}