/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 18:09:53 by atsu              #+#    #+#             */
/*   Updated: 2023/08/10 18:12:07 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void close_error_exit(int fd)
{
	int check;

	check = close(fd);
	if (check == -1)
	{
		perror("close");
		exit(1);
	}
}