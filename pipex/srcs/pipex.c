/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:28:47 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:23:45 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void ft_pipe(t_vars vars)
{
	int pipefd[2];
	pid_t pid;

	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		exec_child(vars, pipefd);
	}
	else
	{
		exec_parent(vars, pipefd);
	}
}

int main(int argc, char **argv, char **envp)
{
	t_vars vars;

	if (argc != 5)
	{
		printf("invalid argc!\n");
		return 0;
	}
	
	vars.file[0] = argv[1];
	vars.file[1] = argv[4];
	vars.cmd1 = ft_split(argv[2], ' ');
	vars.cmd2 = ft_split(argv[3], ' ');

	ft_pipe(vars);
	free_split(vars.cmd1);
	free_split(vars.cmd2);
}