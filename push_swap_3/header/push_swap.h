/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:51:34 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/02 13:53:01 by atokamot         ###   ########.fr       */
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

//array
void swap_array(int *a, int *b);
int bub_sort_array(int *array, int size);
void set_array(int *array, int size, char **argv);
void set_array_num(int *array, t_list *list);
void set_array_num_by_size(int *array, t_list *list, int size);
void compress_array(int *array, int *sorted_array, int size);
void print_array(int *array, int size);

//lst_1
t_list  *set_list(int argc, int *array);
void print_list(t_list *list);
void print_swap_and_push(t_list *list);
int print_rotate(t_list *list);
void print_rev_rotate(t_list *list);

//main
void set_main_lists(t_three_lists *three_lists, int size, int *array);
int *set_main_array(int size, char **argv);

#endif