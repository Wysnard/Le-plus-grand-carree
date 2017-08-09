#ifndef BSQ_H
# define BSQ_H
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct	s_ref
{
	int		i;
	int		j;
	int		max;
	int		line;
	char	vide;
	char	obs;
	char	sqr;
}								t_ref;

void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putnbr(int nb);
int			ft_reader_size(char *path);
int		ft_read_map(char *path, int ct, t_ref *reference);
void 		print_tab(int **tab, t_ref *reference);
t_ref		ft_create_ref(void);
int			ft_atoi(char *str, char vide);
int			ft_char_er(char buf, t_ref *reference);
int			ft_read_er(char buf, t_ref *reference, int i, int ct);

#endif
