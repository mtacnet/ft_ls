/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 11:03:46 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:53:25 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		init_struct_flags(t_flags *flags)
{
	flags->init_dir = NULL;
	flags->br_flag = 0;
	flags->a_flag = 0;
	flags->r_flag = 0;
	flags->t_flag = 0;
	flags->l_flag = 0;
	flags->view_path = 0;
	flags->ret = 0;
	flags->index = 0;
}

void			init_struct_env(t_env *env)
{
	env->path = NULL;
	env->nb_blocks = 0;
	env->nb_arg = 0;
	env->s_major = 0;
	env->s_minor = 0;
	env->s_rights = 10;
	env->s_links = 0;
	env->s_owner = 0;
	env->s_grp = 0;
	env->s_size = 0;
}

void			init_struct_norme(t_norme *norme)
{
	norme->major = 0;
	norme->minor = 0;
	norme->padding = 0;
	norme->ret = 0;
}

void			init_struct(t_flags *flags, t_env *env)
{
	init_struct_flags(flags);
	init_struct_env(env);
}
