/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utiles.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:56:53 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 16:59:58 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void    ft_map_rebuild(t_vars *vars, int move)
{
	int x = vars->data->player_x;
	int y = vars->data->player_y;

	if (move == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->worm,  x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->ground,  x * 64, (y + 1) * 64);
	}
	if (move == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->worm,  x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->ground,  x * 64, (y - 1) * 64);
	}
	if (move == 3)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->worm,  x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->ground,  (x + 1) * 64, y * 64);
	}
	if (move == 4)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->worm,  x * 64, y * 64);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img->ground,  (x - 1) * 64, y * 64);
	}
}
