/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:33:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/17 14:27:25 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	mlx_loop(vars.mlx);
}
