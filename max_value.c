/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 15:15:59 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:11:39 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		max_value_links(t_elem *lst, t_env *env)
{
	if (getnbr(lst->f_stat.st_size) > env->s_size)
		env->s_links = getnbr(lst->f_stat.st_size);
}

static void		max_value_author(t_elem *lst, t_env *env)
{
	env->f_pwd = getpwuid(lst->f_stat.st_uid);
	if (env->s_owner < ft_strlenint(env->f_pwd->pw_name))
		env->s_owner = ft_strlen(env->f_pwd->pw_name);
}

static void		max_value_grp(t_elem *lst, t_env *env)
{
	env->f_grp = getgrgid(lst->f_stat.st_gid);
	if (env->s_grp < ft_strlenint(env->f_grp->gr_name))
		env->s_grp = ft_strlen(env->f_grp->gr_name);
}

void			max_value_size(t_elem *lst, t_env *env)
{
	if (getnbr(lst->f_stat.st_size) > env->s_size)
		env->s_size = getnbr(lst->f_stat.st_size);
}

void			max_value(t_elem *lst, t_env *env)
{
	max_value_links(lst, env);
	max_value_author(lst, env);
	max_value_grp(lst, env);
	max_value2(lst, env);
}
