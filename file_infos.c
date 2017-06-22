/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 17:43:34 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:10:15 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		file_types(t_elem *lst)
{
	if (S_ISDIR(lst->f_stat.st_mode))
		ft_putstr("d");
	else if (S_ISFIFO(lst->f_stat.st_mode))
		ft_putstr("p");
	else if (S_ISREG(lst->f_stat.st_mode))
		ft_putstr("-");
	else if (S_ISLNK(lst->f_stat.st_mode))
		ft_putstr("l");
	else if (S_ISSOCK(lst->f_stat.st_mode))
		ft_putstr("s");
	else if (S_ISBLK(lst->f_stat.st_mode))
		ft_putstr("b");
	else if (S_ISCHR(lst->f_stat.st_mode))
		ft_putstr("c");
	else
		ft_putstr("-");
}

static void		owner_rights(t_elem *lst)
{
	if (lst->f_stat.st_mode & S_IRUSR)
		ft_putstr("r");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IWUSR)
		ft_putstr("w");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IXUSR)
	{
		if (lst->f_stat.st_mode & S_ISUID)
			ft_putstr("s");
		else
			ft_putstr("x");
	}
	else
	{
		if (lst->f_stat.st_mode & S_ISUID)
			ft_putstr("S");
		else
			ft_putstr("-");
	}
}

static void		group_rights(t_elem *lst)
{
	if (lst->f_stat.st_mode & S_IRGRP)
		ft_putstr("r");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IWGRP)
		ft_putstr("w");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IXGRP)
	{
		if (lst->f_stat.st_mode & S_ISGID)
			ft_putstr("s");
		else
			ft_putstr("x");
	}
	else
	{
		if (lst->f_stat.st_mode & S_ISGID)
			ft_putstr("S");
		else
			ft_putstr("-");
	}
}

static void		other_rights(t_elem *lst)
{
	if (lst->f_stat.st_mode & S_IROTH)
		ft_putstr("r");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IWOTH)
		ft_putstr("w");
	else
		ft_putstr("-");
	if (lst->f_stat.st_mode & S_IXOTH)
	{
		if (lst->f_stat.st_mode & S_ISVTX)
			ft_putstr("t");
		else
			ft_putstr("x");
	}
	else
	{
		if (lst->f_stat.st_mode & S_ISVTX)
			ft_putstr("T");
		else
			ft_putstr("-");
	}
}

void			file_infos(t_elem *lst, t_env *env)
{
	file_types(lst);
	owner_rights(lst);
	group_rights(lst);
	other_rights(lst);
	ft_putstr("  ");
	file_infos2(lst, env);
}
