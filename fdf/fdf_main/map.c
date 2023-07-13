/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atokamot <atokamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 07:58:42 by atokamot          #+#    #+#             */
/*   Updated: 2023/07/13 23:36:14 by atokamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./header/libft.h"
#include "./header/fdf.h"

int get_map_width(char *one_line)
{
    char **split_result;
    int count;

    split_result = ft_split(one_line, ' ');
    count = 0;
    while(1)
    {
        if (split_result[count] == NULL)
            break;
        free(ft_split[count]);
        count++;
    }
    free(split_result);
    return (count);
}

int get_map_size(char **argv)
{
	int w;
	int h;

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
	return (w * h);
}

void get_map_info(char **result, t_cor *map)
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
		free(result[x]);
        num++;
		x++;
	}
	y++;
}

t_data *get_map(char **argv)
{
	char *one_line;
	char **split_result;
	t_cor *map;

	map = malloc(sizeof(t_cor) * get_map_size);
	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		one_line = get_next_line(fd);
		split_result = split(one_line);
		if (one_line == NULL)
			break;
		get_map(split_result, &map);
		free(one_line);
		free(split_result);
	}
	free(map);
	close(fd);
    return (map);
}