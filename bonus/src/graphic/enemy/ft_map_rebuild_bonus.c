/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_rebuild_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 23:40:02 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 23:51:51 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/so_long_bonus.h"

static void	ft_up(t_enemy *enm)
{
	int	x;
	int	y;

	x = enm->x;
	y = enm->y;
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->enemy, x * 64, y * 64);
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->ground, x * 64, (y + 1) * 64);
}

static void	ft_down(t_enemy *enm)
{
	int	x;
	int	y;

	x = enm->x;
	y = enm->y;
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->enemy, x * 64, y * 64);
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->ground, x * 64, (y - 1) * 64);
}

static void	ft_left(t_enemy *enm)
{
	int	x;
	int	y;

	x = enm->x;
	y = enm->y;
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->enemy, x * 64, y * 64);
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->ground, (x + 1) * 64, y * 64);
}

static void	ft_right(t_enemy *enm)
{
	int	x;
	int	y;

	x = enm->x;
	y = enm->y;
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->enemy, x * 64, y * 64);
	mlx_put_image_to_window(enm->vars->mlx, enm->vars->win,
		enm->vars->img->ground, (x - 1) * 64, y * 64);
}

void	ft_map_rebuild_enem(t_enemy *enm, int move)
{
	if (move == 1)
		ft_up(enm);
	if (move == 2)
		ft_down(enm);
	if (move == 3)
		ft_left(enm);
	if (move == 4)
		ft_right(enm);
}