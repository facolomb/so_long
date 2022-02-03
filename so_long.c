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
#include "include/get_next_line.h"

void	ft_test(t_point *point, void *mlx_ptr, char c)
{
	char *test;
	static void *img;
	int img_width;
	int img_height;
	//test = "./img/grass.xpm";

	if (c == '0')
		test = "./img/grass.xpm";
	else if (c == '1')
		test = "./img/arbre1.xpm";
	else if (c == 'C')
		test = ".img/sbb.xpm";
	else if (c == 'E')
		test = "./img/end.xpm";
	else
		test = "./img/lixy.xpm";
	img = mlx_xpm_file_to_image(mlx_ptr, test, &img_width, &img_height);
	point->img_ptr = img;
}

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_width;
	t_point	img;
	int		fd;
	char	*str;
	char	*tmp;
	int		i;
	int		y;
	char	c;

	fd = open("test.ber", O_RDONLY);
	y = 1;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So_Long 42");
	img.img_ptr = mlx_new_image(mlx_ptr, 100, 100);
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel, &img.line_length, &img.endian);
	str = get_next_line(fd);
	while (str)
	{
		i = 0;
		//printf("%s", str);
		while (str[i])
		{
			printf("%c", str[i]);
			c = str[i];
			ft_test(&img, mlx_ptr, c);
			i++;
			mlx_put_image_to_window(mlx_ptr, win_ptr, img.img_ptr, i * 100, y * 100);
		}
		y++;
		tmp = str;
		str = get_next_line(fd);
		free(tmp);
	}
	free(str);
	mlx_loop(mlx_ptr);
	return (0);
}