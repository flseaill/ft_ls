/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:38:15 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/28 20:22:00 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls/libft/libft.h"

/* stdlib pour exit(), et stdio pour puts() */
#include <stdlib.h>
#include <stdio.h>

/* Pour l'utilisation des dossiers */
#include <dirent.h>

struct	dirent* readdir(DIR* repertoire);

int		ft_listdir(char *path)
{
	DIR*	rep;
	struct dirent* readfile;

	rep = opendir(path); /* Ouverture d'un dossier */
	if (rep == NULL) /* Si le dossier n'a pas pu être ouvert */
		exit(1); /* (mauvais chemin par exemple) */
	while ((readfile = readdir(rep)) != NULL)
	{
		ft_putendl(readfile->d_name);
		readfile++;
	}
	if (closedir(rep) == -1) /* S'il y a eu un souci avec la fermeture */
		exit(-1);
	return (0);
}


int		main(int argc, char **argv)
{
	if (argc == 2)
		ft_listdir(argv[1]);
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("Folder name missing.\n");
	return (0);
}
