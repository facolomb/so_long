/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchappui <tchappui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:26:02 by tchappui          #+#    #+#             */
/*   Updated: 2022/02/02 14:19:37 by tchappui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000

# include "mlx/mlx.h"
# include <fcntl.h>
# include <string.h>
# include <stdio.h> 
# include <math.h>

typedef struct s_point
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_point;
#endif
