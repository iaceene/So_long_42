/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:55:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/18 23:09:39 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

#define APPLE_1 "bonus/src/graphic/imgs/apple_1.xpm"
#define APPLE_2 "bonus/src/graphic/imgs/apple_2.xpm"
#define GROUND "bonus/src/graphic/imgs/ground.xpm"
#define HOLE "bonus/src/graphic/imgs/hole.xpm"
#define WALL "bonus/src/graphic/imgs/wall.xpm"
#define WORM "bonus/src/graphic/imgs/worm.xpm"
#define ENEMY "bonus/src/graphic/imgs/enemy.xpm"
#define W_LEFT "bonus/src/graphic/imgs/wall_bg_left.xpm"
#define W_CENTER "bonus/src/graphic/imgs/wall_bg_center.xpm"
#define W_RIGHT "bonus/src/graphic/imgs/wall_bg_right.xpm"

static int	helper(void)
{
	int	fd;

	fd = open(ENEMY, 0);
	if (fd == -1)
		return (1);
	fd = open(W_CENTER, 0);
	if (fd == -1)
		return (1);
	fd = open(W_LEFT, 0);
	if (fd == -1)
		return (1);
	fd = open(W_RIGHT, 0);
	if (fd == -1)
		return (1);
	return (0);
}

int	ft_check_file(void)
{
	int	fd;

	fd = open(APPLE_1, 0);
	if (fd == -1)
		return (1);
	fd = open(APPLE_2, 0);
	if (fd == -1)
		return (1);
	fd = open(GROUND, 0);
	if (fd == -1)
		return (1);
	fd = open(HOLE, 0);
	if (fd == -1)
		return (1);
	fd = open(WALL, 0);
	if (fd == -1)
		return (1);
	fd = open(WORM, 0);
	if (fd == -1)
		return (1);
	if (helper())
		return (1);
	else
		return (0);
}
