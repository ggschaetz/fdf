/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 09:43:33 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/18 16:50:47 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_count_iter(int n)
{
	int i;

	i = 1;
	while (n /= 10)
	{
		i++;
	}
	return (i);
}

char				*ft_itoa(int n)
{
	char			*dest;
	int				i;
	unsigned int	res;

	i = ft_count_iter(n);
	res = n;
	if (n < 0)
	{
		res = -n;
		i++;
	}
	if (!(dest = ft_strnew(i)))
		return (NULL);
	if (n == 0)
		dest[0] = 0 + 48;
	dest[--i] = res % 10 + 48;
	while (res /= 10)
		dest[--i] = res % 10 + 48;
	if (n < 0)
		dest[0] = '-';
	return (dest);
}
