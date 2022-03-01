/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:25:08 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/02 14:25:08 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	*ft_imagetoput(t_map *map, t_image image, char c)
{
	static void	*img;
	int			img_width;
	int			img_height;

	if (c == '0')
		img = mlx_xpm_file_to_image(
				map->mlx_ptr, image.grass, &img_width, &img_height);
	else if (c == '1')
		img = mlx_xpm_file_to_image(
				map->mlx_ptr, image.tree, &img_width, &img_height);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(
				map->mlx_ptr, image.collectable, &img_width, &img_height);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(
				map->mlx_ptr, image.end, &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(
				map->mlx_ptr, image.charachter, &img_width, &img_height);
	return (img);
}

void	ft_manageimg(t_map *map, t_image image)
{
	int		i;
	int		y;

	y = 0;
	while (map->map[y])
	{
		i = 0;
		while (map->map[y][i] != '\0' && map->map[y][i] != '\n')
		{
			map->void_rtn = ft_imagetoput(map, image, map->map[y][i]);
			mlx_put_image_to_window(
				map->mlx_ptr, map->win_ptr, map->void_rtn, i * 100, y * 100);
			i++;
		}
		y++;
	}
}

void	ft_init_mlx(t_map *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(
			map->mlx_ptr, map->lenght * 100, map->height * 100, "So_Long 42");
	map->img_ptr = mlx_new_image(
			map->mlx_ptr, 100, 100);
	map->addr = mlx_get_data_addr(
			map->img_ptr, &map->b_per_p, &map->line_length, &map->endian);
}

int	main(int argc, char **argv)
{
	t_image	image;
	t_map	map;

	if (argc == 2)
	{
		ft_map(argv[1], &map);
		ft_checkfiletype(&map, argv[1]);
		ft_initmapinfo(&map);
		if (ft_checkmap(&map) == 0)
			ft_invalidmap(&map);
		ft_init_mlx(&map);
		ft_storeimg(&image);
		ft_manageimg(&map, image);
		mlx_key_hook(map.win_ptr, key_hook, &map);
		mlx_hook(map.win_ptr, 17, 0, ft_presscross, &map);
		mlx_loop(map.mlx_ptr);
	}
	else
		ft_argerror();
	return (0);
}
