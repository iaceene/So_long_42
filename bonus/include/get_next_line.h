/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:57:15 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/17 15:54:17 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

char	*get_next_line(int fd);
char	*ft_join(char *s1, char *s2);
int		ft_strlen(char *s);
char	*ft_sub(char *s);
char	*ft_strdup(char *s);

#endif