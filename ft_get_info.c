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
	Element *suivant;
};

typedef struct	Liste Liste;
struct Liste
{
	Element *premier;
};

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
}


void	*changefilename(Liste *liste, char *modif)
{
	Element *nouveau = malloc(sizeof(*nouveau));
	if (liste == NULL || nouveau == NULL)
		return (NULL);
	nouveau->filename = modif;

	nouveau->suivant = liste->premier;
	liste->premier = nouveau;
	return (NULL);
}


void	*del_lst(Liste *liste)
{
	if (liste == NULL)
		return (NULL);
	if (liste->premier != NULL)
	{
		Element *aSupprimer = liste->premier;
		liste->premier = liste->premier->suivant;
		free(aSupprimer);
	}
	return(NULL);
}

void	*print_info(Liste *liste)
{
	if (liste == NULL)
		return (NULL);
	Element *actuel = liste->premier;

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
	puts("NULL");
	return(NULL);
}

int		main(void)
{
	Liste *fichier = newlst_file();
	//changefilename(fichier, "nomfichiertest");
	print_info(fichier);
	del_lst(fichier);
	return (0);
}
