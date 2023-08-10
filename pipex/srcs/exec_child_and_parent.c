/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_and_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:14:56 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:41:08 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"


void exec_child(const t_vars vars, const int *pipefd)
{
	int fd;
	char *path;

	close(pipefd[0]);
	fd = open(vars.file[0], O_RDONLY);
	if (fd == -1)
	{
		printf("open error\n");
		exit(1);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	path = get_path(vars.envp, vars.cmd1[0]);
	execve(path, vars.cmd1, NULL);
	perror(vars.cmd1[0]);
}

void exec_parent(const t_vars vars, const int *pipefd)
{
	int fd;
	char *path;

	close(pipefd[1]);
	dup2_error(pipefd[0], 0);
	path = get_path(vars.envp, vars.cmd2[0]);
	if (access(vars.file[1], F_OK) != -1)
	{
		fd = open_read_exit(vars);
		dup2_error(fd, 1);
		execve(path, vars.cmd2, NULL);
		perror(vars.cmd2[0]);
	}
	else
	{
		fd = open_create_exit(vars);
		dup2_error(fd, 1);
		execve(path, vars.cmd2, NULL);
		perror(vars.cmd2[0]);
	}
}