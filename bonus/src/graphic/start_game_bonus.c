/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:33:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/16 18:21:22 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"
#include <sys/time.h>

int my_hook(void *param)
{
    t_vars			*vars;
    struct timeval	current_time;
    long			elapsed_time;

	vars = (t_vars *)param;
    gettimeofday(&current_time, NULL);
    elapsed_time = (current_time.tv_sec - vars->last_time.tv_sec) * 1000000
    			+ (current_time.tv_usec - vars->last_time.tv_usec);
    if (elapsed_time >= vars->interval)
	{
        ft_move_enemy(vars);
        vars->last_time = current_time;
    }
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
	size_x = (data->wight - 1) * 64;
	size_y = data->hight * 64;
	vars.interval = 200000;
	vars.data = data;
	vars.win = mlx_new_window(vars.mlx, size_x, size_y, "Worm");
	ft_render(&vars, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop_hook(vars.mlx, my_hook, &vars);
	mlx_loop(vars.mlx);
}
