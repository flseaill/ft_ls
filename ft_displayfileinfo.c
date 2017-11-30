/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displayfileinfo.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:25:39 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/30 17:50:03 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct Element Element;
struct Element
{
	char	*filename;
	int		filesize;
	char	*filerights;
	char	*m_date;
	char	*c_date;
	char	*filegroup;
	char	*fileowner;
	int		nb_links;
	Element	*suivant;
};

typedef struct	Liste Liste;
struct Liste
{
	Element *premier;
};

/*
void	ft_displayfileinfo(char *path, struct stat *buf)
{
	ft_putstr(">>>>>>>>>>>");
	ft_putstr(stat->st_dev);
	ft_putstr("<<<<<<<<<<<\n");
}

*/

void	*print_info(Liste *liste)
{
	if (liste == NULL)
		return (NULL);
	Element *actuel	 = liste->premier;

	while (actuel != NULL)
	{
		ft_putendl(actuel->filerights);
		ft_putnbr(actuel->nb_links);
		ft_putchar('\n');
		ft_putendl(actuel->fileowner);
		ft_putendl(actuel->filegroup);
		ft_putnbr(actuel->filesize);
		ft_putchar('\n');
		ft_putendl(actuel->m_date);
		ft_putendl(actuel->filename);
		ft_putendl(actuel->c_date);
		actuel = actuel->suivant;
	}
	//ft_putstr("NULL");
	return(NULL);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		print_info(stat(argv[1], stat));
}

/*
   Liste *newlst_file()
   {
   Liste *liste = malloc(sizeof(*liste));
   Element *element = malloc(sizeof(*element));

   if (liste == NULL || element == NULL)
   return (NULL);
   element->filename = "filename";
   element->filesize = "file size";
   element->filerights = "droits";
   element->m_date = "date de modif";
   element->c_date = "date de creat";
   element->filegroup = "user group";
   element->fileowner = "owner";
   element->nb_links = 2;
   element->suivant = NULL;
   liste->premier = element;

   return (liste);
   }*/
