/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:12:21 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/17 11:12:21 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_invalidmap(t_map *map)
{
	ft_printf("Error\nInvalid map\n");
	ft_quitgame(map, 1);
}

void	ft_incorrectchar(t_map *map)
{
	ft_printf("Error\nIncorrect character found\n");
	ft_quitgame(map, 1);
}

void	ft_wrongfile(t_map *map)
{
	ft_printf("Error\nIncorrect type file\n");
	ft_quitgame(map, 1);
}
