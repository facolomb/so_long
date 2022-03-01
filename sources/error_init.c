/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: facolomb <facolomb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:04:30 by facolomb          #+#    #+#             */
/*   Updated: 2022/02/17 15:04:30 by facolomb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_fderror(void)
{
	ft_printf("Error\nRead FD error\n");
	exit(0);
}

void	ft_gnlerror(void)
{
	ft_printf("Error\nEmpty map !!\n");
	exit(0);
}

void	ft_callocerror(void)
{
	ft_printf("Error\nCalloc error\n");
	exit(0);
}

void	ft_argerror(void)
{
	ft_printf("Error\nMissing or too many arguments\n");
	exit(0);
}
