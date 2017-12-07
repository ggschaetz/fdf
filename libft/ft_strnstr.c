/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:31:51 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/22 15:50:17 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (big[i] != '\0' && little[j] != '\0' && i < len)
	{
		if (big[i] == little[j] && i <= len && little[j] != '\0')
		{
			i++;
			j++;
		}
		else if (big[i] != little[j] || ft_strlen(little) != j)
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == ft_strlen(little))
		return ((char *)&big[i - j]);
	else
		return (0);
}
