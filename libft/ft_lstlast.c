/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:28:56 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 11:22:33 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*voyager;

	if (lst == NULL)
		return (0);
	voyager = lst;
	while ((*voyager).next != NULL)
		voyager = (*voyager).next;
	return (voyager);
}
