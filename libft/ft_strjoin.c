/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:17:19 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/18 22:03:36 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	s1_l;
	size_t	s2_l;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	new = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, s1_l + 1);
	ft_strlcat(new, s2, s1_l + s2_l + 1);
	return (new);
}
