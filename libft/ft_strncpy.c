/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 02:15:52 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/12 18:14:17 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (src[i] && len)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len)
	{
		dst[i] = '\0';
		i++;
		len--;
	}
	return (dst);
}
