/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:30 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/18 23:18:30 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../../mlx/mlx.h"
# include "get_next_line.h"

typedef struct s_gb
{
	void		*ptr;
	struct s_gb	*next;
}t_gb;

typedef struct s_list
{
	char	*map;
	char	**map2d;
	int		hight;
	int		wight;
	int		is_valid;
	int		player_x;
	int		player_y;
}t_list;

typedef struct s_images
{
	void	*worm;
	void	*apple;
	void	*wall;
	void	*hole;
	void	*ground;
	int		x;
	int		y;
}	t_images;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_list		*data;
	t_images	*img;
}				t_vars;

void	*ft_malloc(ssize_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s);
int		ft_check_file(void);
void	ft_puterr(char *s);
void	ft_map_set(t_list *data);
int		ft_strncmp(char *str1, char *str2, size_t n);
int		ft_charcter_check(char c);
int		ft_check_wall(char *s, int flag);
void	ft_map_checker(t_list *data);
int		ft_check_extention(char *file);
void	ft_map_content(t_list *data);
void	ft_check_path(t_list *data);
int		ft_init(char *file, t_list *data);
void	start_game(t_list *data);
int		move_up(t_vars *vars);
int		move_down(t_vars *vars);
int		move_left(t_vars *vars);
int		move_right(t_vars *vars);
void	ft_end_game(t_vars *vars);
char	*ft_set_images(t_images *img, t_vars *vars);
void	ft_put_images(t_images *img, t_vars *vars);
int		ft_render(t_vars *vars, int move);
int		key_hook(int keycode, t_vars *vars);
void	ft_key_press(int key, t_vars *vars);
void	ft_map_rebuild(t_vars *vars, int move);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
#endif