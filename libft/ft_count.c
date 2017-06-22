/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 16:50:28 by mtacnet           #+#    #+#             */
/*   Updated: 2017/04/20 15:59:09 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_count_arg(int argc, char **argv)
{
	int		i;
	int		count;
	int		tmp;

	tmp = 0;
	count = 0;
	i = 0;
	while (i < argc)
	{
		while (ft_strchr(argv[i], '-') != NULL)
			count++;
		i++;
	}
	tmp = i - count;
	ft_putnbr(tmp);
	return (tmp);
}

int		main(int argc, char **argv)
{
	ft_count_arg(argc, argv);
	return (0);
}
