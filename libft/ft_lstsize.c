/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pforesti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:28:30 by pforesti          #+#    #+#             */
/*   Updated: 2021/10/26 10:31:10 by pforesti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*voyager;

	i = 0;
	voyager = lst;
	while (voyager != NULL)
	{
		voyager = (*voyager).next;
		i++;
	}
	return (i);
}
