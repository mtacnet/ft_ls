/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_value2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:16:09 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:12:01 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		max_value_majmin(t_elem *lst, t_env *env)
{
	int		major;
	int		minor;

	major = 0;
	minor = 0;
	if (S_ISBLK(lst->f_stat.st_mode) || S_ISCHR(lst->f_stat.st_mode))
	{
		major = major(lst->f_stat.st_rdev);
		minor = minor(lst->f_stat.st_rdev);
		if (getnbr(major) > env->s_major)
			env->s_major = getnbr(major);
		if (getnbr(minor) > env->s_minor)
			env->s_minor = getnbr(minor);
	}
	else
		max_value_size(lst, env);
}

void			max_value2(t_elem *lst, t_env *env)
{
	max_value_majmin(lst, env);
}
