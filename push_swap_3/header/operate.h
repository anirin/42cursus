/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:05:59 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/30 15:05:34 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
#define OPERATE_H

#include <libc.h>

#define A 0
#define B 1
#define R 2
#define C 3
#define SA 10
#define SB 11
#define SS 12
#define RA 20
#define RB 21
#define RR 22
#define PA 30
#define PB 31
#define RRA 40
#define RRB 41
#define RRR 42

void swap(t_list **list, int flag, t_list **swap_result);
void push(t_list **list_a, t_list **list_b, int flag, t_list **swap_result);
void rotate(t_list **list, int flag, t_list **swap_result);
void rev_rotate(t_list **list, int flag, t_list **swap_result);

#endif