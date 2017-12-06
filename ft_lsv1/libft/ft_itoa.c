/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:19:07 by flseaill          #+#    #+#             */
/*   Updated: 2017/03/28 18:33:47 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*rst;
	int				len;
	unsigned int	nb;

	nb = n;
	len = ft_intlen(n);
	if (n < 0)
	{
		nb = -n;
		len++;
	}
	if (!(rst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rst[len--] = '\0';
	if (n == 0)
		rst[len] = '0';
	while (nb >= 1)
	{
		rst[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (n < 0)
		rst[len] = '-';
	return (rst);
}
