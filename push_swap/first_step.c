/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 18:39:48 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/22 20:21:12 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_d(t_deque *deque, char *input)
{
	char	**push_num;
	int		i;

	i = 0;
	push_num = ft_split(input, ' ');
	if (!push_num)
		exit(1);
	while (push_num[i])
	{
		push_back(deque, ft_atoi(push_num[i]));
		i++;
	}
	free_arr(push_num);
}

int	*make_tmp(t_deque *a)
{
	int		len;
	int		*tmp;
	t_node	*node;
	int		i;

	len = a->size;
	tmp = (int *)malloc(sizeof(int) * len);
	if (!tmp)
		exit(1);
	i = 0;
	node = a->head;
	while (node)
	{
		tmp[i] = node->data;
		node = node-> next;
		i++;
	}
	return (tmp);
}

int	*sort(int *tmp, t_deque *a)
{
	int	i;
	int	j;
	int	len;
	int	n;

	len = a->size;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (tmp[j] > tmp[j + 1])
			{
				n = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = n;
			}
			j++;
		}
		i++;
	}
	return (tmp);
}

void	index_deque(t_deque *a, int *tmp)
{
	int		i;
	t_node	*node;

	node = a->head;
	while (node)
	{
		i = 0;
		while (i < a->size)
		{
			if (node->data == tmp[i])
			{
				node->data = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}
