/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_timeconvert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:48:29 by flseaill          #+#    #+#             */
/*   Updated: 2017/12/04 21:01:02 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	ft_timeconvert(char *str)
{
	int		i;
	
	i = 4;
	while (i < 16)
	{
		ft_putchar(str[i]);
		i++;
	}
}
