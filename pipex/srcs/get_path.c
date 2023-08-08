/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:13:55 by atsu              #+#    #+#             */
/*   Updated: 2023/08/08 16:23:45 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

char **get_envp(static char **envp)
{
	int i;
	char **path;

	i = 0;
	path = NULL;
	while(envp[i])
	{
		if (strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
		}
		i++;
	}
	return (path);
}

char *get_path(static char **envp, static char *cmd1)
{
	int i;
	char **path;
	char *file_path;
	char *dir_path;

	i = 0;
	path = get_envp(envp);
	while(path[i] != NULL)
	{
		dir_path = ft_strjoin(path[i], "/");
		free(path[i]);
		file_path = ft_strjoin(dir_path, cmd1);
		free(dir_path);
		if(access(file_path, 0) == 0)
		{
			return (file_path);
		}
		free(file_path);
		i++;
	}
	return (NULL);
}
