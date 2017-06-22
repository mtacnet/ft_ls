/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:42:53 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 16:13:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		view_path(char *path, t_flags *flags, int i)
{
	if (flags->view_path != 0 || flags->br_flag != 0)
	{
		if (flags->br_flag && i != 0)
		{
			ft_putstr(path);
			ft_putendl(":");
		}
		else if (flags->view_path && ft_strcmp(path, "/tmp/") != 0)
		{
			ft_putstr(path);
			ft_putendl(":");
		}
	}
}

static void		process_dir(t_env *env, t_elem *lst_dname, t_elem *lst_dir,
		t_flags *flags)
{
	struct dirent		*read;
	struct stat			stat;
	char				*str;

	str = NULL;
	while ((read = readdir(env->dir_path)) != NULL)
	{
		stat.st_mode = 0;
		str = concat_str(str, read->d_name, env);
		lstat(str, &stat);
		if (flags->a_flag)
		{
			t_opt1(flags, &lst_dname, read->d_name, stat);
			if (S_ISDIR(stat.st_mode))
				t_opt2(flags, &lst_dir, read->d_name, stat);
		}
		else
		{
			if (read->d_name[0] != '.')
				t_opt1(flags, &lst_dname, read->d_name, stat);
			if (read->d_name[0] != '.' && S_ISDIR(stat.st_mode))
				t_opt2(flags, &lst_dir, read->d_name, stat);
		}
	}
	print(flags, lst_dname, lst_dir, env);
}

void			process_path(char *path, t_flags *flags)
{
	t_env			*env;
	t_elem			*lst_dname;
	t_elem			*lst_dir;
	static int		i = 0;
	struct stat		stat;

	errno = 0;
	lst_dname = new_list();
	lst_dir = new_list();
	env = NULL;
	env = (t_env*)malloc(sizeof(t_env));
	process_env(env, path);
	view_path(path, flags, i);
	i++;
	lstat(path, &stat);
	if (errno != 0)
	{
		view_path_error(path);
		perror("");
	}
	else
		process_dir(env, lst_dname, lst_dir, flags);
	freelst(lst_dname);
	freelst(lst_dir);
	free(env->path);
}

void			rec_dir(char *init_path, char *path, t_flags *flags)
{
	char	*concat;

	concat = "/";
	if (ft_strcmp(path, ".") != 0 && ft_strcmp(path, "..") != 0)
	{
		init_path = ft_strjoin(init_path, concat);
		init_path = ft_strjoin(init_path, path);
		ft_putchar('\n');
		process_path(init_path, flags);
	}
}
