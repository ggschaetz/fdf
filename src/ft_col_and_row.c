/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_col_and_row.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:22:23 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/08 12:00:10 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_nb_row_fdf(t_fdf *var)
{
	int		i;
	int		j;
	int		y;
	char	*line;
	char	**tmp;

	i = 0;
	j = 0;
	y = 0;
	line = NULL;
	tmp = NULL;
	var->fd = open(var->file, O_RDONLY);
	while (get_next_line(var->fd, &line) != 0)
	{
		i++;
		tmp = ft_strsplit(line, ' ');
	}
	while (tmp[y++] != '\0')
		j++;
	var->nb_col = j;
	close(var->fd);
	return (i);
}
