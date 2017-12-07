/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 10:47:04 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/15 17:25:37 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*tmp1;
	unsigned char	c1;

	i = 0;
	tmp = (unsigned char *)src;
	tmp1 = (unsigned char *)dest;
	c1 = (unsigned char)c;
	while (i < n)
	{
		tmp1[i] = tmp[i];
		if (tmp[i] == c1)
			return ((unsigned char *)&tmp1[i + 1]);
		i++;
	}
	return (NULL);
}
