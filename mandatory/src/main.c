#include "../include/so_long.h"


int main(int c, char **v)
{
    if (c == 2)
    {
        ft_check_map(v[1]);
        ft_init();
    }
    else
        ft_puterror("Error\n");
}