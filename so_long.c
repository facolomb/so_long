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

void	ft_test(t_point *point, void *mlx_ptr, int i)
{
	char *test;
	static void *img;
	int img_width;
	int img_height;

	//printf("i :%d\n", i);
	//if (i % 2 == 1)
		test = "./img/grass.xpm";
	//else
	//	test = "./img/arbre2.xpm";
	img = mlx_xpm_file_to_image(mlx_ptr, test, &img_width, &img_height);
	point->img_ptr = img;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_width;
	int		i;
	t_point	img;

	i = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So_Long 42");
	img.img_ptr = mlx_new_image(mlx_ptr, 50, 50);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i < 10)
	{
		ft_test(&img, mlx_ptr, i);
		i++;
		mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, i * 53, 0);
	}
	mlx_loop(mlx_ptr);
}