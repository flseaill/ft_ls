/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:30:08 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/24 20:49:00 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_list_dir(char *path, int opt_a)
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
		if (readfile->d_name[0] != '.' && opt_a == 0)
		{
			ft_putendl(readfile->d_name);
			readfile++;
		}
		else
			readfile++;
	}
	if (closedir(rep) == -1)
		exit(-1);
	return (0);
}

int		main(int argc, char **argv)
{
	int				opt_a;

	opt_a = 0;
	if (argc >= 2)
		ft_list_dir(argv[1], opt_a);
	else if (argc == 1)
		ft_list_dir("./", opt_a);
	return (0);
}
