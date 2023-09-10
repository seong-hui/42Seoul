/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:34:36 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 18:35:14 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	int	num;

	num = get_front(a);
	pop_head(a);
	push_back(a, num);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	int	num;

	num = get_front(b);
	pop_head(b);
	push_back(b, num);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	int	num;

	num = get_front(a);
	pop_head(a);
	push_back(a, num);
	num = get_front(b);
	pop_head(b);
	push_back(b, num);
	write(1, "rr\n", 3);
}

void	rra(t_deque *a)
{
	int	num;

	num = get_back(a);
	pop_back(a);
	push_front(a, num);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	int	num;

	num = get_back(b);
	pop_back(b);
	push_front(b, num);
	write(1, "rrb\n", 4);
}
