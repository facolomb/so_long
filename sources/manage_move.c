/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:19:56 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/16 14:19:56 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_increasemove(t_map *map)
{
	map->playermove++;
	ft_printf("%d\n", map->playermove);
}

void	ft_moveup(t_map *map, t_image image, int y, int x)
{
	int	img_width;
	int	img_height;

	if (map->map[map->chary - 1][map->charx] == '1')
		return ;
	if (map->map[y - 1][x] == 'E' && map->playercoll != map->nbcoll)
		return ;
	else if (map->map[y - 1][x] == 'E' && map->playercoll == map->nbcoll)
		ft_endgame(map);
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.grass, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, y * 100);
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->playercoll++;
	}
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.charachter, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, (y - 1) * 100);
	map->chary--;
	ft_increasemove(map);
}

void	ft_moveleft(t_map *map, t_image image, int y, int x)
{
	int	img_width;
	int	img_height;

	if (map->map[map->chary][map->charx - 1] == '1')
		return ;
	if (map->map[y][x - 1] == 'E' && map->playercoll != map->nbcoll)
		return ;
	else if (map->map[y][x - 1] == 'E' && map->playercoll == map->nbcoll)
		ft_endgame(map);
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.grass, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, y * 100);
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->playercoll++;
	}
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.charachter, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, (x - 1) * 100, y * 100);
	map->charx--;
	ft_increasemove(map);
}

void	ft_movedown(t_map *map, t_image image, int y, int x)
{
	int	img_width;
	int	img_height;

	if (map->map[map->chary + 1][map->charx] == '1')
		return ;
	if (map->map[y + 1][x] == 'E' && map->playercoll != map->nbcoll)
		return ;
	else if (map->map[y + 1][x] == 'E' && map->playercoll == map->nbcoll)
		ft_endgame(map);
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.grass, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, y * 100);
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->playercoll++;
	}
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.charachter, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, (y + 1) * 100);
	map->chary++;
	ft_increasemove(map);
}

void	ft_moveright(t_map *map, t_image image, int y, int x)
{
	int	img_width;
	int	img_height;

	if (map->map[map->chary][map->charx + 1] == '1')
		return ;
	if (map->map[y][x + 1] == 'E' && map->playercoll != map->nbcoll)
		return ;
	else if (map->map[y][x + 1] == 'E' && map->playercoll == map->nbcoll)
		ft_endgame(map);
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.grass, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, x * 100, y * 100);
	if (map->map[y][x] == 'C')
	{
		map->map[y][x] = '0';
		map->playercoll++;
	}
	map->void_rtn = mlx_xpm_file_to_image(
			map->mlx_ptr, image.charachter, &img_width, &img_height);
	mlx_put_image_to_window(
		map->mlx_ptr, map->win_ptr, map->void_rtn, (x + 1) * 100, y * 100);
	map->charx++;
	ft_increasemove(map);
}
