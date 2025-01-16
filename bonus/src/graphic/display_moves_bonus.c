/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:37:41 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/16 23:05:57 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_display_moves(t_vars *vars, char *moves)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall, 64, 0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->wall, 64 * 2, 0);
	mlx_string_put(vars->mlx, vars->win, 20, 40,
		0xFF0000, ft_join("moves : ", moves));
}
