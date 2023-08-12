/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:36:22 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/12 12:22:38 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void	pipe_error_exit(int *pipefd)
{
	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(1);
	}
}
