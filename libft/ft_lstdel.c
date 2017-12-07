/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:26:23 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/21 18:05:33 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t n))
{
	t_list *tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		del((tmp)->content, (tmp)->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	*alst = NULL;
}
