/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_infos2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 16:05:45 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 15:22:28 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		author_group(t_env *env, t_elem *lst)
{
	int		padding;
	int		ret;

	padding = 0;
	ret = 0;
	env->f_pwd = getpwuid(lst->f_stat.st_uid);
	padding = ft_strlenint(env->f_pwd->pw_name);
	ret = env->s_owner - padding;
	ft_putstr(env->f_pwd->pw_name);
	process_space(ret);
	ft_putstr("  ");
	env->f_grp = getgrgid(lst->f_stat.st_gid);
	padding = ft_strlenint(env->f_grp->gr_name);
	ret = env->s_grp - padding + 1;
	ft_putstr(env->f_grp->gr_name);
	process_space(ret);
	ft_putstr(" ");
}

static void		nb_links(t_elem *lst, t_env *env)
{
	int		padding;
	int		ret;

	padding = getnbr(lst->f_stat.st_nlink);
	ret = 0;
	ret = env->s_links - padding - 1;
	process_space(ret);
	ft_putnbr(lst->f_stat.st_nlink);
	ft_putstr(" ");
}

static void		file_size(t_elem *lst, t_env *env)
{
	t_norme		norme;

	init_struct_norme(&norme);
	if (S_ISBLK(lst->f_stat.st_mode) || S_ISCHR(lst->f_stat.st_mode))
	{
		norme.major = major(lst->f_stat.st_rdev);
		norme.padding = getnbr(norme.major);
		norme.ret = env->s_major - norme.padding;
		process_space(norme.ret);
		ft_putnbr(norme.major);
		ft_putstr(", ");
		norme.minor = minor(lst->f_stat.st_rdev);
		norme.padding = getnbr(norme.minor);
		norme.ret = env->s_minor - norme.padding;
		process_space(norme.ret);
		ft_putnbr(norme.minor);
		ft_putstr(" ");
	}
	else
	{
		norme.padding = getnbr(lst->f_stat.st_size);
		norme.ret = env->s_size - norme.padding;
		process_space(norme.ret);
		ft_putnbr(lst->f_stat.st_size);
	}
}

static void		last_modif(t_elem *lst)
{
	time_t		current_date;
	time_t		timebuf;
	time_t		final_date;
	char		*timestr;
	char		*strtmp;

	current_date = time(NULL);
	timebuf = lst->f_stat.st_mtime;
	timestr = ctime(&timebuf);
	final_date = current_date - timebuf;
	if (final_date > 15778800 || final_date < 0)
	{
		strtmp = ft_strsub(timestr, 4, 7);
		ft_putstr(strtmp);
		strtmp = ctime(&(lst->f_stat.st_mtimespec.tv_sec));
		strtmp = ft_strdup(strtmp);
		strtmp = ft_strsub(strtmp, 19, 5);
		ft_putstr(strtmp);
	}
	else
	{
		strtmp = ft_strsub(timestr, 4, 12);
		ft_putstr(strtmp);
	}
	ft_putstr(" ");
}

void			file_infos2(t_elem *lst, t_env *env)
{
	nb_links(lst, env);
	author_group(env, lst);
	file_size(lst, env);
	ft_putstr(" ");
	last_modif(lst);
}
