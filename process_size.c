/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 12:48:42 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:14:13 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process_space(int space)
{
	int		i;

	i = 0;
	while (i < space)
	{
		ft_putstr(" ");
		i++;
	}
}

void	process_size(t_elem *lst, t_env *env)
{
	while (lst != NULL)
	{
		max_value(lst, env);
		lst = lst->next;
	}
}
