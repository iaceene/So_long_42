/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:43:48 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 12:42:26 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void ft_key_press(int key, t_vars *vars)
{
	if (key == XK_Up || key == XK_w)
		move_up(vars);
	else if (key == XK_Down || key == XK_s)
		move_down(vars);
	else if (key == XK_Left || key == XK_a)
		move_left(vars);
	else if (key == XK_Right || key == XK_d)
		move_right(vars);
	else
		return ;
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape && vars->mlx)
		ft_end_game(vars);
	else
		ft_key_press(keycode, vars);
	return (0);
}