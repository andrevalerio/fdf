/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 19:21:05 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/11 18:13:18 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;
	size_t			i;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	i = 0;
	while ((temp_s1[i] != '\0' || temp_s2[i] != '\0') && (n - 1) > i)
	{
		if (temp_s1[i] != temp_s2[i])
		{
			break ;
		}
		i++;
	}
	return (temp_s1[i] - temp_s2[i]);
}
