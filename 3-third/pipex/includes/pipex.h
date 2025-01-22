/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:19:26 by atsu              #+#    #+#             */
/*   Updated: 2023/08/12 15:12:44 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libc.h>

typedef struct s_vars
{
	char	*file[2];
	char	**envp;
	char	**cmd1;
	char	**cmd2;
}			t_vars;

void		free_split(char **split);

//exec
void		child_proc_write(const t_vars vars, const int *pipefd);
void		child_proc_read(const t_vars vars, const int *pipefd);

//get_path
char		**get_envp(char *const envp[]);
char		*get_path(char *const envp[], const char *cmd1);

//error
int			open_create_error_exit(const t_vars vars);
void		dup2_error_exit(int fd1, int fd2);
void		close_error_exit(int fd);
void		waitpid_error_exit(int pid);
void		pipe_error_exit(int *pipefd);
int			fork_error_exit(void);

#endif
