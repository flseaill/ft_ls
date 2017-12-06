/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:55:02 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/21 22:39:43 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || (!(str = (char *)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	if (i == len)
		str[i] = '\0';
	return (str);
}
