/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 22:01:00 by flseaill          #+#    #+#             */
/*   Updated: 2017/04/22 01:54:59 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splitchecker(const char *s, char sep)
{
	int		checksep;

	checksep = 0;
	while (*s)
	{
		if (*s == sep)
			checksep++;
		s++;
	}
	if (checksep == 0)
		return (0);
	return (1);
}

static int	ft_lenfword(const char *s, char sep)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!ft_splitchecker(s, sep))
		return (ft_strlen((char *)s));
	if (s[i] == sep)
	{
		while (s[i] && s[i] == sep)
			i++;
	}
	if (s[i] != sep)
	{
		while (s[i] && s[i] != sep)
		{
			i++;
			j++;
		}
	}
	return (j);
}

static char	**ft_filltab(char **tab, const char *s, char c)
{
	int		i;
	int		words;
	int		wordlen;

	i = 0;
	words = ft_countwords(s, c);
	while (i < words)
	{
		if (ft_lenfword(s, c) == 0)
			wordlen = ft_strlen(s);
		else
			wordlen = ft_lenfword(s, c);
		if (!(tab[i] = malloc(sizeof(char) * wordlen + 1)))
			return (NULL);
		while (*s == c)
			s++;
		tab[i] = ft_strjoin(ft_strsub(s, 0, wordlen), "\0");
		if (!(s + wordlen))
			break ;
		s += wordlen + 1;
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		lentab;
	int		words;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	lentab = ft_strlen((char *)s) - words + 1;
	if (!(tab = (char **)malloc(sizeof(char *) * words)))
		return (0);
	tab = ft_filltab(tab, s, c);
	return (tab);
}
