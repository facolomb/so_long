/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:04:36 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/16 14:04:36 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_endgame(t_map *map)
{
	printf("%d\n", map->playermove + 1);
	printf("Victory !! Well done !!\n");
	ft_quitgame(map, 0);
}

int	ft_presscross(t_map *map)
{
	ft_quitgame(map, 0);
	return (0);
}

void	ft_quitgame(t_map *map, int iserror)
{
	while (map->height >= 0)
	{
		free(map->map[map->height]);
		map->height--;
	}
	free(map->map);
	if (iserror == 0)
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
}
