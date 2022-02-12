/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 20:36:43 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/19 22:34:10 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_s;
	unsigned char	*temp_d;

	temp_s = (unsigned char *)src;
	temp_d = (unsigned char *)dest;
	if ((temp_s == NULL) && (temp_d == NULL))
		return (NULL);
	if (temp_d < temp_s)
	{
		while (n--)
			*temp_d++ = *temp_s++;
	}
	else
	{
		temp_d = temp_d + n;
		temp_s = temp_s + n;
		while (n--)
			*--temp_d = *--temp_s;
	}
	return (dest);
}
