/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:30 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/13 18:41:19 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
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
	int		hight;
	int		wight;
	int		is_valid;
}t_list;

void	*ft_malloc(ssize_t len);
char	**ft_split(char const *s, char c);

#endif