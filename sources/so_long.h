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

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../include/get_next_line.h"
# include "../include/ft_printf.h"
# include <fcntl.h>

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
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*void_rtn;
	char	*addr;
	int		b_per_p;
	int		line_length;
	int		endian;
	char	**map;
	int		charx;
	int		chary;
	int		nbchar;
	int		nbend;
	int		nbcoll;
	int		playercoll;
	int		lenght;
	int		height;
	int		playermove;
}		t_map;

void	ft_storeimg(t_image *img);
void	ft_map(char *map_path, t_map *map);
void	ft_initmapinfo(t_map *map);
int		ft_checkmap(t_map *map);
int		key_hook(int keycode, t_map *map);
void	ft_moveup(t_map *map, t_image image, int y, int x);
void	ft_moveleft(t_map *map, t_image image, int y, int x);
void	ft_movedown(t_map *map, t_image image, int y, int x);
void	ft_moveright(t_map *map, t_image image, int y, int x);
void	ft_checkfiletype(t_map *map, char *str);
int		ft_presscross(t_map *map);
void	ft_wrongfile(t_map *map);
void	ft_invalidmap(t_map *map);
void	ft_incorrectchar(t_map *map);
void	ft_fderror(void);
void	ft_gnlerror(void);
void	ft_callocerror(void);
void	ft_argerror(void);
void	ft_endgame(t_map *map);
void	ft_quitgame(t_map *map, int iserror);

#endif
