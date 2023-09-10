/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_btoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:50:56 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/23 17:21:30 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_ways(t_deque *a, t_deque *b, int a_n, int b_n)
{
	if (a_n > a->size / 2 && b_n > b->size / 2)
		sort_order_ab1(a, b, a_n, b_n);
	else if (a_n < a->size / 2 && b_n < b->size / 2)
		sort_order_ab2(a, b, a_n, b_n);
	else
	{
		if (b_n == 1)
			sb(b);
		else
			sort_order_b(b, b_n);
		sort_order_a(a, a_n);
	}
}

void	b_top_largest(t_deque *a, t_deque *b, int b_n)
{
	int	a_n;

	a_n = find_smallest_index(a);
	sort_ways(a, b, a_n, b_n);
	pa (a, b);
}

void	b_top_middle(t_deque *a, t_deque *b, int n)
{
	int		b_top;
	int		i;
	t_node	*node;

	b_top = get_b_top(b, n);
	node = a->head;
	i = 1;
	if (get_front(a) > b_top && get_back(a) < b_top)
	{	
		sort_order_b(b, n);
		pa(a, b);
		return ;
	}
	while (node->next)
	{
		if (node->data < b_top && node->next->data > b_top)
			break ;
		node = node->next;
		i++;
	}
	sort_ways(a, b, i, n);
	pa (a, b);
}

void	sort_btoa(t_deque *a, t_deque *b)
{
	int	n;
	int	b_top;

	while (b->size)
	{
		n = count_sum(a, b, 100);
		b_top = get_b_top(b, n);
		if (find_max_a(a) < b_top || find_min_a(a) > b_top)
			b_top_largest(a, b, n);
		else
			b_top_middle(a, b, n);
	}
}

void	sort_final(t_deque *a)
{
	int	n;

	n = find_smallest_index(a);
	sort_order_a(a, n);
}
