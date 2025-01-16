/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_ia_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 21:02:13 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/16 23:07:34 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

void	ft_find_enm(t_enemy *enm)
{
	int		x;
	int		y;
	char	**map;

	map = enm->vars->data->map2d;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'H')
			{
				enm->x = x;
				enm->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_move(t_enemy *enm)
{
	char	**map;
	int		i;

	i = rand();
	map = enm->vars->data->map2d;
	if (i % 4 == 0)
		move_up_enm(enm);
	else if (i % 4 == 1)
		move_down_enm(enm);
	else if (i % 4 == 2)
		move_left_enm(enm);
	else if (i % 4 == 3)
		move_right_enm(enm);
}

void	ft_move_enemy(t_vars *vars)
{
	t_enemy		enm;
	static int	i;

	enm.vars = vars;
	ft_find_enm(&enm);
	ft_move(&enm);
	i++;
}
