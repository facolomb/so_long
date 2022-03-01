/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:53:42 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/15 13:53:42 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_checkline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_ismapgood(int checkline, int nbcoll, int nbchar, int nbend)
{
	if (checkline == 2)
	{
		if (nbcoll > 0)
		{
			if (nbchar == 1)
			{
				if (nbend == 1)
					return (1);
			}
		}
	}
	return (0);
}

void	ft_checkinside(t_map *map, int y, int i)
{
	if (map->map[y][i] == 'C')
		map->nbcoll++;
	else if (map->map[y][i] == 'E')
		map->nbend++;
	else if (map->map[y][i] == 'P')
	{
		map->nbchar++;
		map->chary = y;
		map->charx = i;
	}
	else if (map->map[y][i] == '0' || map->map[y][i] == '1')
		;
	else
		ft_incorrectchar(map);
}

int	ft_checkmap(t_map *map)
{
	int	i;
	int	y;
	int	checkline;

	checkline = 0;
	y = 1;
	while (y < map->height)
	{
		i = 0;
		if (map->map[y][i] != '1')
			return (0);
		while (map->map[y][i])
		{
			ft_checkinside(map, y, i);
			i++;
		}
		if (map->map[y][i - 1] != '1')
			return (0);
		y++;
	}
	checkline += ft_checkline(map->map[0]);
	checkline += ft_checkline(map->map[map->height - 1]);
	return (ft_ismapgood(checkline, map->nbcoll, map->nbchar, map->nbend));
}

void	ft_checkfiletype(t_map *map, char *str)
{
	if (ft_strncmp(str + (ft_strlen(str) - 4), ".ber", 5) != 0)
	{
		printf("%s\n", str + (ft_strlen(str) - 4));
		ft_wrongfile(map);
	}
}
