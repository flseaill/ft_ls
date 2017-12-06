/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsrec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 20:28:06 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/28 18:44:36 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "libft/libft.h"
#include "ft_ls.h"

int		ft_list_dir_rec(char *path, int opt_a, int over)
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
	readfile = readdir(rep);
	if (readfile != NULL && over == 0)
		ft_list_dir_rec(path, opt_a, over);
	if (readfile->d_name[0] != '.' && opt_a == 0)
	{
		ft_putendl(readfile->d_name);
		readfile++;
	}
	else
		readfile++;
	if (closedir(rep) == -1)
		exit(-1);
	over = 1;
	return (0);
}

int		main(int argc, char **argv)
{
	int				opt_a;
	int				over;

	opt_a = 0;
	over = 0;
	if (argc >= 2)
		ft_list_dir_rec(argv[1], opt_a, over);
	else if (argc == 1)
		ft_list_dir_rec("./", opt_a, over);
	return (0);
}

*/
