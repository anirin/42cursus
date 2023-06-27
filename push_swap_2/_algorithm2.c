/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _algorithm2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 09:19:55 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/27 09:08:50y atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int first_finish_condition(t_list **list_a, t_list **list_b)
{
    if(ft_lstsize(*list_a) == 2)
        sort_two_a(list_a);
    if(ft_lstsize(*list_a) == 3)
        sort_three_a(list_a);
    if(ft_lstsize(*list_a) == 4)
        sort_four_a(list_a, list_b);
    if(ft_lstsize(*list_a) == 5)
        sort_five_a(list_a, list_b);
    if (ft_lstsize(*list_a) <= 5)
        return (OK);
    else
        return (NG);
}

int finish_condition(t_list **list_a, t_list **list_b)
{
    if(ft_lstsize(*list_b) == 2)
        sort_two_b(list_b);
    if(ft_lstsize(*list_b) == 3)
        sort_three_b(list_b);
    if(ft_lstsize(*list_b) == 4)
        sort_four_b(list_b, list_a);
    if(ft_lstsize(*list_b) == 5)
        sort_five_b(list_b, list_a);
    if (ft_lstsize(*list_b) <= 5)
    {
        all_push_rotate(list_a, list_b);
        return (OK);
    }
    else
        return (NG);
}

void recursive_one_third(t_list **list_a, t_list **list_b)
{
    int size;

    if (finish_condition(list_a, list_b) == OK)
        return ;
    size = ft_lstsize(*list_b);
    two_third_push(list_a, list_b, size);
    if (finish_condition(list_a, list_b) == NG)
        recursive_one_third(list_a, list_b);
    one_third_push_back(list_a, list_b, size / 3);
    if (finish_condition(list_a, list_b) == NG)
        recursive_one_third(list_a, list_b);
    one_third_push_back(list_a, list_b, size - (size / 3) * 2);
    if (finish_condition(list_a, list_b) == NG)
        recursive_one_third(list_a, list_b);
}

void first_one_third(t_list **list_a, t_list **list_b)
{
    int size;
    int pivod[2];


    if (first_finish_condition(list_a, list_b) == OK)
        return ;
    size = ft_lstsize(*list_a);
    get_pivot(list_a, ft_lstsize(*list_a), pivod);
    first_one_third_push(list_b, list_a, pivod[0], size / 3);
    recursive_one_third(list_a, list_b);
    first_one_third_push(list_b, list_a, pivod[1], size / 3);
    recursive_one_third(list_a, list_b);
    one_third_push(list_b, list_a, pivod[1], size - (size / 3) * 2);
    recursive_one_third(list_a, list_b);
}

/*----------------------------------
    if (finish_condition() == NG)
        return ;
    two_third_push(size); 2/3 push
        if (finish_condition() == NG)
            recursive_one_third(); 1/3 sort
    one_third_push_back(size / 3); middle 1/3 push back
        if (finish_condition() == NG)
            recursive_one_third(); middle 1/3 sort
    one_third_push_back(size - (size / 3) * 2); big 1/3 + a
        if (finish_condition() == NG)
            recursive_one_third(); big 1/3 sort

----------------------------------

    two_third_push(size)
        get_pivot(size) //remainder becareful
        big_one_third_push(pivot[2])
        middle_one_third_push(pivot[1])
----------------------------------*/
