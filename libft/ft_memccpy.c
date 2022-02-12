/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:44:49 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/13 23:29:11 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*temp_s;
	char	*temp_d;
	size_t	i;

	temp_s = (char *)src;
	temp_d = (char *)dest;
	if ((temp_s == NULL) && (temp_d == NULL))
		return (NULL);
	i = 0;
	while (i < n)
	{
		*(temp_d + i) = *(temp_s + i);
		if (*(temp_d + i) == (char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
