/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:50:41 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/19 22:44:02 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_l;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (*(dst + i) != '\0' && i < size)
		i++;
	dst_l = i;
	while (i < (size - 1) && *(src + j) != '\0')
	{
		*(dst + i) = *(src + j);
		i++;
		j++;
	}
	if (dst_l < size)
		*(dst + i) = '\0';
	return (ft_strlen(src) + dst_l);
}
