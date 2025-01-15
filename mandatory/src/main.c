/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:05:32 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 18:25:42 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_error(int err)
{
	if (err == 1)
    	ft_puterr("Error: Usage - ./so_long mandatory/maps/map.ber\n");
	else if (err == 2)
    	ft_puterr("Error: Invalid map. Please try a different map!\n");
	return (1);
}

int	main(int c, char **v)
{
	t_list	data;

	if (c != 2)
		return (ft_error(1));
	ft_init(v[1], &data);
	if (data.is_valid == 0)
		return (ft_error(2), ft_malloc(-1), 1);
	start_game(&data);
	return (ft_malloc(-1), 0);
}
