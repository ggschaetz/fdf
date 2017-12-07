/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 15:58:25 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/10 11:51:29 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_declar_var(t_fdf *var)
{
	var->zoom = 50;
	var->alt = 2;
	var->decal = 1;
	var->pad_x = 400;
	var->pad_y = 400;
	var->color = 0x00FFFFFF;
}

int		ft_convert_z(char *c, t_fdf *var)
{
	int		rez;

	rez = ft_atoi(c) * var->alt;
	return (rez);
}

int		ft_convert_x(int i, int j, t_fdf *var)
{
	int		rez;

	rez = ((M_SQRT2 / 2) * (j - i) * 30) * 50 / var->zoom;
	return (var->pad_x - rez);
}

int		ft_convert_y(int i, int j, t_fdf *var)
{
	int		rez;

	rez = (((M_SQRT2 / sqrt(3)) * var->save[j][i].z) - ((1 / sqrt(6)) *\
			(i + j)) * 30) * 50 / var->zoom;
	return (var->pad_y - rez);
}
