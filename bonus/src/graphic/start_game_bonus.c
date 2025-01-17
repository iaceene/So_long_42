/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:33:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/17 14:25:57 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_show_apple(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->data->map2d;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx,
					vars->win, vars->img->apple, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_hide_apple(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->data->map2d;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->img->apple_2, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	ft_animations(t_vars *vars)
{
	static int	i;
	static int	x;

	if (i % 2 == 0 && x % 5 == 0)
		ft_hide_apple(vars);
	else if (i % 2 != 0 && x % 5 == 0)
		ft_show_apple(vars);
	x++;
	i++;
}

int	my_hook(void *param)
{
	t_vars		*vars;
	static int	x;

	vars = (t_vars *)param;
	if (x % 10000 == 0)
	{
		ft_move_enemy(vars);
		ft_animations(vars);
	}
	x++;
	return (0);
}

void	start_game(t_list *data)
{
	t_vars	vars;
	int		size_x;
	int		size_y;

	if (data->is_valid == 0)
		return ;
	else
		vars.mlx = mlx_init();
	if (!vars.mlx)
		return ;
	size_x = (data->wight - 1) * 64;
	size_y = data->hight * 64;
	vars.data = data;
	vars.win = mlx_new_window(vars.mlx, size_x, size_y, "Worm");
	if (!vars.win)
		return ;
	ft_render(&vars, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, my_hook, &vars);
	mlx_loop(vars.mlx);
}
