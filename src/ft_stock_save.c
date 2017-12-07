/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:24:23 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/17 13:19:57 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_is_nb(char c)
{
	if ((48 <= c && c <= 57) || c == 45 || c == '+')
		return (1);
	else
		return (0);
}

int			ft_check_map_fdf(t_fdf *var)
{
	char		*line;
	int			i;
	char		**tmp;

	line = NULL;
	tmp = NULL;
	var->fd = open(var->file, O_RDONLY);
	while (get_next_line(var->fd, &line) != 0 && (tmp = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (tmp[i] != '\0')
		{
			if (ft_is_nb(tmp[i][0]) != 1 && tmp[i][0] != '\0')
				return (0);
			i++;
		}
		if (i != var->nb_col)
			return (0);
	}
	close(var->fd);
	return (1);
}

void		ft_malloc_save(t_fdf *var)
{
	int			i;
	static int	y = 0;

	i = 0;
	if (y == 0)
	{
		if (!(var->save = (t_point **)malloc(sizeof(t_point *) * var->nb_row)))
			return ;
		while (i < var->nb_row)
		{
			if (!(var->save[i] = (t_point *)malloc(sizeof(t_point) *\
				var->nb_col)))
				return ;
			i++;
		}
		y++;
		if ((var->nb_row * var->nb_col) > 1000)
			var->zoom = 500;
		if ((var->nb_row * var->nb_col) > 50000)
			var->zoom = 1000;
	}
}

void		ft_convertion(t_fdf *var)
{
	int		i;
	int		j;
	char	*line;
	char	**tmp;

	j = 0;
	line = NULL;
	tmp = NULL;
	while (get_next_line(var->fd, &line) != 0 && (tmp = ft_strsplit(line, ' ')))
	{
		i = 0;
		while (tmp[i])
		{
			var->save[j][i].verif = (ft_atoi(tmp[i]) == 0) ? 0 : 1;
			var->save[j][i].z = ft_convert_z(tmp[i], var);
			var->save[j][i].x = ft_convert_x(i, j, var) / var->decal;
			var->save[j][i].y = ft_convert_y(i, j, var) / var->decal;
			i++;
		}
		j++;
	}
}

void		ft_stock_save(t_fdf *var)
{
	var->fd = open(var->file, O_RDONLY);
	ft_malloc_save(var);
	ft_convertion(var);
	close(var->fd);
}
