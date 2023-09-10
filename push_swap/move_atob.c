/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_atob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:49:18 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 19:38:07 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	atob_1(t_deque *a, t_deque *b, int len)
{
	int	l1;
	int	i;

	i = 0;
	l1 = len / 3 * 2;
	while (i < len)
	{
		if (get_front(a) >= l1)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	atob_2(t_deque *a, t_deque *b, int len)
{
	int	l1;
	int	len_a;
	int	i;

	i = 0;
	l1 = len / 3;
	len_a = a->size;
	while (i < len_a)
	{
		if (get_front(a) >= l1)
			pb(a, b);
		else
			ra(a);
		i++;
	}
}

void	atob_3(t_deque *a, t_deque *b)
{
	while (a->size > 3)
		pb(a, b);
}

void	sort_atob(t_deque *a, t_deque *b)
{
	int	len;

	len = a->size;
	if (len > 5)
	{
		atob_1(a, b, len);
		atob_2(a, b, len);
		atob_3(a, b);
	}
	else if (len > 3)
		sort_five(a, b);
	if (a->size == 3)
		sort_three(a);
}
