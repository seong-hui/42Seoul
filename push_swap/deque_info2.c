/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_info2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:28:07 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/22 20:24:19 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pop_head(t_deque *deque)
{
	t_node	*head_node;

	if (is_empty(deque))
		return ;
	head_node = deque -> head;
	if (head_node->next == NULL)
		deque -> tail = NULL;
	else
		deque->head->next->prev = NULL;
	deque -> head = deque-> head-> next;
	deque -> size--;
	free(head_node);
}

void	pop_back(t_deque *deque)
{
	t_node	*tail_node;

	if (is_empty(deque))
		return ;
	tail_node = deque->tail;
	if (tail_node->prev == NULL)
		deque -> head = NULL;
	else
		deque->tail->prev->next = NULL;
	deque->tail = deque->tail->prev;
	deque -> size--;
	free(tail_node);
}

int	get_front(t_deque *deque)
{
	if (is_empty(deque))
		return (-1);
	return (deque->head->data);
}

int	get_back(t_deque *deque)
{
	if (is_empty(deque))
		return (-1);
	return (deque->tail->data);
}

void	free_deque(t_deque *deque)
{
	while (deque->head != NULL)
		pop_back(deque);
}
