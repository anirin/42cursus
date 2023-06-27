/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:37:36 by atokamot          #+#    #+#             */
/*   Updated: 2023/06/24 08:55:20 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int rev_flag(int flag)
{
    if (flag == A)
        return (B);
    else
        return (A);
}

int check_error(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    return (OK);
}