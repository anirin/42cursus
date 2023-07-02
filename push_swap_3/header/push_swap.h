/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:51:34 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/01 11:28:57 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <libc.h>

typedef struct s_three_lists
{
    t_list **sub_list_a;
    t_list **sub_list_b;
    t_list **sub_swap_result;
}               t_three_lists;

//arry
void swap_arry(int *a, int *b);
int bub_sort_arry(int *arry, int size);
void set_arry(int *arry, int size, char **argv);
void set_arry_num(int *arry, t_list *list);
void set_arry_num_by_size(int *arry, t_list *list, int size);
void compress_arry(int *arry, int *sorted_arry, int size);
void print_arry(int *arry, int size);

//lst_1
t_list  *set_list(int argc, int *arry);
void print_list(t_list *list);
void print_swap_and_push(t_list *list);
int print_rotate(t_list *list);
void print_rev_rotate(t_list *list);

#endif