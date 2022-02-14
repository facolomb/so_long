/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:02 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/02 14:19:37 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# include "mlx/mlx.h"
# include "include/get_next_line.h"
# include "include/ft_printf.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h> 
# include <math.h>

typedef struct s_point
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*void_rtn;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_point;

typedef struct s_image
{
	void	*grass;
	void	*tree;
	void	*collectable;
	void	*end;
	void	*charachter;
}		t_image;

typedef struct s_map
{
	char	**map;
	int		charx;
	int		chary;
}		t_map;

void	ft_storeimg(t_image *img);
void	ft_map(char *map_path,  t_map *map);

#endif
