/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 16:07:07 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/10 12:54:15 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			verif;
}				t_point;

typedef struct	s_fdf
{
	void		*mlx;
	void		*win;
	int			x;
	int			i;
	int			ind;
	int			transi;
	int			color;
	int			j;
	int			y;
	int			fd;
	int			alt;
	int			zoom;
	int			tab[4];
	char		*file;
	int			pad_x;
	int			pad_y;
	int			decal;
	int			nb_row;
	int			nb_col;
	char		*line;
	t_point		**save;
	t_point		**stock;
}				t_fdf;

void			ft_choice(int y, int x1, int y1, t_fdf *var);
void			ft_bresenham_1(int y, int x1, int y1, t_fdf *var);
void			ft_bresenham_2(int y, int x1, int y1, t_fdf *var);
void			ft_bresenham_3(int y, int x1, int y1, t_fdf *var);
void			ft_bresenham_4(int y, int x1, int y1, t_fdf *var);
void			ft_declar_var(t_fdf *var);
int				ft_convert_z(char *c, t_fdf *var);
int				ft_convert_x(int i, int j, t_fdf *var);
void			ft_free_save(t_fdf *var);
int				ft_convert_y(int i, int j, t_fdf *var);
int				ft_check_map_fdf(t_fdf *var);
void			ft_center_map(t_fdf *var);
void			ft_stock_save(t_fdf *var);
int				ft_nb_row_fdf(t_fdf *var);
void			ft_pixel_put(t_fdf *var);
void			ft_fdf(t_fdf *var);

#endif
