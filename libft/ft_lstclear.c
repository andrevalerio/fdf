/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avalerio <avalerio@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 22:37:02 by avalerio          #+#    #+#             */
/*   Updated: 2021/04/19 22:43:21 by avalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual;
	t_list	*ptr;

	if (lst && *lst && del)
	{
		actual = *lst;
		while (actual)
		{
			ptr = actual->next;
			ft_lstdelone(actual, del);
			actual = ptr;
		}
		*lst = NULL;
	}
}
