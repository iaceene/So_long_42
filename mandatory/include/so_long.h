/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:30 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/14 21:01:23 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../../mlx_linux/mlx.h"
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

void	*ft_malloc(ssize_t len);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s);
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


#endif