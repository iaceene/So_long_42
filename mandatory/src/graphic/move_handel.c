/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_handel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:45:35 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 11:47:55 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"


int ft_valid_move(int move, t_vars *vars)
{
	if (move == 1)
		if (move_up(vars))
			return (1);
	if (move == 2)
		if (move_down(vars))
			return (1);
	if (move == 3)
		if (move_left(vars))
			return (1);
	if (move == 4)
		if (move_right(vars))
			return (1);
	return (0);
}

void ft_move_player(int move, t_vars *vars)
{
	static int count;
	
	if (ft_valid_move(move, vars))
	{
		ft_render(vars);
		count++;
	}
	// printf("move : %d\n", count);
}

