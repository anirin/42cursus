/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_child_and_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:14:56 by atsu              #+#    #+#             */
/*   Updated: 2023/08/13 14:28:42 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void	child_proc_write(const t_vars vars, const int *pipefd)
{
	int		fd;
	char	*path;

	close(pipefd[0]);
	fd = open(vars.file[0], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(1);
	}
	dup2_error_exit(fd, 0);
	dup2_error_exit(pipefd[1], 1);
	path = get_path(vars.envp, vars.cmd1[0]);
	if (path == NULL)
	{
		ft_putstr_fd("no path\n", STDERR_FILENO);
		exit(1);
	}
	execve(path, vars.cmd1, NULL);
	perror(vars.cmd1[0]);
	exit(1);
}

void	child_proc_read(const t_vars vars, const int *pipefd)
{
	int		fd;
	char	*path;

	close_error_exit(pipefd[1]);
	dup2_error_exit(pipefd[0], 0);
	path = get_path(vars.envp, vars.cmd2[0]);
	if (path == NULL)
	{
		ft_putstr_fd("no path\n", STDERR_FILENO);
		exit(1);
	}
	fd = open_create_error_exit(vars);
	dup2_error_exit(fd, 1);
	execve(path, vars.cmd2, NULL);
	perror(vars.cmd2[0]);
	exit(1);
}
