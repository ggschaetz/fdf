/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:58:02 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/15 17:25:06 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tsrc;
	size_t		i;

	i = 0;
	tmp = (char *)dest;
	tsrc = (const char *)src;
	while (i != n)
	{
		tmp[i] = tsrc[i];
		i++;
	}
	return ((void *)tmp);
}
