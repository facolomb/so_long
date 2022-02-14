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

void	*ft_imagetoput(t_point *point, t_image image, char c)
{
	char *test;
	static void *img;
	int img_width;
	int img_height;

	if (c == '0')
		img = mlx_xpm_file_to_image(point->mlx_ptr, image.grass, &img_width, &img_height);
	else if (c == '1')
		img = mlx_xpm_file_to_image(point->mlx_ptr, image.tree, &img_width, &img_height);
	else if (c == 'C')
		img = mlx_xpm_file_to_image(point->mlx_ptr, image.collectable, &img_width, &img_height);
	else if (c == 'E')
		img = mlx_xpm_file_to_image(point->mlx_ptr, image.end, &img_width, &img_height);
	else
		img = mlx_xpm_file_to_image(point->mlx_ptr, image.charachter, &img_width, &img_height);
	return (img);
}

void	ft_manageimg(t_map *map, t_point *img, t_image image)
{
	int		i;
	int		y;

	y = 0;
	while (map->map[y])
	{
		i = 0;
		while (map->map[y][i] != '\0' && map->map[y][i] != '\n')
		{
			img->void_rtn = ft_imagetoput(img, image, map->map[y][i]);
			mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->void_rtn, i * 100, y * 100);
			i++;
		}
		y++;
	}
}

int	main(void)
{
	t_point	img;
	t_image	image;
	t_map	map;
	int		fd;
	int		i;

	i = 0;
	ft_map("test.ber", &map);
	ft_printf("-----------------\n");
	while (i < 5)
	{
		ft_printf("%s\n", map.map[i]);
		i++;
	}
	img.mlx_ptr = mlx_init();
	img.win_ptr = mlx_new_window(img.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So_Long 42");
	img.img_ptr = mlx_new_image(img.mlx_ptr, 100, 100);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	ft_storeimg(&image);
	ft_manageimg(&map, &img, image);
	mlx_loop(img.mlx_ptr);
	return (0);
}
