/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:18:01 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/23 16:30:46 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_a(t_deque *a)
{
	t_node	*node_a;
	int		min;

	node_a = a->head;
	min = node_a->data;
	while (node_a)
	{
		if (node_a-> data < min)
			min = node_a->data;
		node_a = node_a->next;
	}
	return (min);
}

int	find_max_a(t_deque *a)
{
	t_node	*node_a;
	int		max;

	node_a = a->head;
	max = node_a->data;
	while (node_a)
	{
		if (node_a-> data > max)
			max = node_a->data;
		node_a = node_a->next;
	}
	return (max);
}

int	find_smallest_index(t_deque *a)
{
	int		i;
	t_node	*node;

	i = 0;
	node = a->head;
	while (node)
	{
		if (node-> data == find_min_a(a))
			return (i);
		i++;
		node = node->next;
	}
	return (i);
}

void	sort_order_ab1(t_deque *a, t_deque *b, int a_n, int b_n)
{
	int	i;

	i = 0;
	a_n = a->size - a_n;
	b_n = b->size - b_n;
	while (i < a_n && i < b_n)
	{
		rrr(a, b);
		i++;
	}
	if (a_n > b_n)
	{
		while (i++ < a_n)
			rra(a);
	}
	else
	{
		while (i++ < b_n)
			rrb(b);
	}
}

void	sort_order_ab2(t_deque *a, t_deque *b, int a_n, int b_n)
{
	int	i;

	i = 0;
	while (i < a_n && i < b_n)
	{
		rr(a, b);
		i++;
	}
	if (a_n > b_n)
	{
		while (i++ < a_n)
			ra(a);
	}
	else
	{
		while (i++ < b_n)
			rb(b);
	}
}
