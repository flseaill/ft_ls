/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:29:08 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/28 18:36:02 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Ma libft */
#include "libft/libft.h"
/* stdlib pour exit(), et stdio pour puts() */
#include <stdlib.h>
/* Pour l'utilisation des dossiers */
#include <dirent.h>

/* Structure pour gerer les fichiers ? */
struct	dirent* readdir(DIR* repertoire);

int		ft_ls(char *path, int opt);
int		ft_ls_a(char *path);
int		ft_list_dir_dot(char *path);
int		ft_list_dir(char *path, int opt_a);
int		ft_list_dir_rec(char *path, int opt_a, int over);
int		ft_checker(char *str);
int		ft_parser(char **str);
