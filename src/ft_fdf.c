/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:37:43 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/10 12:53:06 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		ft_refresh(t_fdf *var)
{
	mlx_clear_window(var->mlx, var->win);
	ft_stock_save(var);
	ft_pixel_put(var);
}

int			pt_function(int keycode, t_fdf *var)
{
	if (keycode == 1 && var->zoom != -1)
		var->zoom += 1;
	if (keycode == 12)
		var->alt++;
	if (keycode == 13)
		var->alt--;
	if (keycode == 0 && var->zoom != 1)
		var->zoom -= 1;
	if (keycode == 124)
		var->pad_x += 5;
	if (keycode == 123)
		var->pad_x -= 5;
	if (keycode == 125)
		var->pad_y += 5;
	if (keycode == 126)
		var->pad_y -= 5;
	ft_refresh(var);
	if (keycode == 53)
		exit(0);
	return (0);
}

void		ft_pixel_put(t_fdf *var)
{
	var->i = 0;
	while (var->i < var->nb_row)
	{
		var->j = 0;
		while (var->j < var->nb_col)
		{
			if (var->j < var->nb_col - 1)
			{
				var->transi = var->save[var->i][var->j].verif;
				var->ind = var->save[var->i][var->j].x;
				ft_choice(var->save[var->i][var->j].y, var->save[var->i]\
				[var->j + 1].x, var->save[var->i][var->j + 1].y, var);
			}
			if (var->i < var->nb_row - 1)
			{
				var->transi = var->save[var->i][var->j].verif;
				var->ind = var->save[var->i][var->j].x;
				ft_choice(var->save[var->i][var->j].y, var->save[var->i + 1]\
				[var->j].x, var->save[var->i + 1][var->j].y, var);
			}
			var->j++;
		}
		var->i++;
	}
}

void		ft_fdf(t_fdf *var)
{
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1000, 1000, "fdf");
	ft_pixel_put(var);
	mlx_key_hook(var->win, pt_function, var);
	mlx_loop(var->mlx);
}
