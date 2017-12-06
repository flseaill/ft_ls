/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:55:10 by flseaill          #+#    #+#             */
/*   Updated: 2017/01/30 08:14:56 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	int		*mem;

	i = 0;
	mem = (int *)malloc(sizeof(int) * size + 1);
	if (!mem)
		return (NULL);
	while (i != size)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
