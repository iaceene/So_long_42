/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 20:33:46 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/14 22:26:32 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include <stdio.h>


typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_list	*data;
}				t_vars;

typedef struct s_images
{
	void	*worm;
	void	*apple;
	void	*wall;
	void	*hole;
	void	*ground;
} t_images;

void ft_end_game(t_vars *vars);

char *ft_set_images(t_images *img, t_vars *vars)
{
	int h;
	int w;

	h = 64;
	w = 64;
	img->apple = mlx_xpm_file_to_image(vars->mlx, "imgs/apple.xpm", &w, &h);
	if (!img->apple)
		return (NULL);
	img->worm = mlx_xpm_file_to_image(vars->mlx, "./imgs/worm.xpm", &w, &h);
	if (!img->worm)
		return (NULL);
	img->wall = mlx_xpm_file_to_image(vars->mlx, "./imgs/wall.xpm", &w, &h);
	if (!img->wall)
		return (NULL);
	img->hole = mlx_xpm_file_to_image(vars->mlx, "./imgs/hole.xpm", &w, &h);
	if (!img->hole)
		return (NULL);
	img->ground = mlx_xpm_file_to_image(vars->mlx, "./imgs/ground.xpm", &w, &h);
	if (!img->ground)
		return (NULL);
	return (NULL);
}

void ft_put_images(t_images *img, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, img->apple, 0, 0);
}

int	ft_render(t_vars *vars)
{
	char *status;
	t_images img;

	status = ft_set_images(&img, vars);
	if (!status)
		ft_end_game(vars);
	ft_put_images(&img, vars);
	return (0);
}

void ft_end_game(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	ft_malloc(-1);
	ft_puterr("bye!\n");
	exit(0);
}

void ft_key_press(int key, t_vars *vars)
{
	if (key == XK_Up || key == XK_w)
	{
		ft_render(vars);
		printf("move up\n");
	}
	else if (key == XK_Down || key == XK_s)
	{
		ft_render(vars);
		printf("move down\n");
	}
	else if (key == XK_Left || key == XK_a)
	{
		ft_render(vars);
		printf("move left\n");
	}
	else if (key == XK_Right || key == XK_d)
	{
		ft_render(vars);	
		printf("move right\n");
	}
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

void	start_game(t_list *data)
{
	t_vars	vars;

	if (data->is_valid == 0)
		return ;
	else
		vars.mlx = mlx_init();
	vars.data = data;
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Worm");
	ft_render(&vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
