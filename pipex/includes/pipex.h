/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:26 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:18:55 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <libc.h>

void	free_split(char **split);

//exec
void exec_child(static t_vars vars, static int *pipefd);
void exec_parent(static t_vars vars, static int *pipefd);

//get_path
char **get_envp(static char **envp);
char *get_path(static char **envp, static char *cmd1);

//open
int open_read_exit(static t_vars vars);
int open_create_exit(static t_vars vars);

//dup2
int dup2_error(int fd1, int fd2);

typedef struct s_vars
{
	char *file[2];
	char **envp;
	char **cmd1;
	char **cmd2;
}				t_vars;

#endif