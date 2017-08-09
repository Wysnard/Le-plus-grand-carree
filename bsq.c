#include "bsq.h"
#define	BUF_SIZE 4096

int	ft_reader_size(char *path)
{
	int	fd;
	int ct;
	char buf[1];

	ct = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		write(2, "map error\n", 10);
		close (fd);
		return (0);
	}
	while (read(fd, buf, 1))
	{
		if (buf[0] == '\n')
				break ;
		if (buf[0] == '\0')
		{
			write(2, "map error\n", 10);
			close (fd);
			return (0);
		}
	}
	while (read(fd, buf, 1))
	{
		ct++;
		if (buf[0] == '\n')
			break ;
	}
	close(fd);
	return (ct);
}

int	ft_minimum(int a, int b, int c)
{
	int min;

	min = a;
	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int ft_first_line(int fd, char *buf, t_ref *reference)
{
	int i;
	char *first;

	i = 0;
	first = malloc(sizeof(char) * 12);
	while (read(fd, buf, 1))
	{
		buf[1] = '\0';
		if (i > 11 && i < 4)
		{
			write(2, "map error\n", 10);
			close (fd);
			return (0);
		}
		first[i] = buf[0];
		if (buf[0] == '\n')
		{
			first[i + 1] = '\0';
			reference->sqr = first[i - 1];
			reference->obs = first[i - 2];
			reference->vide = first[i - 3];
			reference->line = ft_atoi(first, reference->vide);
			if (reference->line == 0 || reference->sqr == reference->obs ||
				reference->obs == reference->vide || reference->sqr == reference->vide)
			{
				write(2, "map error\n", 10);
				close (fd);
				return (0);
			}
			break ;
		}
		i++;
	}
	free(first);
	return (1);
}

int	ft_read_map(char *path, int ct, t_ref *reference)
{
	int		fd;
	char 	buf[BUF_SIZE + 1];
	int		**tab;
	int 	i;
	int 	j;
	int		k;
	int		ret;

	i = 0;
	j = 0;
	printf("ct = %d\n", ct);
	fd = open(path, O_RDONLY);
	ft_first_line(fd, buf, reference);
	printf("sqr = %c | obs = %c | vide = %c\n", reference->sqr, reference->obs, reference->vide);
	tab = (int**)malloc(sizeof(*tab) * (reference->line + 1));
	printf("ref->line = %d\n", reference->line);
	tab[0] = malloc(sizeof(int) * (ct));
	while (ret = read(fd, buf, BUF_SIZE))
	{
		buf[ret] = '\0';
		k = 0;
		while (buf[k])
		{
			if ((ft_read_er(buf[k], reference, i, ct)) == 0)
				return (0);
			if (buf[k] == reference->vide)
			{
				tab[j][i] = ((j == 0 || i == 0) && buf[k] != reference->obs) ? 1
				: (ft_minimum(tab[j - 1][i], tab[j][i - 1], tab[j - 1][i - 1])) + 1;
				if (tab[j][i] > reference->max)
				{
					reference->max = tab[j][i];
					reference->i = i;
					reference->j = j;
				}
				i++;
			}
			else if (buf[k] == reference->obs)
			{
				tab[j][i] = 0;
				i++;
			}
			else if (buf[k] == '\n' || buf[k] == '\0')
			{
				tab[j][i] = -1;
				if (i != ct - 1)
				{
					write(2, "map error\n", 10);
					return (0);
				}
				i = 0;
				j++;
				tab[j] = malloc(sizeof(int) * (ct + 1));
			}
			if (buf[k] == '\0')
				return (0);
			k++;
		}
}
	if (j != reference->line)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	printf("j = %d\n", j);
	printf("ref->i = %d | ref->j = %d | ref->max = %d\n", reference->i, reference->j, reference->max);
	print_tab(tab, reference);
	free(tab);
	close (fd);
	return (1);
}
