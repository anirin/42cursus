/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitpid_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:41:40 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/12 16:16:23 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void	waitpid_error_exit(int pid)
{
	int	stats;

	(void)pid;
	if (waitpid(pid, &stats, 0) == -1)
	{
		perror("waitpid");
		exit(1);
	}
}
