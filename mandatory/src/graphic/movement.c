/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:34:47 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 11:36:02 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int move_up(t_vars *vars)
{
	int x = vars->data->player_x;
	int y = vars->data->player_y;
	char **map = vars->data->map2d;
	if (map[y - 1][x] == '0')
	{
		vars->data->player_y = y - 1;
		map[y][x] = '0';
		map[y - 1][x] = 'P';
		return (1);
	}
	return (0);
}

int move_down(t_vars *vars)
{
	int x = vars->data->player_x;
	int y = vars->data->player_y;
	char **map = vars->data->map2d;
	if (map[y + 1][x] == '0')
	{
		vars->data->player_y = y + 1;
		map[y][x] = '0';
		map[y + 1][x] = 'P';
		return (1);
	}
	return (0);
}
int move_left(t_vars *vars)
{
	int x = vars->data->player_x;
	int y = vars->data->player_y;
	char **map = vars->data->map2d;
	if (map[y][x - 1] == '0')
	{
		vars->data->player_x = x - 1;
		map[y][x] = '0';
		map[y][x - 1] = 'P';
		return (1);
	}
	return (0);
}

int move_right(t_vars *vars)
{
	int x = vars->data->player_x;
	int y = vars->data->player_y;
	char **map = vars->data->map2d;
	if (map[y][x + 1] == '0')
	{
		vars->data->player_x = x + 1;
		map[y][x] = '0';
		map[y][x + 1] = 'P';
		return (1);
	}
	return (0);
}