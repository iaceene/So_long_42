/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:48:11 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/18 22:54:06 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

#define APPLE "mandatory/src/graphic/imgs/apple.xpm"
#define GROUND "mandatory/src/graphic/imgs/ground.xpm"
#define HOLE "mandatory/src/graphic/imgs/hole.xpm"
#define WALL "mandatory/src/graphic/imgs/wall.xpm"
#define WORM "mandatory/src/graphic/imgs/worm.xpm"

int	ft_check_file(void)
{
	int	fd;

	fd = open(APPLE, 0);
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
	return (0);
}
