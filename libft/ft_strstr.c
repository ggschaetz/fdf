/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:57:39 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/22 12:45:35 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *gstr, const char *lstr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (gstr[i] != '\0' && lstr[j] != '\0')
	{
		if (gstr[i] == lstr[j] && lstr[j] != '\0')
		{
			j++;
			i++;
		}
		else if (gstr[i] != lstr[j])
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == ft_strlen(lstr))
		return ((char *)&gstr[i - j]);
	else
		return (0);
}
