/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 13:15:38 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/15 17:27:19 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy_rev(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp1;

	tmp = (char *)dest;
	tmp1 = (const void *)src;
	while (n--)
	{
		tmp[n] = tmp1[n];
	}
	return ((void *)tmp);
}
