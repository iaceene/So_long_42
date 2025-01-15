/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:46:01 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 20:43:05 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

char	**ft_copy_map(char **map)
{
	int		i;
	char	**cpy;

	i = 0;
	while (map[i])
		i++;
	cpy = ft_malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (map[i])
	{
		cpy[i] = ft_strdup(map[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

void	ft_find_player(t_list *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map2d[y])
	{
		x = 0;
		while (data->map2d[y][x])
		{
			if (data->map2d[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
			}
			x++;
		}
		y++;
	}
}

void	ft_floodfill(char **map, int x, int y)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	if (x > ft_strlen(map[0]) || y > row || x < 0 || y < 0)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'E'
		|| map[y][x] == 'C' || map[y][x] == 'P')
	{
		if (map[y][x] == 'E')
		{
			map[y][x] = 'X';
			return ;
		}	
		map[y][x] = 'X';
	}
	else
		return ;
	ft_floodfill(map, x - 1, y);
	ft_floodfill(map, x + 1, y);
	ft_floodfill(map, x, y - 1);
	ft_floodfill(map, x, y + 1);
}

void	ft_check_the_fild(char **map, t_list *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
			{
				data->is_valid = 0;
				break ;
			}
			x++;
		}
		y++;
	}
}

void	ft_check_path(t_list *data)
{
	char	**map;

	map = ft_copy_map(data->map2d);
	ft_find_player(data);
	ft_floodfill(map, data->player_x, data->player_y);
	ft_check_the_fild(map, data);
}
