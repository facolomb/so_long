/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 16:00:10 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/04 16:00:10 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_countlines(char *map_path)
{
	int		fd;
	int		x;
	char	*str;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	x = 0;
	str = get_next_line(fd);
	while (str)
	{
		x++;
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
	}
	tmp = str;
	free(tmp);
	close(fd);
	return (x);
}

void	ft_map(char *map_path, t_map *map)
{
	char	*str;
	int		nblines;
	int		fd;
	int		i;
	int		y;

	nblines = ft_countlines(map_path);
	map->map = ft_calloc(sizeof(char *), nblines + 1);
	fd = open(map_path, O_RDONLY);
	y = 0;
	while (y < nblines)
	{
		str = get_next_line(fd);
		i = 0;
		map->map[y] = ft_calloc(sizeof(char), ft_strlen(str) + 1);
		while (str[i] != '\n' && str[i] != '\0')
		{	
			map->map[y][i] = str[i];
			ft_printf("%c", map->map[y][i]);
			i++;
		}
		ft_printf("\n");
		map->map[y][i] = '\0';
		y++;
	}
	map->map[i] = 0;
	close(fd);
}
