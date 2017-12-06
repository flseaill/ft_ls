
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

void	ft_filemode(struct stat)
{
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
	if ((*fileinfo).st_mode & S_IRWXU )
		ft_putstr("rwx");
	else
	{
		if ((*fileinfo).st_mode & S_IRUSR )
			ft_putchar('r');
		else
			ft_putchar('-');
		if ((*fileinfo).st_mode & S_IWUSR )
			ft_putchar('w');
		else
			ft_putchar('-');
		if ((*fileinfo).st_mode & S_IXUSR )
			ft_putchar('x');
		else
			ft_putchar('-');
	}
	if (rights & S_IRWXG )
		ft_putstr("rwx");
	else
	{
		if (rights & S_IRGRP )
			ft_putchar('r');
		else
			ft_putchar('-');
		if (rights & S_IWGRP )
			ft_putchar('w');
		else
			ft_putchar('-');
		if (rights & S_IWGRP )
			ft_putchar('x');
		else
			ft_putchar('-');
	}
	if (rights & S_IRWXO )
		ft_putstr("rwx");
	else
	{
		if (rights & S_IROTH )
			ft_putchar('r');
		else
			ft_putchar('-');
		if (rights & S_IWOTH )
			ft_putchar('w');
		else
			ft_putchar('-');
		if (rights & S_IXOTH )
			ft_putchar('x');
		else
			ft_putchar('-');
	}
}


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
// ATTENTION, NE GERE PAS LES LIENS, A RAJOUTER :
// filename -> filelinked
// filesize of the link and not the linked file
void	ft_timeconvert(char *str);
//void	ft_filemode(int filemode);

int		main(int argc, char **argv)
{
	struct stat		fileinfo;
	struct passwd	*user;
	struct group	*usergroup;
	//struct tm		*time;
	char			*time;
	int i;

	i = 1;
	if (argc < 2)
	{
		ft_putendl(argv[1]);
		exit(EXIT_FAILURE);
	}
	while (argv[i])
	{
		if (stat(argv[i], &fileinfo) == -1)
		{
			perror(argv[i]);
			exit(-1);
		}
		user = getpwuid(fileinfo.st_uid);
		usergroup = getgrgid(user->pw_gid);
		time = ctime(&fileinfo.st_mtime);
		if (user)
		{
			//		ft_putstr("Droits du fichier : ");
ii			//ft_filemode(fileinfo.st_mode);
			ft_filemode(&fileinfo);
			ft_putchar(' ');
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
			ft_putstr(argv[i]);
			ft_putchar('\n');
		}
		i++;
	}
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
	return (1);
}
