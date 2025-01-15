/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:02:08 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 20:43:14 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

int	ft_check_wall(char *s, int flag)
{
	int	i;

	i = 0;
	if (flag == 1)
	{
		while (s[i])
		{
			if (s[i] != '1')
				return (-1);
			i++;
		}
	}
	else
	{
		if (s[i] != '1' || s[ft_strlen(s) - 1] != '1')
			return (-1);
	}
	return (0);
}

void	ft_map_checker(t_list *data)
{
	char	**map;
	int		i;
	int		err;

	i = 0;
	map = ft_split(data->map, '\n');
	data->map2d = map;
	while (map[i])
	{
		if (i == 0 || i == data->hight)
			err = ft_check_wall(map[i], 1);
		else
			err = ft_check_wall(map[i], 0);
		if (ft_strlen(map[i]) != data->wight - 1 || err == -1)
		{
			data->is_valid = 0;
			break ;
		}
		i++;
	}
}

int	ft_check_extention(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (!file[i])
		return (1);
	if (ft_strncmp(file + i, ".ber", ft_strlen(file + i)) != 0)
		return (1);
	return (0);
}

void	ft_map_content(t_list *data)
{
	int	i;
	int	exit;
	int	col;
	int	start;

	i = -1;
	exit = 0;
	col = 0;
	start = 0;
	while (data->map[++i])
	{
		if (data->map[i] == '\n'
			&& (data->map[i + 1] == '\n' || data->map[i + 1] == '\0'))
			data->is_valid = 0;
		if (!ft_charcter_check(data->map[i]))
			data->is_valid = 0;
		if (data->map[i] == 'E')
			exit++;
		else if (data->map[i] == 'C')
			col++;
		else if (data->map[i] == 'P')
			start++;
	}
	if (exit != 1 || col < 1 || start != 1)
		data->is_valid = 0;
}

int	ft_init(char *file, t_list *data)
{
	char	*s;
	int		fd;
	char	*tmp;

	tmp = NULL;
	data->is_valid = 1;
	fd = open(file, 0);
	if (fd == -1 || ft_check_extention(file))
		return (data->is_valid = 0, 1);
	s = get_next_line(fd);
	while (s)
	{
		tmp = ft_join(tmp, s);
		s = get_next_line(fd);
	}
	data->map = tmp;
	ft_map_set(data);
	ft_map_checker(data);
	if (data->is_valid == 1)
		ft_map_content(data);
	if (data->is_valid == 1)
		ft_check_path(data);
	return (0);
}
