/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrepel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:51:06 by mtacnet           #+#    #+#             */
/*   Updated: 2017/03/03 15:29:49 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrepel(t_list **alst, t_list *pnew)
{
	t_list		*list;

	if (!*alst)
		*alst = pnew;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = pnew;
	}
}
