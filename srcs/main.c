#include "sastantua.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, USAGE, sizeof(USAGE) - 1);
		return (1);
	}
	sastantua((int)ato_ui(av[ac - 1]));
	return (0);
}
