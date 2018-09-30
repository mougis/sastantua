#include "sastantua.h"

static void	init_yx(int *yx, int s, int size)
{
	int	i;

	yx[0] = s + 2;
	yx[1] = 0;
	i = -1;
	yx[2] = 0;
	while (++i < size)
		yx[2] += (i == 0) ? 7 : 2 * ((i + 3) + i % 2 + i / 2 + 1);
	yx[3] = -((yx[0] - 1) * 2);
	i = -1;
	while (++i < s)
		yx[3] += (i == 0) ? 7 : 2 * ((i + 3) + i % 2 + i / 2 + 1);
	yx[4] = yx[2];
	yx[2] = (yx[2] - yx[3]) / 2;
}

static void	door(int s, int *x, int *yx)
{
	int		i;
	int		d;

	d = (s % 2) ? s : s - 1;
	i = 0;
	while (i++ < d)
	{
		if (d >= 5 && yx[1] == (yx[0] - d / 2) && i == d - 1)
			putchr('$');
		else
			putchr('|');
		(*x)--;
	}
	++(*x);
}

static void	line(int *yx, int s, int size)
{
	int		x;
	int		d;

	d = (size % 2) ? size : size - 1;
	d = -(d - yx[0]);
	x = yx[2];
	while (x-- > 0)
		putchr(' ');
	x = yx[3];
	while (x-- > 0)
	{
		if (x == yx[3] - 1)
			putchr('/');
		else if (x == 0)
			putchr('\\');
		else if (s == size && yx[1] > d && x == (yx[3] + size) / 2 - 1)
			door(size, &x, yx);
		else
			putchr('*');
	}
}

void		sastantua(int size)
{
	int			yx[5];
	static int	saved_size = 0;

	if (size <= 0)
		return ;
	saved_size = (saved_size == 0) ? size : saved_size;
	sastantua(size - 1);
	init_yx(yx, size, saved_size);
	while (yx[1]++ < yx[0])
	{
		line(yx, size, saved_size);
		yx[3] += 2;
		yx[2] = (yx[4] - yx[3]) / 2;
		putchr('\n');
	}
}
