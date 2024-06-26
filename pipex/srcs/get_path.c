/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 16:13:55 by atsu              #+#    #+#             */
/*   Updated: 2023/08/12 18:06:42 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/pipex.h"

char	**get_envp(char *const envp[])
{
	int		i;
	char	**path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
		{
			path = ft_split(envp[i] + 5, ':');
		}
		i++;
	}
	return (path);
}

char	*get_path(char *const envp[], const char *cmd1)
{
	int		i;
	char	**path;
	char	*file_path;
	char	*dir_path;

	if (access(cmd1, X_OK) == 0)
		return ((char *)cmd1);
	i = 0;
	path = get_envp(envp);
	while (path[i] != NULL)
	{
		dir_path = ft_strjoin(path[i], "/");
		file_path = ft_strjoin(dir_path, cmd1);
		free(dir_path);
		if (access(file_path, X_OK) == 0)
		{
			free_split(path);
			return (file_path);
		}
		free(file_path);
		i++;
	}
	free_split(path);
	return (NULL);
}
