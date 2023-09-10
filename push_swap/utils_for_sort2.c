/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_for_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:27:36 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/23 16:30:51 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_b_top(t_deque *b, int n)
{
	t_node	*node;
	int		i;

	i = 0;
	node = b->head;
	while (i < n)
	{
		node = node->next;
		i++;
	}
	return (node->data);
}

void	sort_order_a(t_deque *deq, int n)
{
	int	i;

	i = 0;
	if (n > deq->size / 2)
	{
		n = deq->size - n;
		while (i < n)
		{
			rra(deq);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			ra(deq);
			i++;
		}
	}
}

void	sort_order_b(t_deque *deq, int n)
{
	int	i;

	i = 0;
	if (n > deq->size / 2)
	{
		n = deq->size - n;
		while (i < n)
		{
			rrb(deq);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			rb(deq);
			i++;
		}
	}
}
