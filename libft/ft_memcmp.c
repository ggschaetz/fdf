/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:23:21 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/18 16:39:31 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*tp1;
	const char	*tp2;
	size_t		i;

	i = 0;
	tp1 = (const char *)s1;
	tp2 = (const char *)s2;
	while (i < n)
	{
		if (tp1[i] == tp2[i])
			i++;
		else
			return ((unsigned char)tp1[i] - (unsigned char)tp2[i]);
	}
	return (0);
}
