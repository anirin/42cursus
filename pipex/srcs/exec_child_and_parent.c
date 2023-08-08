/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_and_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:14:56 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:23:45 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"


void exec_child(static t_vars vars, static int *pipefd)
{
	int fd;
	char *path;

	close(pipefd[0]);
	fd = open(file[0], O_RDONLY);
	if (fd1 == -1)
	{
		printf("open error\n");
		strerror(errno);
		exit(1);
	}
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	path = get_path(envp, cmd1[0]);
	execve(path, cmd1, NULL);
	perror(cmd1[0]);
}

void exec_parent(static t_vars vars, static int *pipefd)
{
	int fd;
	char *path;

	close(pipefd[1]);
	dup2_error(pipefd[0], 0);
	path = get_path(vars.envp, vars.cmd2[0]);
	if (access(vars.file[1], F_OK) != -1)
	{
		open_read_exit(vars);
		dup2_error(fd, 1);
		execve(path, vars.cmd2, NULL);
		perror(vars.cmd2[0]);
	}
	else
	{
		open_create_exit(vars);
		dup2_error(fd, 1);
		execve(path, vars.cmd2, NULL);
		perror(vars.cmd2[0]);
	}
}