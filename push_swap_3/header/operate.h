/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:05:59 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/29 11:22:49 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_H
#define OPERATE_H

#include <libc.h>

#define A 0
#define B 1
#define R 2
#define C 3

void swap(t_list **list, int flag);
void push(t_list **list_a, t_list **list_b, int flag);
void rotate(t_list **list, int flag);
void rev_rotate(t_list **list, int flag);

#endif