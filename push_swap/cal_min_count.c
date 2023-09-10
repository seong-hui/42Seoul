/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_min_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:51:58 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/23 17:22:40 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	b_top_middle_count(t_deque *a, int b_top)
{
	int		i;
	t_node	*node;

	node = a->head;
	i = 1;
	if (get_front(a) > b_top && get_back(a) < b_top)
		return (0);
	while (node->next)
	{
		if (node->data < b_top && node->next->data > b_top)
			break ;
		node = node->next;
		i++;
	}
	if (i > a->size / 2)
		i = a->size - i;
	return (i);
}

int	b_top_largest_count(t_deque *a)
{
	int	n;

	n = find_smallest_index(a);
	if (n > a->size / 2)
		n = a->size - n;
	return (n);
}

int	small_index(int i, int cal, t_deque *b)
{
	if (i > b->size / 2)
			cal += b->size - i;
	else
		cal += i;
	return (cal);
}

int	count_sum(t_deque *a, t_deque *b, int min)
{
	int		cal;
	int		i;
	int		index;
	t_node	*node_b;

	index = 0;
	i = 0;
	node_b = b->head;
	while (node_b)
	{
		if (find_max_a(a) < node_b->data || find_min_a(a) > node_b->data)
			cal = b_top_largest_count(a);
		else
			cal = b_top_middle_count(a, node_b->data);
		cal = small_index(i, cal, b);
		if (cal < min)
		{
			min = cal;
			index = i;
		}
		i++;
		node_b = node_b->next;
	}
	return (index);
}
