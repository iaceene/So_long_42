/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:05:32 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/13 22:37:26 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int c, char **v)
{
	t_list	data;

	if (c != 2)
		return (ft_puterr("usage .. \n"), 1);
	ft_init(v[1], &data);
	if (data.is_valid == 0)
		ft_puterr("invalid map !\n");
	else
		ft_puterr("valid map !\n");
	return (ft_malloc(-1), 0);
}
