/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 12:28:36 by avalerio          #+#    #+#             */
/*   Updated: 2021/02/18 19:56:03 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	size_t	end;
	char	*trim;

	if (s1 == 0 || set == 0)
		return (NULL);
	beg = 0;
	while (s1[beg] != 0 && ft_strchr(set, s1[beg]) != 0)
		beg++;
	end = ft_strlen(s1 + beg);
	if (end != 0)
		while (s1[end + beg - 1] != 0 && ft_strchr(set, s1[end + beg - 1]) != 0)
			end--;
	trim = malloc(sizeof(char) * (end + 1));
	if (trim == NULL)
		return (NULL);
	ft_strlcpy(trim, s1 + beg, end + 1);
	return (trim);
}
