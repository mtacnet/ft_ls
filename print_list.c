/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:51:35 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 17:01:24 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem			*reverse_lst(t_elem **lst, t_flags *flags)
{
	t_elem		*prev;
	t_elem		*next;
	t_elem		*current;

	if (flags->r_flag)
	{
		current = *lst;
		prev = NULL;
		while (current != NULL)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		*lst = prev;
		return (*lst);
	}
	else
		return (*lst);
}

void			print_lst_name(t_elem *lst, t_flags *flags, t_env *env)
{
	if (is_empty(lst))
	{
		lst = new_list();
		return ;
	}
	display_total(lst, flags, env);
	while (lst != NULL)
	{
		if (flags->l_flag)
			file_infos(lst, env);
		if (S_ISLNK(lst->f_stat.st_mode))
		{
			ft_putstr(lst->name);
			if (flags->l_flag)
				treat_symlnk(lst->name, flags, env, flags->ret = 1);
			ft_putendl("");
		}
		else
			ft_putendl(lst->name);
		lst = lst->next;
	}
}

static void		fnorme(t_flags *flags, t_env *env, t_elem *newlst)
{
	if (flags->l_flag)
		file_infos(newlst, env);
	if (S_ISLNK(newlst->f_stat.st_mode))
	{
		ft_putstr(newlst->name);
		if (flags->l_flag)
			treat_symlnk(newlst->name, flags, env, flags->ret = 1);
		if (newlst->next != NULL)
			ft_putendl("");
	}
	else
		ft_putendl(newlst->name);
}

void			print_reverse_list_name(t_elem *lst, t_flags *flags, t_env *env)
{
	t_elem		*newlst;
	t_elem		*next;

	newlst = new_list();
	while (lst)
	{
		next = lst->next;
		lst->next = newlst;
		newlst = lst;
		lst = next;
	}
	display_total(newlst, flags, env);
	while (newlst)
	{
		fnorme(flags, env, newlst);
		newlst = newlst->next;
	}
}
