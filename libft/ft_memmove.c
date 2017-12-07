/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 11:59:12 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/15 17:27:52 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tdest;
	const char	*tsrc;
	size_t		i;

	i = 0;
	tdest = dest;
	tsrc = src;
	if (tsrc > tdest)
		ft_memcpy(dest, src, n);
	if (tsrc <= tdest)
		ft_memcpy_rev(dest, src, n);
	return ((void *)dest);
}
