/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:37:41 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/17 16:53:28 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	*ft_image_conv(t_vars *vars, int i, int h, int w)
{
	if (i == 1)
		return (mlx_xpm_file_to_image(vars->mlx,
				"./bonus/src/graphic/imgs/wall_bg_left.xpm", &w, &h));
	else if (i == 2)
		return (mlx_xpm_file_to_image(vars->mlx,
				"./bonus/src/graphic/imgs/wall_bg_center.xpm", &w, &h));
	else if (i == 3)
		return (mlx_xpm_file_to_image(vars->mlx,
				"./bonus/src/graphic/imgs/wall_bg_right.xpm", &w, &h));
	return ("valid");
}

int	ft_add_imgs(t_vars *vars)
{
	vars->img->wall_left = ft_image_conv(vars, 1, 64, 64);
	if (!vars->img->wall_left)
		return (-1);
	vars->img->wall_center = ft_image_conv(vars, 2, 64, 64);
	if (!vars->img->wall_center)
		return (-1);
	vars->img->wall_right = ft_image_conv(vars, 3, 64, 64);
	if (!vars->img->wall_right)
		return (-1);
	return (0);
}

int	ft_destroy_win(t_vars *ptr)
{
	ft_end_game(ptr, 0);
	return (0);
}

void	ft_display_moves(t_vars *vars, char *moves)
{
	static int	state;

	if (state == 0)
		if (ft_add_imgs(vars) == -1)
			ft_end_game(vars, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->wall_left, 0, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->wall_center, 64, 0);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->img->wall_right, 64 * 2, 0);
	mlx_string_put(vars->mlx, vars->win, 40, 35,
		~0, ft_join("moves : ", moves));
	state++;
}
