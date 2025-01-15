/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:47 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 20:43:47 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	ft_is_collect_all(t_vars *vars)
{
	char	**map;
	int		x;
	int		y;

	map = vars->data->map2d;
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	move_up(t_vars *vars)
{
	char	p;
	char	**map;

	map = vars->data->map2d;
	p = map[vars->data->player_y - 1][vars->data->player_x];
	if (p == '0' || p == 'E' || p == 'C')
	{
		if (p == 'E')
		{
			if (ft_is_collect_all(vars))
				ft_end_game(vars);
		}
		else
		{
			map[vars->data->player_y][vars->data->player_x] = '0';
			vars->data->player_y = vars->data->player_y - 1;
			map[vars->data->player_y][vars->data->player_x] = 'P';
			ft_render(vars, 1);
		}
	}
	return (0);
}

int	move_down(t_vars *vars)
{
	char	p;
	char	**map;

	map = vars->data->map2d;
	p = map[vars->data->player_y + 1][vars->data->player_x];
	if (p == '0' || p == 'E' || p == 'C')
	{
		if (p == 'E')
		{
			if (ft_is_collect_all(vars))
				ft_end_game(vars);
		}
		else
		{
			map[vars->data->player_y][vars->data->player_x] = '0';
			vars->data->player_y = vars->data->player_y + 1;
			map[vars->data->player_y][vars->data->player_x] = 'P';
			ft_render(vars, 2);
		}
	}
	return (0);
}

int	move_left(t_vars *vars)
{
	char	p;
	char	**map;

	map = vars->data->map2d;
	p = map[vars->data->player_y][vars->data->player_x - 1];
	if (p == '0' || p == 'E' || p == 'C')
	{
		if (p == 'E')
		{
			if (ft_is_collect_all(vars))
				ft_end_game(vars);
		}
		else
		{
			map[vars->data->player_y][vars->data->player_x] = '0';
			vars->data->player_x = vars->data->player_x - 1;
			map[vars->data->player_y][vars->data->player_x] = 'P';
			ft_render(vars, 3);
		}
	}
	return (0);
}

int	move_right(t_vars *vars)
{
	char	p;
	char	**map;

	map = vars->data->map2d;
	p = map[vars->data->player_y][vars->data->player_x + 1];
	if (p == '0' || p == 'E' || p == 'C')
	{
		if (p == 'E')
		{
			if (ft_is_collect_all(vars))
				ft_end_game(vars);
		}
		else
		{
			map[vars->data->player_y][vars->data->player_x] = '0';
			vars->data->player_x = vars->data->player_x + 1;
			map[vars->data->player_y][vars->data->player_x] = 'P';
			ft_render(vars, 4);
		}
	}
	return (0);
}
