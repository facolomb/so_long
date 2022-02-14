/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strore_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 14:32:29 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/04 14:32:29 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_storeimg(t_image *img)
{
	img->grass = "./img/grass.xpm";
	img->tree = "./img/tree.xpm";
	img->collectable = "./img/sbb.xpm";
	img->end = "./img/end.xpm";
	img->charachter = "./img/lixy.xpm";
}
