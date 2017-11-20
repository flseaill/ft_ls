/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 04:58:28 by flseaill          #+#    #+#             */
/*   Updated: 2017/02/15 16:06:32 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinsep(const char *s1, const char *s2, char sep)
{
	char	*concat;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	concat = (char *)malloc(sizeof(char) * len + 2);
	if (!concat)
		return (NULL);
	while (s1 && s1[i])
	{
		concat[i] = s1[i];
		i++;
	}
	concat[i] = sep;
	i++;
	i = 0;
	while (s2 && s2[i])
	{
		concat[i + ft_strlen((char *)s1) + 1] = s2[i];
		i++;
	}
	concat[i + ft_strlen((char *)s1) + 1] = '\0';
	return (concat);
}
