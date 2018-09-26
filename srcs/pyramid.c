#include "sastantua.h"

#ifndef L
# define L x_line(x_start(y_floor(n), i_floor(n)), y - 1)
#endif

void	pyramid(unsigned int size, unsigned int n)
{
	unsigned int	x;
	unsigned int	y;

	if (!size)
		return ;
	y = 0;
	while (y++ < y_floor(n))
	{
		x = L;
		spaces(x_line(x_start(y_floor(n), i_floor(n)), y_floor(size - 1)), x)
		while (x-- > 0)
		{
			if (x == L - 1)
				putchr((int)'/');
			else if (x == 0)
				putchr((int)'\\');
			else if (n == size - 1 && y == 3 && x == L / 2 + size / 2)
				door(y, &x);
			else
				putchr((int)'*');
		}
	}
	if (n < size)
		pyramid(size, n + 1);
}
