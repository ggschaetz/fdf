/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:47:23 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/18 17:02:54 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_start(char const *s)
{
	int i;

	i = 0;
	while ((s[i] == '\n' || s[i] == ' ' || s[i] == '\t') && s[i] != '\0')
		i++;
	return (i);
}

static int		ft_count_end(char const *s, int j)
{
	while ((s[j] == '\n' || s[j] == ' ' \
			|| s[j] == '\t' || s[j] == '\0') && j > 0)
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	char	*dest;
	int		i;
	int		j;
	int		x;
	int		k;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	j = ft_strlen(s);
	i = ft_count_start(s);
	j = ft_count_end(s, j);
	k = j - i;
	if (k < 0)
		k = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (k + 2))))
		return (NULL);
	while (s[i] && x <= k)
	{
		dest[x++] = s[i++];
	}
	dest[x] = '\0';
	return (dest);
}
