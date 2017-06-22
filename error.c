/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 13:09:24 by mtacnet           #+#    #+#             */
/*   Updated: 2017/06/05 13:35:36 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			view_path_error(char *path)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	ft_putstr_fd("ft_ls: ", 2);
	while (path[i])
	{
		if (path[i] == '/')
		{
			k = i + 1;
			j++;
		}
		i++;
	}
	while (path[k])
	{
		ft_putchar(path[k]);
		k++;
	}
	ft_putstr_fd(": ", 2);
}

static void		error_bad_argv(char bad_argv)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(bad_argv, 2);
	ft_putstr_fd("\nusage: ./ft_ls [-Ralrt] [file ...]", 2);
	ft_putstr_fd("\n", 2);
	exit(EXIT_FAILURE);
}

static int		error_bad_argv2(char bad_argv)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd("-", 2);
	ft_putchar_fd(bad_argv, 2);
	ft_putstr_fd(": No such file or directory", 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

void			ft_error(int ret, char bad_argv)
{
	if (ret == 1)
		error_bad_argv(bad_argv);
	if (ret == 2)
		error_bad_argv2(bad_argv);
}
