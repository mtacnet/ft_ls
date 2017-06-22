/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_path2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/17 15:04:16 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 17:01:20 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	t_opt1(t_flags *flags, t_elem **lst_dname, char *dname,
		struct stat stat)
{
	if (flags->t_flag)
		*lst_dname = push_name_sortime(*lst_dname, dname, stat);
	else
		*lst_dname = push_infos_name(*lst_dname, dname, stat);
}

void	t_opt2(t_flags *flags, t_elem **lst_dir, char *dname, struct stat stat)
{
	if (flags->t_flag)
		*lst_dir = push_name_sortime(*lst_dir, dname, stat);
	else
		*lst_dir = push_infos_name(*lst_dir, dname, stat);
}

char	*concat_str(char *str, char *dname, t_env *env)
{
	str = ft_strjoin(env->path, "/");
	str = ft_strjoin(str, dname);
	return (str);
}

void	print(t_flags *flags, t_elem *lst_dname, t_elem *lst_dir, t_env *env)
{
	closedir(env->dir_path);
	process_size(lst_dname, env);
	if (flags->r_flag)
		print_reverse_list_name(lst_dname, flags, env);
	else
		print_lst_name(lst_dname, flags, env);
	if (flags->br_flag)
	{
		lst_dir = reverse_lst(&lst_dir, flags);
		while (lst_dir != NULL)
		{
			rec_dir(env->path, lst_dir->name, flags);
			lst_dir = lst_dir->next;
		}
	}
}

void	process_env(t_env *env, char *path)
{
	init_struct_env(env);
	env->path = NULL;
	env->path = ft_strnew(ft_strlen(path));
	env->path = ft_strcpy(env->path, path);
	env->dir_path = opendir(path);
}
