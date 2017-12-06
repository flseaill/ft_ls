/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:30:08 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/28 18:36:30 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_list_dir_dot(char *path)
{
	DIR				*rep;
	struct dirent	*readfile;

	rep = opendir(path);
	if (rep == NULL)
	{
		ft_putstr("ft_ls: ");
		ft_putstr(path);
		ft_putendl(": No such file or directory");
		exit(1);
	}
	while ((readfile = readdir(rep)) != NULL)
	{
		ft_putendl(readfile->d_name);
		readfile++;
	}
	if (closedir(rep) == -1)
		exit(-1);
	return (0);
}
/*
int		main(int argc, char **argv)
{
	if (argc >= 2)
		ft_list_dir_dot(argv[1]);
	else if (argc == 1)
		ft_list_dir_dot("./");
	return (0);
}*/
