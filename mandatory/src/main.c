#include "../include/so_long.h"


void ft_puterr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void ft_map_set(t_list *data)
{
	char	*tmp;
	int		i;
	int		h;
	int		w;

	tmp = data->map;
	i = 0;
	h = 0;
	w = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			h++;
		if (h == 0)
			w++;
		i++;
	}
	data->hight = h + 1;
	data->wight = w + 1;
}

int	ft_check_wall(char *s, int flag)
{
	int i;

	i = 0;
	if (flag == 1)
	{
		while(s[i])
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

void ft_map_checker(t_list *data)
{
	char	**map;
	int		i;
	int		err;

	i = 0;
	map = ft_split(data->map, '\n');
	while(map[i])
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

int	ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		if (str1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int ft_check_extention(char *file)
{
	int i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strncmp(file + i, ".ber", ft_strlen(".ber")) != 0)
		return (1);
	return (0);
}

int ft_charcter_check(char c)
{
	return (c == 'C' || c == 'P' || c == '0' || c == '1' || c == 'E' || c == '\n');
}

void ft_map_content(t_list *data)
{
	int i;
	int exit;
	int col;
	int start;

	i = 0;
	exit = 0;
	col = 0;
	start = 0;
	while (data->map[i])
	{
		if (!ft_charcter_check(data->map[i]))
			data->is_valid = 0;
		if (data->map[i] == 'E')
			exit++;
		else if (data->map[i] == 'C')
			col++;
		else if (data->map[i] == 'P')
			start++;
		i++;
	}
	if (exit != 1 || col < 1 || start != 1)
		data->is_valid = 0;
}

int ft_init(char *file, t_list *data)
{
	char	*s;
	int		fd;
	char	*tmp;

	tmp = NULL;
	data->is_valid = 1;
	fd = open(file, 0);
	if (fd == -1 || ft_check_extention(file))
		return (data->is_valid = 0, 1);
	while((s = get_next_line(fd)))
		tmp = ft_join(tmp, s);
	data->map = tmp;
	ft_map_set(data);
	ft_map_checker(data);
	if (data->is_valid == 1)
		ft_map_content(data);
	return (0);
}

int main(int c, char **v)
{
	t_list data;

	if (c != 2)
		return (ft_puterr("usage .. \n"), 1);
	ft_init(v[1], &data);
	if (data.is_valid == 0)
		ft_puterr("invalid map !\n");
	else
		ft_puterr("valid map !\n");
	return (ft_malloc(-1), 0);
}
