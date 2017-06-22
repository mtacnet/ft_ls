/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:16:47 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 16:30:41 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_elem	*process_file(t_elem *lst_file, char *argv, struct stat stat,
		t_flags *flags)
{
	errno = 0;
	lstat(argv, &stat);
	if (errno != 0)
	{
		view_path_error(argv);
		perror("");
	}
	else
	{
		if (flags->t_flag)
			lst_file = push_name_sortime(lst_file, argv, stat);
		else
			lst_file = push_infos_name(lst_file, argv, stat);
	}
	return (lst_file);
}

static void		no_arg(char **argv, int i, int j, t_flags *flags)
{
	char	*init_path;

	init_path = ".";
	if (!(argv[i] && argv[i][0]))
	{
		if (j == 0)
			process_path(init_path, flags);
	}
}

static t_elem	*process_lst(char *argv, t_flags *flags, t_elem **elem, t_elem
		*lst_file)
{
	struct stat		stat;

	stat.st_mode = 0;
	lstat(argv, &stat);
	if (S_ISDIR(stat.st_mode))
	{
		if (flags->t_flag)
			*elem = push_path_sortime(*elem, argv, stat);
		else
			*elem = push_infos_path(*elem, argv, stat);
		flags->view_path += flags->index;
	}
	else
		lst_file = process_file(lst_file, argv, stat, flags);
	return (lst_file);
}

void			prep_dir(char **argv, t_env *env, t_elem *elem, t_flags *flags)
{
	int				i;
	t_elem			*lst_file;

	i = 1;
	flags->index = 0;
	lst_file = new_list();
	while (i < env->nb_arg && argv[i] && argv[i][0])
	{
		while (i < env->nb_arg && argv[i] && argv[i][0] == '-')
		{
			flags->index == 0 ? 0 : ft_error(2, argv[i][1]);
			i++;
		}
		no_arg(argv, i, flags->index, flags);
		if (argv[i] && argv[i][0])
			lst_file = process_lst(argv[i], flags, &elem, lst_file);
		i++;
		flags->index++;
	}
	env ? free(env) : 0;
	view_list(lst_file, elem, flags);
}
