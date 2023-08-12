/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:26 by atsu              #+#    #+#             */
/*   Updated: 2023/08/11 19:22:44 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <libc.h>

typedef struct s_vars
{
	char *file[2];
	char **envp;
	char **cmd1;
	char **cmd2;
}				t_vars;

void	free_split(char **split);

//exec
void exec_child(const t_vars vars, const int *pipefd);
void exec_parent(const t_vars vars, const int *pipefd);

//get_path
char **get_envp(char *const envp[]);
char *get_path(char *const envp[], const char *cmd1);

//open
int open_create_error_exit(const t_vars vars);

//dup2
void dup2_error_exit(int fd1, int fd2);

//close
void close_error_exit(int fd);

#endif