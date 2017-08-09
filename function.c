#include "bsq.h"

void    ft_putchar(char c)
{
  write(1, &c, 1);
}

void    ft_putstr(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    ft_putchar(str[i]);
    i++;
  }
}

void    ft_putnbr(int nb)
{
  if (nb > 9)
    ft_putnbr(nb / 10);
  ft_putchar(nb % 10 + '0');
}

t_ref	ft_create_ref(void)
{
	t_ref		tmp;

	tmp.i = 0;
	tmp.j = 0;
	tmp.max = 0;
	return(tmp);
}

void print_tab(int **tab, t_ref	*reference)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < reference->line)
	{
		if (j <= reference->j && j > reference->j - reference->max &&
			 i <= reference->i && i > reference->i - reference->max)
			ft_putchar(reference->sqr);
		else if (tab[j][i] > 0)
			ft_putchar(reference->vide);
		else if (tab[j][i] == 0)
			ft_putchar(reference->obs);
		if (tab[j][i] == -1)
		{
			ft_putchar('\n');
			j++;
			i = -1;
		}
		i++;
	}
}

int		ft_atoi(char *str, char vide)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	if (str[i] != vide)
		return (0);
	return (nb);
}
