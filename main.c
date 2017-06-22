/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 11:53:33 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:10:54 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				main(int argc, char **argv)
{
	t_env		*env;
	t_flags		flags;
	t_elem		*elem;

	env = NULL;
	elem = NULL;
	env = (t_env*)malloc(sizeof(t_env));
	init_struct(&flags, env);
	elem = new_list();
	env->nb_arg = argc;
	if (argc < 2)
		process_path(".", &flags);
	free(env);
	env = NULL;
	env = (t_env*)malloc(sizeof(t_env));
	if (argc >= 2)
	{
		check_flags(&flags, argv);
		prep_dir(argv, env, elem, &flags);
	}
	return (0);
}
