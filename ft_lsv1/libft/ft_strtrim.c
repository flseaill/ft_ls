/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 16:38:29 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/19 20:33:21 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_trimlen(char const *s)
{
	int		spaces;
	int		i;

	spaces = 0;
	while (s[spaces] == ' ' || s[spaces] == '\t' || s[spaces] == '\n')
		++spaces;
	if (!s[spaces])
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		--i;
		++spaces;
	}
	return (ft_strlen(s) - spaces);
}

char		*ft_strtrim(const char *s)
{
	char	*dst;
	int		i;
	int		j;
	int		len;

	if (s == NULL)
		return ("");
	len = ft_trimlen(s) + 1;
	if (!s || (!(dst = (char*)malloc(sizeof(char) * len))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		dst[j] = s[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	j--;
	while (dst[j] == ' ' || dst[j] == '\n' || dst[j] == '\t')
		dst[j--] = '\0';
	return (dst);
}
