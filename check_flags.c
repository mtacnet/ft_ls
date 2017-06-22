/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:05:35 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/17 17:07:45 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		parser_flags(t_flags *flags, char *argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		if (ft_strchr("Ralrt", (int)argv[i]) == NULL)
			ft_error(1, argv[i]);
		if (argv[i] == 'R')
			flags->br_flag = 1;
		if (argv[i] == 'a')
			flags->a_flag = 1;
		if (argv[i] == 'r')
			flags->r_flag = 1;
		if (argv[i] == 't')
			flags->t_flag = 1;
		if (argv[i] == 'l')
			flags->l_flag = 1;
		i++;
	}
}

void			check_flags(t_flags *flags, char **argv)
{
	int		i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		parser_flags(flags, argv[i]);
		i++;
	}
}
