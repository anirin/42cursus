/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:39:55 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:37:57 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void dup2_error(int fd1, int fd2)
{
	int check;

	check = dup2(fd1, fd2);
	if (check == -1)
	{
		perror("dup2");
		exit(1);
	}
}