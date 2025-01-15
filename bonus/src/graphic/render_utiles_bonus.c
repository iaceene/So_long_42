/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utiles_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:56:53 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 20:44:06 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->data->player_x;
	y = vars->data->player_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->worm, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->ground, x * 64, (y + 1) * 64);
}

void	ft_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->data->player_x;
	y = vars->data->player_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->worm, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->ground, x * 64, (y - 1) * 64);
}

void	ft_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->data->player_x;
	y = vars->data->player_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->worm, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->ground, (x + 1) * 64, y * 64);
}

void	ft_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->data->player_x;
	y = vars->data->player_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->worm, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->ground, (x - 1) * 64, y * 64);
}

void	ft_map_rebuild(t_vars *vars, int move)
{
	if (move == 1)
		ft_up(vars);
	if (move == 2)
		ft_down(vars);
	if (move == 3)
		ft_left(vars);
	if (move == 4)
		ft_right(vars);
}
