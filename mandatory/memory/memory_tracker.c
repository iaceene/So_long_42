/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_tracker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:27:12 by yaajagro          #+#    #+#             */
/*   Updated: 2025/01/13 16:37:38 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free(t_gb **head)
{
	t_gb	*tmp;

	if (!head)
		return ;
	while ((*head))
	{
		tmp = (*head)->next;
		free((*head)->ptr);
		free((*head));
		(*head) = tmp;
	}
	*head = NULL;
}

t_gb	*ft_new_addr(void *add)
{
	t_gb	*ret;

	ret = malloc(sizeof(t_gb));
	if (!ret)
		return (NULL);
	ret->ptr = add;
	ret->next = NULL;
	return (ret);
}

t_gb	*ft_last_addr(t_gb *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

void	ft_add_new(t_gb **head, t_gb *new)
{
	t_gb	*last;

	if (!head || !new)
		return ;
	if (!*head)
		*head = new;
	else
	{
		last = ft_last_addr(*head);
		last->next = new;
	}
}

void	*ft_malloc(size_t len, int flag)
{
	static t_gb	*head;
	void		*ptr;

	if (flag == 1)
	{
		ft_free(&head);
		return (NULL);
	}
	ptr = malloc(len);
	if (!ptr)
	{
		ft_free(&head);
		exit(1);
	}
	ft_add_new(&head, ft_new_addr(ptr));
	return (ptr);
}
