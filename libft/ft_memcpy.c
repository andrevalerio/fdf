/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 00:48:50 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/11 08:42:26 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dest);
}
