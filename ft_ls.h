/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:29:08 by flseaill          #+#    #+#             */
/*   Updated: 2017/12/06 19:25:18 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ma libft */
#include "libft/libft.h"
/* stdlib pour exit(), et stdio pour puts() */
#include <stdlib.h>
//#include <stdio.h>
/* Pour l'utilisation des dossiers */
#include <dirent.h>
/* Pour stat, lstat, fstat et cie */
#include <sys/stat.h>
#include <sys/types.h>
//#include <pwd.h>
#include <grp.h>
/* Pour recuperer les dates */
#include <time.h>

/* Structure pour gerer les fichiers ? */
struct	dirent* readdir(DIR* repertoire);

int		ft_ls(char *path, int opt);
int		ft_ls_a(char *path);
int		ft_list_dir_dot(char *path);
int		ft_list_dir(char *path, int opt_a);
int		ft_list_dir_rec(char *path, int opt_a, int over);
int		ft_checker(char *str);
int		ft_parser(char **str);
