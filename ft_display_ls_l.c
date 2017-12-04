/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:50:11 by flseaill          #+#    #+#             */
/*   Updated: 2017/12/04 21:08:45 by flseaill         ###   ########.fr       */
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
struct stat {
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


struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};
*/

void	ft_timeconvert(char *str);


int		main(int argc, char **argv)
{
	struct stat		fileinfo;
	struct passwd	*user;
	struct group	*usergroup;
	//struct tm		*time;
	char			*time;

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
	time = ctime(&fileinfo.st_mtime);
	if (user)
	{
		//		ft_putstr("Droits du fichier : ");
		ft_putnbr(fileinfo.st_mode);
		ft_putstr("         ");
		//		ft_putstr("Nombre de liens : ");
		ft_putnbr(fileinfo.st_nlink);
		ft_putstr(" ");
		//		ft_putstr("Proprietaire : ");
		ft_putstr(user->pw_name);
		ft_putstr("  ");
		//		ft_putstr("Groupe du proprietaire : ");
		ft_putstr(usergroup->gr_name);
		ft_putstr("   ");
		//		ft_putstr("Taille du fichier : ");
		ft_putnbr(fileinfo.st_size);
		ft_putstr(" ");
		ft_timeconvert(time);
		ft_putstr(" ");
		//		ft_putstr("Nom du fichier : ");
		ft_putstr(argv[1]);
		ft_putchar('\n');
		
		/*
		//		ft_putstr("Derniere modification du fichier : ");
		//ft_putstr(ctime(&fileinfo.st_mtime));
		
		ft_putnbr(time->tm_mon);
		ft_putchar(' ');
		ft_putnbr(time->tm_mday);
		ft_putchar(' ');
		ft_putnbr(time->tm_hour);
		ft_putchar(':');
		ft_putnbr(time->tm_min);
		ft_putchar(' ');
		*/

		/*
		   ft_putstr("Peripherique : ");
		   ft_putnbr(fileinfo.st_dev);
		   ft_putchar('\n');
		   ft_putstr("Type de peripherique : ");
		   ft_putnbr(fileinfo.st_rdev);
		   ft_putchar('\n');
		   ft_putstr("Numero d'inoeud : ");
		   ft_putnbr(fileinfo.st_ino);
		   ft_putchar('\n');
		   ft_putstr("UID : ");
		   ft_putnbr(fileinfo.st_uid);
		   ft_putchar('\n');
		   ft_putstr("GID : ");
		   ft_putnbr(fileinfo.st_gid);
		   ft_putchar('\n');
		   ft_putstr("Creation du fichier : ");
		   ft_putstr(ctime(&fileinfo.st_ctime));
		   */
	}
	return (1);
}
