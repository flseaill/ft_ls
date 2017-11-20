/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:12:41 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/12 17:27:04 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	int		j;

	i = 0;
	j = ft_strlen(s) + 1;
	while (j > 0)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
		j--;
	}
	return (NULL);
}
