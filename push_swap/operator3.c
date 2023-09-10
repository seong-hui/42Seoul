/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:35:42 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/16 18:36:10 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_deque *a, t_deque *b)
{
	int	num;

	num = get_back(a);
	pop_back(a);
	push_front(a, num);
	num = get_back(b);
	pop_back(b);
	push_front(b, num);
	write(1, "rrr\n", 4);
}
