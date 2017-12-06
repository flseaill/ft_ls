/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 16:43:26 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/18 19:59:34 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ret;

	i = 0;
	if (!str)
		return (NULL);
	k = ft_strlen(str);
	j = k - 1;
	ret = ft_strnew(k);
	while (i < k / 2)
		ret[i++] = str[j--];
	i = 0;
	j = k;
	while (j >= i)
	{
		if (j == k)
			ret[j--] = '\0';
		ret[j--] = str[i++];
	}
	return (ret);
}
