/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:14:22 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/18 16:48:59 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;
	unsigned char	a;

	a = (unsigned char)c;
	tmp = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == a)
			return ((void *)&tmp[i]);
		else
			i++;
	}
	return (NULL);
}
