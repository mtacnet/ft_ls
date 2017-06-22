/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtacnet <mtacnet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 12:40:06 by mtacnet           #+#    #+#             */
/*   Updated: 2017/03/02 12:58:37 by mtacnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *buffer, int size)
{
	char	*swap;

	swap = ft_strnew(ft_strlen(buffer));
	ft_strcpy(swap, buffer);
	ft_strdel(&buffer);
	buffer = ft_strnew(ft_strlen(swap) + size);
	ft_strcpy(buffer, swap);
	ft_strdel(&swap);
	return (buffer);
}
