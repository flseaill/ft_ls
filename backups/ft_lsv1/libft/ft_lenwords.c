/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:03:34 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/19 17:44:06 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lenwords(const char *str, char c, int word)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (word != 0)
	{
		j = 0;
		if (str[i] == c)
		{
			while (str[i] == c)
				i++;
		}
		if (str[i] != c)
		{
			while (str[i] != c)
			{
				i++;
				j++;
			}
		}
		word--;
	}
	return (j);
}
