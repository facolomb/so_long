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
	if (fd < 0)
		ft_fderror();
	x = 0;
	str = get_next_line(fd);
	if (!str)
		ft_gnlerror();
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

int	ft_fillmap(t_map *map, char *str, int y)
{
	int	i;

	i = 0;
	map->map[y] = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	if (!map->map[y])
		ft_callocerror();
	while (str[i] != '\n' && str[i] != '\0')
	{	
		map->map[y][i] = str[i];
		i++;
	}
	map->map[y][i] = '\0';
	return (i);
}

void	ft_map(char *map_path, t_map *map)
{
	char	*str;
	int		nblines;
	int		fd;
	int		y;
	int		lenght;

	nblines = ft_countlines(map_path);
	map->height = nblines;
	map->map = ft_calloc(sizeof(char *), nblines + 1);
	if (!map->map)
		ft_callocerror();
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		ft_fderror();
	y = 0;
	while (y < nblines)
	{
		str = get_next_line(fd);
		lenght = ft_fillmap(map, str, y);
		y++;
	}
	map->lenght = lenght;
	map->map[y] = 0;
	close(fd);
}

void	ft_initmapinfo(t_map *map)
{
	map->nbchar = 0;
	map->nbcoll = 0;
	map->nbend = 0;
	map->playercoll = 0;
	map->playermove = 0;
}
