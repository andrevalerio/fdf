/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 23:40:39 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/19 22:30:47 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	unsigned int	length;
	unsigned int	temp_n;

	if (n == 0)
		return (1);
	length = 0;
	if (n < 0)
	{
		length++;
		n = -n;
	}
	temp_n = n;
	while (temp_n != 0)
	{
		length++;
		temp_n = temp_n / 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	unsigned int	n_len;
	unsigned int	n_temp;
	unsigned int	is_negative;
	char			*str;

	n_len = ft_intlen(n);
	str = malloc(sizeof(char) * (n_len + 1));
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	is_negative = 0;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		is_negative = 1;
	}
	n_temp = n;
	while (n_len > is_negative)
	{
		str[n_len - 1] = (n_temp % 10) + '0';
		n_temp = n_temp / 10;
		n_len--;
	}
	return (str);
}
