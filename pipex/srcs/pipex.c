/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:28:47 by atsu              #+#    #+#             */
/*   Updated: 2023/08/12 11:07:48 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void ft_pipe(t_vars vars)
{
	int pipefd[2];
	int stats;
	pid_t pid;

	if (pipe(pipefd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)
		exec_child(vars, pipefd);
	else
	{
		if (waitpid(pid, &stats, 0) == -1)
		{
			perror("waitpid");
			exit(1);
		}
		exec_parent(vars, pipefd);
	}
}

int main(int argc, char **argv, char *envp[])
{
	t_vars vars;

	if (argc != 5)
	{
		ft_putstr_fd("incorrect argument number\n", STDOUT_FILENO);
		return 0;
	}
	
	vars.file[0] = argv[1];
	vars.file[1] = argv[4];
	vars.cmd1 = ft_split(argv[2], ' ');
	vars.cmd2 = ft_split(argv[3], ' ');
	vars.envp = envp;
	ft_pipe(vars);
}
