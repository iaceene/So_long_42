/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:41:08 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 11:42:48 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char *ft_set_images(t_images *img, t_vars *vars)
{
	int h;
	int w;

	h = 64;
	w = 64;
	img->apple = mlx_xpm_file_to_image(vars->mlx, "./mandatory/src/graphic/imgs/apple.xpm", &w, &h);
	if (!img->apple)
		return (NULL);
	img->worm = mlx_xpm_file_to_image(vars->mlx, "./mandatory/src/graphic/imgs/worm.xpm", &w, &h);
	if (!img->worm)
		return (NULL);
	img->wall = mlx_xpm_file_to_image(vars->mlx, "./mandatory/src/graphic/imgs/wall.xpm", &w, &h);
	if (!img->wall)
		return (NULL);
	img->hole = mlx_xpm_file_to_image(vars->mlx, "./mandatory/src/graphic/imgs/hole.xpm", &w, &h);
	if (!img->hole)
		return (NULL);
	img->ground = mlx_xpm_file_to_image(vars->mlx, "./mandatory/src/graphic/imgs/ground.xpm", &w, &h);
	if (!img->ground)
		return (NULL);
	vars->img = img;
	return ("Valid");
}

void ft_put_images(t_images *img, t_vars *vars)
{
	int x;
	int y;
	char **map = vars->data->map2d;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
				mlx_put_image_to_window(vars->mlx, vars->win, img->ground, x * 64, y * 64);
			else if (map[y][x] == '1')
				mlx_put_image_to_window(vars->mlx, vars->win, img->wall,  x * 64, y * 64);
			else if (map[y][x] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win, img->apple,  x * 64, y * 64);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(vars->mlx, vars->win, img->worm,  x * 64, y * 64);
			else if (map[y][x] == 'E')
				mlx_put_image_to_window(vars->mlx, vars->win, img->hole,  x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	ft_render(t_vars *vars)
{
	static char *status;
	static int state;
	t_images img;

	if (state == 0)
		status = ft_set_images(&img, vars);
	if (!status)
		ft_end_game(vars);
	ft_put_images(&img, vars);
	return (0);
}