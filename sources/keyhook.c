/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:12:03 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/15 16:12:03 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	key_hook(int keycode, t_map *map)
{
	t_image	image;

	ft_storeimg(&image);
	if (keycode == 13)
		ft_moveup(map, image, map->chary, map->charx);
	else if (keycode == 0)
		ft_moveleft(map, image, map->chary, map->charx);
	else if (keycode == 1)
		ft_movedown(map, image, map->chary, map->charx);
	else if (keycode == 2)
		ft_moveright(map, image, map->chary, map->charx);
	else if (keycode == 53)
		ft_quitgame(map, 0);
	return (0);
}
