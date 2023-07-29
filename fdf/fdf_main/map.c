/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:58:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/29 18:10:28 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../header/fdf.h"

static int get_map_width(const char *one_line)
{
    char **split_result;
    int count;

    split_result = ft_split(one_line, ' ');
    count = 0;
    while(1)
    {
        if (split_result[count] == NULL)
            break;
        free(split_result[count]);
        count++;
    }
    free(split_result);
    return (count);
}

t_wid_hig get_map_size(const char **argv)
{
	int w;
	int h;
	int fd;
	char *one_line;

	w = 0;
	h = 0;
	fd = open(argv[1], O_RDONLY);
	while(1)
	{
		one_line = get_next_line(fd);
		if (one_line == NULL)
			break;
		if (w == 0)
			w = get_map_width(one_line);
		h++;
		free(one_line);
	}
	close(fd);
	t_wid_hig size;
	size.w = w;
	size.h = h;
	return (size);
}

static void get_map_info(char **result, t_cor *map)
{
	int x;
	static int y = 0;
	static int num = 0;
	
	x = 0;
	while(result[x] != NULL)
	{
		map[num].x = (double)x;
		map[num].y = (double)y;
		map[num].z = (double)ft_atoi(result[x]);
		if (strchr(result[x], ','))
			map[num].color = get_color(result[x]);//get color 
		else
			map[num].color = 0x00ffffff;
		free(result[x]);
        num++;
		x++;
	// printf("(x, y) = (%d, %d)\n", x, y);
	}
	y++;
}

t_cor *get_map(const char **argv, size_t size)
{
	char *one_line;
	char **split_result;
	t_cor *map;
	int fd;

	map = malloc(sizeof(t_cor) * size);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		one_line = get_next_line(fd);
		split_result = ft_split(one_line, ' ');
		if (one_line == NULL)
			break;
		get_map_info(split_result, map);
		free(one_line);
		free(split_result);
	}
	// free(map);
	close(fd);
    return (map);
}

t_cor *copy_map(t_cor *map, size_t size)
{
	size_t i;
	t_cor *copy_map;

	i = 0;
	copy_map = malloc(sizeof(t_cor) * size);
	while(i < size)
	{
		copy_map[i].x = map[i].x;	
		copy_map[i].y = map[i].y;	
		copy_map[i].z = map[i].z;	
		i++;
	}
	return (copy_map);
}

void zoom_cor(t_cor *map, int size, int zoom)
{
	int i;

	i = 0;
	while (i < size)
	{
		map[i].x *= zoom;
		map[i].y *= zoom;
		map[i].z *= zoom;
		i++;
	}
}
