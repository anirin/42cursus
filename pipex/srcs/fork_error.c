/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:08:59 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/12 15:12:30 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

int fork_error_exit(void)
{
	int ret;

	ret = fork();
	if (ret < 0)
	{
		perror("fork");
		exit(1);
	}
	return (ret);
}