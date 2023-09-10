/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_info1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:14:40 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/22 20:29:35 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_deque(t_deque *deque)
{
	deque -> head = NULL;
	deque -> tail = NULL;
	deque -> size = 0;
}

int	is_empty(t_deque *deque)
{
	return (deque->head == NULL);
}

int	push_front(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node -> data = data;
	node -> next = deque -> head;
	node -> prev = NULL;
	if (is_empty(deque))
		deque -> tail = node;
	else
		deque->head->prev = node;
	deque -> head = node;
	deque -> size++;
	return (1);
}

int	push_back(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node -> data = data;
	node->prev = deque->tail;
	node -> next = NULL;
	if (is_empty(deque))
		deque -> head = node;
	else
		deque->tail->next = node;
	deque -> tail = node;
	deque -> size++;
	return (1);
}
