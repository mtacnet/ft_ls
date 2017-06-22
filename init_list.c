/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:58:17 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:10:26 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem		*new_list(void)
{
	return (NULL);
}

int			is_empty(void *lst)
{
	if (lst == NULL)
		return (1);
	return (0);
}

t_elem		*init_element(t_elem *element)
{
	element = (t_elem*)malloc(sizeof(t_elem));
	if (element == NULL)
	{
		ft_putendl("MEMORY ALLOCATION ERROR");
		exit(EXIT_FAILURE);
	}
	element->path = NULL;
	element->name = NULL;
	element->content = NULL;
	element->next = NULL;
	return (element);
}

void		freelst(t_elem *lst)
{
	t_elem		*tmp;

	while (lst != NULL)
	{
		tmp = lst;
		free(tmp->path);
		free(tmp->name);
		free(tmp);
		tmp = NULL;
		lst = lst->next;
	}
	lst = NULL;
}
