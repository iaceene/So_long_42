/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:39:12 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/17 16:52:07 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_distory_imgs(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->img->apple);
	mlx_destroy_image(vars->mlx, vars->img->wall);
	mlx_destroy_image(vars->mlx, vars->img->worm);
	mlx_destroy_image(vars->mlx, vars->img->ground);
	mlx_destroy_image(vars->mlx, vars->img->hole);
	mlx_destroy_image(vars->mlx, vars->img->enemy);
	mlx_destroy_image(vars->mlx, vars->img->apple_2);
	mlx_destroy_image(vars->mlx, vars->img->wall_left);
	mlx_destroy_image(vars->mlx, vars->img->wall_center);
	mlx_destroy_image(vars->mlx, vars->img->wall_right);
}

void	ft_end_game(t_vars *vars, int c)
{
	ft_distory_imgs(vars);
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_malloc(-1);
	if (c == 1)
		ft_putstr("You WIN !!!\n");
	else if (c == 2)
		ft_putstr("You LOSE !!!, loser\n");
	else
		ft_putstr("bye !\n");
	exit(0);
}
