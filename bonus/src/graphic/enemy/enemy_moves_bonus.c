/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:26:03 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/16 23:06:52 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

int	move_up_enm(t_enemy *enm)
{
	char	p;
	char	**map;

	map = enm->vars->data->map2d;
	p = map[enm->y - 1][enm->x];
	if (p == '0' || p == 'P')
	{
		if (p == 'P')
			ft_end_game(enm->vars, 2);
		else
		{
			map[enm->y][enm->x] = '0';
			enm->y = enm->y - 1;
			map[enm->y][enm->x] = 'H';
			ft_map_rebuild_enem(enm, 1);
		}
	}
	return (0);
}

int	move_down_enm(t_enemy *enm)
{
	char	p;
	char	**map;

	map = enm->vars->data->map2d;
	p = map[enm->y + 1][enm->x];
	if (p == '0' || p == 'P')
	{
		if (p == 'P')
			ft_end_game(enm->vars, 2);
		else
		{
			map[enm->y][enm->x] = '0';
			enm->y = enm->y + 1;
			map[enm->y][enm->x] = 'H';
			ft_map_rebuild_enem(enm, 2);
		}
	}
	return (0);
}

int	move_left_enm(t_enemy *enm)
{
	char	p;
	char	**map;

	map = enm->vars->data->map2d;
	p = map[enm->y][enm->x - 1];
	if (p == '0' || p == 'P')
	{
		if (p == 'P')
			ft_end_game(enm->vars, 2);
		else
		{
			map[enm->y][enm->x] = '0';
			enm->x = enm->x - 1;
			map[enm->y][enm->x] = 'H';
			ft_map_rebuild_enem(enm, 3);
		}
	}
	return (0);
}

int	move_right_enm(t_enemy *enm)
{
	char	p;
	char	**map;

	map = enm->vars->data->map2d;
	p = map[enm->y][enm->x + 1];
	if (p == '0' || p == 'P')
	{
		if (p == 'P')
			ft_end_game(enm->vars, 2);
		else
		{
			map[enm->y][enm->x] = '0';
			enm->x = enm->x + 1;
			map[enm->y][enm->x] = 'H';
			ft_map_rebuild_enem(enm, 4);
		}
	}
	return (0);
}
