#include "bsq.h"

int main(int argc, char **argv)
{
	t_ref		reference;
	int i;

	i = 1;
	while (i < argc)
	{
		reference = ft_create_ref();
		ft_read_map(argv[i], ft_reader_size(argv[i]), &reference);
		i++;
	}
	return (0) ;
}
