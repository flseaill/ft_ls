/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filemode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:23:55 by flseaill          #+#    #+#             */
/*   Updated: 2017/12/06 21:32:38 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void	ft_filemode(char *filename)
{
	struct stat	fileinfo;
	int			rights;

	if (stat(filename, &fileinfo) == -1)
		exit(-1);
	rights = fileinfo.st_mode;
	if (S_ISLNK(rights))
		ft_putchar('@');
	else if (S_ISBLK(rights))
		ft_putchar('b');
	else if (S_ISCHR(rights))
		ft_putchar('c');
	else if (S_ISDIR(rights))
		ft_putchar('d');
	else if (S_ISFIFO(rights))
		ft_putchar('f');
	else if (S_ISSOCK(rights))
		ft_putchar('s');
	else if (S_ISREG(rights))
		ft_putchar('-');
	if (fileinfo.st_mode & S_IRWXU)
		ft_putstr("rwx");
	else
	{
		if (fileinfo.st_mode & S_IRUSR)
			ft_putchar('r');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IWUSR)
			ft_putchar('w');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IXUSR)
			ft_putchar('x');
		else
			ft_putchar('-');
	}
	if (fileinfo.st_mode & S_IRWXG)
		ft_putstr("rwx");
	else
	{
		if (fileinfo.st_mode & S_IRGRP)
			ft_putchar('r');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IWGRP)
			ft_putchar('w');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IWGRP)
			ft_putchar('x');
		else
			ft_putchar('-');
	}
	if (fileinfo.st_mode & S_IRWXO)
		ft_putstr("rwx");
	else
	{
		if (fileinfo.st_mode & S_IROTH)
			ft_putchar('r');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IWOTH)
			ft_putchar('w');
		else
			ft_putchar('-');
		if (fileinfo.st_mode & S_IXOTH)
			ft_putchar('x');
		else
			ft_putchar('-');
	}
}
