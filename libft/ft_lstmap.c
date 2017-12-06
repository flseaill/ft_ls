/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 18:34:41 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/28 18:34:42 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *result_last;

	if (lst && f)
	{
		result_last = f(lst);
		result = result_last;
		if (result == NULL)
			return (NULL);
		while (lst->next)
		{
			lst = lst->next;
			result_last->next = f(lst);
			if (result_last->next == NULL)
				return (NULL);
			result_last = result_last->next;
		}
		return (result);
	}
	return (NULL);
}
