/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:13:47 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/24 17:28:37 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;
	int		last_c;

	i = 0;
	j = ft_strlen(s) + 1;
	last_c = -1;
	while (i < (size_t)j)
	{
		if (s[i] == c)
			last_c = i;
		i++;
	}
	if (last_c == -1)
		return (NULL);
	return ((char *)&s[last_c]);
}
