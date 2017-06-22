/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:17:53 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 17:08:22 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_rev_lstname(t_elem *lst, t_flags *flags, t_env *env)
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
	while (newlst)
	{
		if (flags->l_flag)
			file_infos(newlst, env);
		if (S_ISLNK(newlst->f_stat.st_mode))
			treat_symlnk(newlst->name, flags, env, 0);
		else
			ft_putendl(newlst->name);
		newlst = newlst->next;
	}
}

static void		print_list_name(t_elem *lst_file, t_flags *flags, t_env *env)
{
	if (flags->r_flag)
		print_rev_lstname(lst_file, flags, env);
	else
	{
		while (lst_file != NULL)
		{
			if (flags->l_flag)
				file_infos(lst_file, env);
			if (S_ISLNK(lst_file->f_stat.st_mode))
				treat_symlnk(lst_file->name, flags, env, flags->ret = 0);
			else
				ft_putendl(lst_file->name);
			lst_file = lst_file->next;
		}
	}
}

void			view_list(t_elem *lst_file, t_elem *elem, t_flags *flags)
{
	t_elem		*tmp_lst;
	t_env		*env;

	tmp_lst = reverse_lst(&elem, flags);
	env = NULL;
	env = (t_env*)malloc(sizeof(t_env));
	init_struct_env(env);
	if (lst_file != NULL)
	{
		print_list_name(lst_file, flags, env);
		if (tmp_lst)
			ft_putchar('\n');
	}
	while (tmp_lst != NULL)
	{
		process_path(tmp_lst->path, flags);
		if (tmp_lst->next != NULL)
			ft_putchar('\n');
		tmp_lst = tmp_lst->next;
	}
	free(env);
	freelst(lst_file);
	freelst(tmp_lst);
}
