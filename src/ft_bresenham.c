/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:27:34 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/08 17:38:30 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	ft_choice(int y, int x1, int y1, t_fdf *var)
{
	int		x;

	x = var->ind;
	if (var->transi != 0)
		var->color = 0x0010BAA4;
	else
		var->color = 0x00EF0000;
	if (x > x1 && y < y1)
		ft_bresenham_2(y, x1, y1, var);
	if (x > x1 && y > y1)
		ft_bresenham_3(y, x1, y1, var);
	if (x < x1 && y > y1)
		ft_bresenham_4(y, x1, y1, var);
	if (x < x1 && y < y1)
		ft_bresenham_1(y, x1, y1, var);
}

void	ft_bresenham_1(int y, int x1, int y1, t_fdf *var)
{
	int		dx;
	int		dy;
	int		e;
	int		x;

	x = var->ind;
	e = abs(x1 - x);
	dx = 2 * e;
	dy = 2 * abs(y1 - y);
	while (x != x1)
	{
		mlx_pixel_put(var->mlx, var->win, x++, y, var->color);
		e = e - dy;
		while (e < 0 && y < y1)
		{
			mlx_pixel_put(var->mlx, var->win, x, y++, var->color);
			e = e + dx;
		}
	}
}

void	ft_bresenham_2(int y, int x1, int y1, t_fdf *var)
{
	int		dx;
	int		dy;
	int		e;
	int		x;

	x = var->ind;
	e = abs(x1 - x);
	dx = 2 * e;
	dy = 2 * abs(y1 - y);
	while (x >= x1)
	{
		mlx_pixel_put(var->mlx, var->win, x--, y, var->color);
		e = e - dy;
		while (e < 0 && y < y1)
		{
			mlx_pixel_put(var->mlx, var->win, x, y++, var->color);
			e = e + dx;
		}
	}
}

void	ft_bresenham_3(int y, int x1, int y1, t_fdf *var)
{
	int		dx;
	int		dy;
	int		e;
	int		x;

	x = var->ind;
	e = abs(x1 - x);
	dx = 2 * e;
	dy = 2 * abs(y1 - y);
	while (x >= x1)
	{
		mlx_pixel_put(var->mlx, var->win, x--, y, var->color);
		e = e - dy;
		while (e < 0 && y > y1)
		{
			mlx_pixel_put(var->mlx, var->win, x, y--, var->color);
			e = e + dx;
		}
	}
}

void	ft_bresenham_4(int y, int x1, int y1, t_fdf *var)
{
	int		dx;
	int		dy;
	int		e;
	int		x;

	x = var->ind;
	e = abs(x1 - x);
	dx = 2 * e;
	dy = 2 * abs(y1 - y);
	while (x <= x1)
	{
		mlx_pixel_put(var->mlx, var->win, x++, y, var->color);
		e = e - dy;
		while (e < 0 && y > y1)
		{
			mlx_pixel_put(var->mlx, var->win, x, y--, var->color);
			e = e + dx;
		}
	}
}
