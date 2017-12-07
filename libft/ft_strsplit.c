/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 16:40:30 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/22 15:50:53 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_nb_char(const char *s, char c, int i)
{
	int j;

	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

static int		ft_count_nb_word(const char *s, char c)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nb);
}

static char		**ft_cpy_word(const char *s, char **dest, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (j < ft_count_nb_word(s, c))
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			dest[j][k] = s[i];
			k++;
			i++;
		}
		dest[j][k] = '\0';
		j++;
		k = 0;
	}
	return (dest);
}

static int		ft_position(char const *s, char c, int i)
{
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**dest;
	int		k;

	i = 0;
	k = 0;
	if (!s)
		return (NULL);
	if (!(dest = (char **)malloc(sizeof(char *) * \
		(ft_count_nb_word(s, c) + 1))))
		return (NULL);
	while (i < ft_count_nb_word(s, c))
	{
		if (!(dest[i] = (char *)malloc(sizeof(char) * \
			ft_count_nb_char(s, c, k) + 1)))
			return (NULL);
		k = ft_position(s, c, k);
		i++;
	}
	dest = ft_cpy_word(s, dest, c);
	dest[i] = NULL;
	return (dest);
}
