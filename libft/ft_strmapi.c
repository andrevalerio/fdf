/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:36:32 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/18 17:07:07 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	if (s)
	{
		new = ft_strdup((const char *)s);
		if (new == NULL)
			return (NULL);
		i = 0;
		while (new[i] != 0)
		{
			new[i] = f(i, new[i]);
			i++;
		}
		return (new);
	}
	else
		return (NULL);
}
