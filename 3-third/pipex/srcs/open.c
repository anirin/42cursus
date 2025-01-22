/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:25:19 by atsu              #+#    #+#             */
/*   Updated: 2023/08/12 11:33:26 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

int	open_create_error_exit(const t_vars vars)
{
	int	fd;

	fd = open(vars.file[1], O_CREAT | O_WRONLY | O_TRUNC,
			S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	return (fd);
}
