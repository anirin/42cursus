/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:28:47 by atsu              #+#    #+#             */
/*   Updated: 2023/08/12 15:57:02by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

void	ft_pipe(t_vars vars)
{
	int		pipefd[2];
	pid_t	pid_write;
	pid_t	pid_read;

	pipe_error_exit(pipefd);

	//first fork
	pid_write = fork_error_exit();
	if (pid_write == 0)
		child_proc_write(vars, pipefd);

	//second fork
	pid_read = fork_error_exit();
	if (pid_read == 0)
		child_proc_read(vars, pipefd);
	waitpid_error_exit(pid_write);
	waitpid_error_exit(pid_read);
	exit(0);
}

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;

	if (argc != 5)
	{
		ft_putstr_fd("incorrect argument number\n", STDERR_FILENO);
		exit(2);
	}
	vars.file[0] = argv[1];
	vars.file[1] = argv[4];
	vars.cmd1 = ft_split(argv[2], ' ');
	vars.cmd2 = ft_split(argv[3], ' ');
	vars.envp = envp;
	ft_pipe(vars);
}
