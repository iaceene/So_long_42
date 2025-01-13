/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:36:30 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/13 14:56:49 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../mlx_linux/mlx.h"

typedef struct s_gb
{
    void *ptr;
    struct s_gb *next;
    
}t_gb;

void    *ft_malloc(size_t n);

#endif