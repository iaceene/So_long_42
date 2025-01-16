/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utiles_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:04:59 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 21:00:19 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long_bonus.h"

void	ft_puterr(char *s)
{
	while (*s)
		write(2, s++, 1);
}

void	ft_map_set(t_list *data)
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

int	ft_charcter_check(char c)
{
	return (c == 'C' || c == 'P' || c == '0'
		|| c == '1' || c == 'E' || c == '\n' || c == 'H');
}
