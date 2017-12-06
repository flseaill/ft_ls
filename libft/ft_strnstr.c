/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 16:09:28 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/12 20:09:16 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = (char *)s1;
	if (!s2[0])
		return (tmp);
	while (tmp[i])
	{
		if (tmp[i] == s2[j] && i < n)
		{
			while (s2[j] && tmp[i + j] == s2[j] && (i + j) < (n))
			{
				if (tmp[i + j] == s2[j] && j + 1 == ft_strlen(s2))
					return (char *)(&s1[i]);
				j++;
			}
			j = 0;
		}
		i++;
	}
	return (NULL);
}
