/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:19 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:23:45 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

int open_read_exit(static t_vars vars)
{
	int fd;

	fd = open(vars.file[1], O_WRONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
}

int open_create_exit(static t_vars vars)
{
	int fd;

	fd = open(vars.file[1], O_CREAT);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
}