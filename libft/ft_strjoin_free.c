/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 21:04:30 by avalerio          #+#    #+#             */
/*   Updated: 2021/06/02 21:54:29 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strjoin_free(char *s1_stc, char *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	char	*s3;

	if (!s1_stc && !s2)
		return (0);
	s1_l = ft_strlen(s1_stc);
	s2_l = ft_strlen(s2);
	s3 = malloc(sizeof(char) * (s1_l + s2_l + 1));
	if (s3 == NULL)
		return (NULL);
	ft_memmove(s3, s1_stc, s1_l);
	ft_memmove(s3 + s1_l, s2, s2_l);
	s3[s1_l + s2_l] = '\0';
	free(s1_stc);
	return (s3);
}
