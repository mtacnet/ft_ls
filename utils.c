/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:14:28 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/19 14:37:34 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				getnbr(int nbr)
{
	int		count;

	count = 0;
	if (nbr < 1)
		nbr = 1;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void			display_total(t_elem *lst, t_flags *flags, t_env *env)
{
	t_elem		*tmp_lst;

	tmp_lst = lst;
	env->nb_blocks = 0;
	while (tmp_lst != NULL)
	{
		env->nb_blocks += tmp_lst->f_stat.st_blocks;
		tmp_lst = tmp_lst->next;
	}
	if (flags->l_flag)
	{
		ft_putstr("total ");
		ft_putnbr(env->nb_blocks);
		ft_putchar('\n');
	}
	freelst(tmp_lst);
}

static void		fnorme2(t_flags *flags, char *name_ln, char *buff, char *concat)
{
	struct stat		stat;

	if (flags->l_flag)
	{
		if (flags->ret != 1)
			ft_putstr(name_ln);
		ft_putstr(" -> ");
		ft_putstr(buff);
	}
	else
	{
		concat = ft_strjoin(concat, buff);
		lstat(concat, &stat);
		if (S_ISDIR(stat.st_mode) && flags->l_flag == 0)
			process_path(concat, flags);
	}
}

void			egalegal(t_elem **t1, t_elem **t2, t_elem **s1, t_elem **s2)
{
	*t1 = *t2;
	*s1 = *s2;
}

void			treat_symlnk(char *name_ln, t_flags *flags, t_env *env, int ret)
{
	char			*buff;
	char			*concat;
	char			*swap;
	size_t			size;

	concat = "/";
	swap = NULL;
	size = PATH_MAX;
	buff = ft_strnew(size);
	if (ret == 1)
	{
		if (env->path[ft_strlen(env->path) - 1] != '/')
		{
			swap = ft_strjoin(env->path, "/");
			swap = ft_strjoin(swap, name_ln);
		}
		else
			swap = ft_strjoin(env->path, name_ln);
		readlink(swap, buff, size - 1);
	}
	else
		readlink(name_ln, buff, size - 1);
	fnorme2(flags, name_ln, buff, concat);
	free(buff);
}
