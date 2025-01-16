/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:41:08 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/16 22:37:14 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	*xpm_converter(void *mlx, int img)
{
	int	h;
	int	w;

	if (img == 1)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/apple_1.xpm", &w, &h));
	if (img == 2)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/worm.xpm", &w, &h));
	if (img == 3)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/wall.xpm", &w, &h));
	if (img == 4)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/hole.xpm", &w, &h));
	if (img == 5)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/ground.xpm", &w, &h));
	if (img == 6)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/enemy.xpm", &w, &h));
	if (img == 7)
		return (mlx_xpm_file_to_image(mlx,
				"./bonus/src/graphic/imgs/apple_2.xpm", &w, &h));
	return (NULL);
}

char	*ft_set_images(t_images *img, t_vars *vars)
{
	img->apple = xpm_converter(vars->mlx, 1);
	if (!img->apple)
		return (NULL);
	img->worm = xpm_converter(vars->mlx, 2);
	if (!img->worm)
		return (NULL);
	img->wall = xpm_converter(vars->mlx, 3);
	if (!img->wall)
		return (NULL);
	img->hole = xpm_converter(vars->mlx, 4);
	if (!img->hole)
		return (NULL);
	img->ground = xpm_converter(vars->mlx, 5);
	if (!img->ground)
		return (NULL);
	img->enemy = xpm_converter(vars->mlx, 6);
	if (!img->enemy)
		return (NULL);
	img->apple_2 = xpm_converter(vars->mlx, 7);
	if (!img->enemy)
		return (NULL);
	return ("Valid");
}

void	ft_put_img_to_win(t_images *img, void *mlx, void *win, char c)
{
	if (c == '0')
		mlx_put_image_to_window(mlx, win,
			img->ground, img->x, img->y);
	else if (c == '1')
		mlx_put_image_to_window(mlx, win,
			img->wall, img->x, img->y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, win,
			img->apple, img->x, img->y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx, win,
			img->worm, img->x, img->y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, win,
			img->hole, img->x, img->y);
	else if (c == 'H')
		mlx_put_image_to_window(mlx, win,
			img->enemy, img->x, img->y);
}

void	ft_put_images(t_images *img, t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	map = vars->data->map2d;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			img->x = x * 64;
			img->y = y * 64;
			ft_put_img_to_win(img, vars->mlx,
				vars->win, map[y][x]);
			x++;
		}
		y++;
	}
}

int	ft_render(t_vars *vars, int move)
{
	static char		*status;
	static t_images	img;
	static int		number;

	if (move == 0)
	{
		status = ft_set_images(&img, vars);
		if (status)
			ft_put_images(&img, vars);
		else
			ft_end_game(vars, 0);
		vars->img = &img;
	}
	ft_map_rebuild(vars, move);
	ft_display_moves(vars, ft_itoa(number));
	number++;
	return (0);
}