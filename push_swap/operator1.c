/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:46:12 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 18:35:54 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	int	num1;
	int	num2;

	num1 = get_front(a);
	pop_head(a);
	num2 = get_front(a);
	pop_head(a);
	push_front(a, num1);
	push_front(a, num2);
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	int	num1;
	int	num2;

	num1 = get_front(b);
	pop_head(b);
	num2 = get_front(b);
	pop_head(b);
	push_front(b, num1);
	push_front(b, num2);
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	int	num1;
	int	num2;

	num1 = get_front(a);
	pop_head(a);
	num2 = get_front(a);
	pop_head(a);
	push_front(a, num1);
	push_front(a, num2);
	num1 = get_front(b);
	pop_head(b);
	num2 = get_front(b);
	pop_head(b);
	push_front(b, num1);
	push_front(b, num2);
	write(1, "ss\n", 3);
}

void	pa(t_deque *a, t_deque *b)
{
	int	num;

	if (is_empty(b))
		return ;
	num = get_front(b);
	pop_head(b);
	push_front(a, num);
	write(1, "pa\n", 3);
}

void	pb(t_deque *a, t_deque *b)
{
	int	num;

	if (is_empty(a))
		return ;
	num = get_front(a);
	pop_head(a);
	push_front(b, num);
	write(1, "pb\n", 3);
}
