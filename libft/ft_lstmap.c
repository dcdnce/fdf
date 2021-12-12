/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:47:45 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 14:36:05 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*v;
	t_list	*n;
	t_list	*b;

	v = lst;
	b = NULL;
	while (v)
	{
		n = ft_lstnew((*f)(v->content));
		if (!n)
		{
			ft_lstclear(&n, del);
			return (b);
		}
		ft_lstadd_back(&b, n);
		v = v->next;
	}
	return (b);
}
