/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:39:12 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 21:38:15 by yaajagro         ###   ########.fr       */
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
}

void	ft_end_game(t_vars *vars)
{
	ft_distory_imgs(vars);
	mlx_destroy_display(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	ft_malloc(-1);
	ft_putstr("bye!\n");
	exit(0);
}
