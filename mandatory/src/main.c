#include "../include/so_long.h"


int main(int c, char **v)
{
	if (c != 2)
		return (ft_puterr("usage .. \n"), 1);
	
	return (ft_malloc(0, 1), 0);
}