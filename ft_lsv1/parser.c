/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flseaill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 17:41:44 by flseaill          #+#    #+#             */
/*   Updated: 2017/11/28 18:38:04 by flseaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(const char *str);
void	ft_putendl(const char *str);
int		ft_ls(char *str, int opt);

int			ft_checker(char *str)
{
	int		i;

	i = 0;
	if (str[i] == '-')
	{
		while (str[i])
		{
			if (str[i] == 'R' || str[i] == 'a' || str[i] == 'l'
			|| str[i] == 'r' || str[i] == 't')
			{
				if (str[i] == 'R')
					ft_putendl("OPTION R");
				if (str[i] == 'a')
					ft_putendl("OPTION a");
				if (str[i] == 'l')
					ft_putendl("OPTION l");
				if (str[i] == 'r')
					ft_putendl("OPTION r");
				if (str[i] == 't')
					ft_putendl("OPTION t");
				i++;
			}
			else
				return (-1);
		}
		return (1);
	}
	else
		return (0);
}

int			main(int argc, char **argv)
{
	int		opt_a;
	int		i;

	opt_a = 0;
	i = 3;
	if (argc == 1)
		ft_ls("./", opt_a);
	if (argc == 2)
		ft_ls(argv[2], opt_a);
	if (argc > 2)
	{
		if (ft_checker(argv[3]) == -1)
		{
			ft_putstr("ls: illegal option -- ");
			ft_putendl(&argv[3][1]);
			ft_putendl("usage: ls [-Ralrt] [file ...]");
		}
		else if (ft_checker(argv[3]) == 0)
		{
			while (argv[i])
			{
				ft_ls(argv[i], opt_a);
				i++;
			}
		}
	}
	return (0);
}
