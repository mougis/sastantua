#include "sastantua.h"

unsigned int	ato_ui(const char *a)
{
	unsigned int	ui;

	ui = 0;
	if (!(*a))
		return (ui);
	while (*a == '+' || (*a >= 9 && *a <= 13) || *a == 32)
		a++;
	while (*a >= '0' && *a <= '9')
		ui = ui * 10 + *(a++) - '0';
	return (ui);
}
