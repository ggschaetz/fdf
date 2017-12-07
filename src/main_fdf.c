/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 13:16:44 by gschaetz          #+#    #+#             */
/*   Updated: 2017/02/17 13:17:47 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int		ft_check_file(char *var)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(var, O_RDONLY);
	if (get_next_line(fd, &line) == -1)
	{
		write(1, "not valide file\n", 16);
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int		main(int ac, char **av)
{
	t_fdf		*var;

	if (ac != 2)
	{
		write(1, "error: one file please\n", 23);
		return (0);
	}
	if (ft_check_file(av[1]) == 0)
		return (0);
	if (!(var = (t_fdf *)malloc(sizeof(t_fdf))))
		return (0);
	var->file = av[1];
	var->nb_row = ft_nb_row_fdf(var);
	if (ft_check_map_fdf(var) == 1)
	{
		ft_declar_var(var);
		ft_stock_save(var);
		ft_fdf(var);
	}
	else
		write(1, "error: invalide map\n", 20);
	return (0);
}
