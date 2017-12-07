/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gschaetz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 18:29:22 by gschaetz          #+#    #+#             */
/*   Updated: 2016/11/22 15:52:17 by gschaetz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp1;
	t_list *tmp2;

	if (!lst)
		return (NULL);
	tmp = f(lst);
	if (!(tmp1 = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	tmp2 = tmp1;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(tmp2->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		lst = lst->next;
		tmp2 = tmp2->next;
	}
	return (tmp1);
}
