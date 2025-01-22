/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:58:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/08/16 16:55:41 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"
#include "../header/libft.h"

static int	get_map_width(const char *one_line)
{
	char	**split_result;
	int		count;

	split_result = ft_split(one_line, ' ');
	count = 0;
	while (1)
	{
		if (split_result == NULL || split_result[count] == NULL
			|| split_result[count][0] == '\0' || split_result[count][0] == '\n')
			break ;
		count++;
	}
	free_split(split_result);
	return (count);
}

t_wid_hig	get_map_size(const char **argv)
{
	int			fd;
	char		*one_line;
	t_wid_hig	size;

	size.w = 0;
	size.h = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(1, "open error\n", 11);
		return (size);
	}
	while (1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break ;
		if (size.w == 0)
			size.w = get_map_width(one_line);
		size.h++;
		free(one_line);
	}
	close(fd);
	return (size);
}

static void	get_map_info(char **result, t_cor *map, int width)
{
	int			x;
	static int	y = 0;
	static int	num = 0;

	x = 0;
	while (x < width)
	{
		map[num].x = (double)x;
		map[num].y = (double)y;
		if (result[x] != NULL)
			map[num].z = (double)ft_atoi(result[x]);
		else
			exit(1);
		if (ft_strchr(result[x], ',') != NULL)
			map[num].color = get_color(result[x]);
		else
			map[num].color = 0x00FFFFFF;
		num++;
		x++;
	}
	y++;
}

t_cor	*get_map(const char **argv, t_wid_hig size)
{
	char	*one_line;
	char	**split_result;
	t_cor	*map;
	int		fd;
	int		i;

	i = 0;
	map = malloc(sizeof(t_cor) * size.w * size.h);
	if (map == NULL)
		exit(1);
	fd = open(argv[1], O_RDONLY);
	while (i < size.h)
	{
		one_line = get_next_line(fd);
		split_result = ft_split(one_line, ' ');
		get_map_info(split_result, map, size.w);
		free(one_line);
		free_split(split_result);
		i++;
	}
	close(fd);
	return (map);
}

t_cor	*copy_map(t_cor *map, size_t size)
{
	size_t	i;
	t_cor	*copy_map;

	i = 0;
	copy_map = malloc(sizeof(t_cor) * size);
	if (copy_map == NULL)
		exit(1);
	while (i < size)
	{
		copy_map[i].x = map[i].x;
		copy_map[i].y = map[i].y;
		copy_map[i].z = map[i].z;
		copy_map[i].color = map[i].color;
		i++;
	}
	return (copy_map);
}
