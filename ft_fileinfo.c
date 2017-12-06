/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:50:11 by flseaill          #+#    #+#             */
/*   Updated: 2017/12/04 19:54:46 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
/*
typedef struct stat {
	dev_t     st_dev;
	ino_t     st_ino;
	mode_t    st_mode;
	nlink_t   st_nlink;
	uid_t     st_uid;
	gid_t     st_gid;
	dev_t     st_rdev;
	off_t     st_size;
	blksize_t st_blksize;
	blkcnt_t  st_blocks;
	time_t    st_atime;
	time_t    st_mtime;
	time_t    st_ctime;
};
*/

int		main(int argc, char **argv)
{
	struct stat		fileinfo;
	struct passwd	*user;
	struct group	*usergroup;

	if (argc < 2)
	{
		ft_putendl(argv[1]);
		exit(EXIT_FAILURE);
	}
	if (stat(argv[1], &fileinfo) == -1)
	{
		perror("stat");
		exit(-1);
	}
	user = getpwuid(fileinfo.st_uid);
	usergroup = getgrgid(user->pw_gid);
	if (user)
	{
		ft_putstr("Peripherique : ");
		ft_putnbr(fileinfo.st_dev);
		ft_putchar('\n');
		ft_putstr("Type de peripherique : ");
		ft_putnbr(fileinfo.st_rdev);
		ft_putchar('\n');
		ft_putstr("Droits du fichier : ");
		ft_putnbr(fileinfo.st_mode);
		ft_putchar('\n');
		ft_putstr("Numero d'inoeud : ");
		ft_putnbr(fileinfo.st_ino);
		ft_putchar('\n');
		ft_putstr("Nombre de liens : ");
		ft_putnbr(fileinfo.st_nlink);
		ft_putchar('\n');
		ft_putstr("Proprietaire : ");
		ft_putstr(user->pw_name);
		ft_putchar('\n');
		ft_putstr("UID : ");
		ft_putnbr(fileinfo.st_uid);
		ft_putchar('\n');
		ft_putstr("Groupe du proprietaire : ");
		ft_putendl(usergroup->gr_name);
		ft_putstr("GID : ");
		ft_putnbr(fileinfo.st_gid);
		ft_putchar('\n');
		ft_putstr("Taille du fichier : ");
		ft_putnbr(fileinfo.st_size);
		ft_putchar('\n');
		ft_putstr("Derniere modification du fichier : ");
		ft_putstr(ctime(&fileinfo.st_mtime));
		ft_putstr("Creation du fichier : ");
		ft_putstr(ctime(&fileinfo.st_ctime));
	}
	return (1);
}
