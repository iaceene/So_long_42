/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:14:13 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/15 17:23:08 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

static int	ft_int_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
		n *= -1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_cpy(long nbr, char *str, int len)
{
	while (nbr)
	{
		str[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
}

static void	ft_fill_bites(char *list, int len)
{
	while (len < 12)
		list[len++] = '\0';
}

void	ft_putnbr(int n)
{
	char	list[12];
	int		len;
	long	nbr;

	nbr = n;
	len = ft_int_len(nbr);
	if (nbr == 0)
		return ;
	if (nbr < 0)
	{
		len++;
		list[0] = '-';
		nbr *= -1;
	}
	ft_cpy(nbr, list, len);
	ft_fill_bites(list, len);
	ft_putstr("moves : ");
	ft_putstr(list);
	ft_putstr("\n");
}
