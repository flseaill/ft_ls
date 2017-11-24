/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 16:29:08 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/24 16:34:07 by flseaill         ###   ########.fr       */
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


int		ft_list_dir(char *path);

