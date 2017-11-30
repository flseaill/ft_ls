#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int n)
{
	unsigned int nb;

	nb = (unsigned int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		nb = n * -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		nb += '0';
		write(1, &nb, 1);
	}
}
*/
int		ft_isnl(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

int		ft_filelen(int fd)
{
	int		c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		i++;
		c++;
	}
	return (i);
}


int		ft_filenl(int fd)
{
	int		c;
	int		i;

	i = 0;
	while (read(fd, &c, 1) > 0)
	{
		if (ft_isnl(c))
			i++;
		c++;
	}
	return (i);
}


int		ft_filesize(char *filename)
{
	int fd;
	int size;

	fd = open(filename, O_RDONLY);
	size = ft_filelen(fd);// * 4;
	close(fd);
	return (size);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_filesize(argv[1]);
	}
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc < 2)
		ft_putstr("File name missing.\n");
	return (0);
}
