/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 17:49:49 by mtacnet           #+#    #+#             */
/*   Updated: 2017/03/30 17:50:31 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char const *s1, char const *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;
	int				i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (1);
	c1 = (unsigned char*)s1;
	c2 = (unsigned char*)s2;
	i = 0;
	while (c1[i] == c2[i])
	{
		if (!c1[i] && !c2[i])
			return (0);
		i++;
	}
	return (c1[i] - c2[i]);
}
