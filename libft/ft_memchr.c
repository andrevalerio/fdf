/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:18:15 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/17 19:18:18 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*temp_s;
	size_t			i;

	temp_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*(temp_s + i) == (unsigned char)c)
			return (temp_s + i);
		i++;
	}
	return (NULL);
}
