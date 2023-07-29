/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:43:46 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/17 13:52:12 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.h"

int keyevent(int keycode, 	t_vars	*vars)
{
	printf("%d %p\n", keycode, vars);
	return 0;
}

int mouse(int x ,int y, 	t_vars	*vars)
{
	printf("%d %d %p\n",x, y, vars);
	return 0;
}

int mouse_down(int key, int x ,int y, 	t_vars	*vars){
	printf("%d %d %d %p\n",key, x, y, vars);
	return 0;
}