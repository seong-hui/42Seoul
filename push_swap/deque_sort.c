/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 17:08:46 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 19:52:44 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_deque *a)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = a -> head-> data;
	n2 = a -> head ->next-> data;
	n3 = a -> head -> next ->next-> data;
	if (n1 < n2 && n2 < n3)
		return ;
	else if (n1 < n2 && n1 < n3)
	{
		sa(a);
		ra(a);
	}
	else if (n1 < n2 && n2 > n3)
		rra(a);
	else if (n1 > n2 && n1 < n3)
		sa(a);
	else
	{
		ra(a);
		if (n2 > n3)
			sa(a);
	}
}

int	find_min_idx(t_deque *a)
{
	t_node	*node;
	int		i;
	int		min;
	int		min_idx;

	node = a->head;
	min = node -> data;
	i = 0;
	min_idx = 0;
	while (node)
	{
		if (min > node ->data)
		{
			min = node -> data;
			min_idx = i;
		}
		i++;
		node = node -> next;
	}
	return (min_idx);
}

void	sort_five_min(t_deque *a)
{
	int	idx;

	idx = find_min_idx(a);
	if (idx == 1)
		sa(a);
	else if (idx == 2)
	{
		ra(a);
		ra(a);
	}
	else if (idx == 3)
	{
		rra(a);
		rra(a);
	}
	else if (idx == 4)
		rra(a);
	return ;
}

void	sort_four_min(t_deque *a)
{
	int	idx;

	idx = find_min_idx(a);
	if (idx == 1)
		sa(a);
	else if (idx == 2)
	{
		ra(a);
		ra(a);
	}
	else if (idx == 3)
		rra(a);
	return ;
}

void	sort_five(t_deque *a, t_deque *b)
{
	if (a->size == 5)
	{
		sort_five_min(a);
		pb(a, b);
	}
	if (a->size == 4)
	{
		sort_four_min(a);
		pb(a, b);
	}
}
