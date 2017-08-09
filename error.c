#include "bsq.h"

int	ft_char_er(char buf, t_ref *reference)
{
	if (buf == reference->vide || buf == reference->obs || buf == '\n')
		return(1);
	return(0);
}

int	ft_read_er(char buf, t_ref *reference, int i, int ct)
{
	if ((ft_char_er(buf, reference)) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	if (i == ct)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	return (1);
}
