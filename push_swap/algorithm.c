/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 20:40:22 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/24 10:31:51 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_location(long num, t_arry arry_info)
{
    int i;

    i = 0;
    while(i < arry_info.size)
    {
        if (arry_info.arry[i] == (int)num)
            break;
        i++;
    }
    return (i);
}

void num_min_rotate(t_list **list, long num, t_arry arry_info, int flag)
{
    t_operate *operate[2];
    int check;

    operate[0] = rotate;
    operate[1] = rev_rotate;
    if (get_location(num, arry_info) < arry_info.size / 2)
        check = 0;
    else
        check = 1;
    while(1)
    {
        if ((*list)->content == (void *)num)
            break;
        operate[check](list, flag);
    }
}

int half_push(t_list **list_1, t_list **list_2, int alpha_flag, int flag) //while rotate 1 push 1 to 2
{
    int count;
    t_arry arry_info;
    
    count = 0;
    arry_info.size = ft_lstsize(*list_1);
    arry_info.arry = malloc(sizeof(int) * arry_info.size);
    if (arry_info.arry == NULL)
        return (-1);
    set_arry(*list_1, arry_info.arry);
    //print_arry(arry_info.arry, arry_info.size);
    while (count < arry_info.size / 2)
    {
        if (check_half_arry(*list_1, arry_info, flag) == OK)
        {
            push(list_1, list_2, rev_flag(alpha_flag));
            count++;
        }
        rotate(list_1, alpha_flag);
    }
    free(arry_info.arry);
    return (count);
}

void half_push_back(t_list **list_1, t_list **list_2, int alpha_flag, int count)
{
    while(count--)
    {
        push(list_1, list_2, alpha_flag);
    }
}

void all_push_rotate(t_list **list_a, t_list **list_b)
{
    int size;
    int i;

    size = ft_lstsize(*list_b);
    i = 0;
    while(i < size)
    {
        push(list_b, list_a, A);
        i++;
    }
    i = 0;
    while(i < size)
    {
        rotate(list_a, A);
        i++;
    }
}

/*
void sort_push(t_list **list_a, t_list **list_b, t_arry arry_info)
{
    int size;
    int i;

    size = ft_lstsize(*list_a);
    i = 0;
    while (i < size)
    {
        num_min_rotate(list_a, (long)arry_info.arry[i], arry_info, A);
        push(list_a, list_b, B);
        i++;
        arry_info.size--;
    }
}
*/

// void find_rotate(t_list **list_a, long num)
// {
//     int i;
//     t_list *tmp;

//     i = 0;
//     while (1)
//     {
//         tmp = *list_a;
//         if (tmp->content == (void *)num)
//             break ;
//         rotate(list_a, A);
//         i++;
//     }
// }
