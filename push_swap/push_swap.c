/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:43:14 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/22 21:13:22 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_deque(char *input)
{
	t_deque	a;
	t_deque	b;
	int		*tmp;

	init_deque(&a);
	init_deque(&b);
	push_d(&a, input);
	tmp = sort(make_tmp(&a), &a);
	index_deque(&a, tmp);
	free(tmp);
	sort_atob(&a, &b);
	sort_btoa(&a, &b);
	sort_final(&a);
	free_deque(&a);
	free_deque(&b);
	free(input);
}

int	validation(char *input)
{
	int	check;

	if (!input[0])
		return (0);
	check = check_num(input);
	if (check == -1)
	{
		free(input);
		return (print_error());
	}
	else if (check == -2)
	{
		free(input);
		return (0);
	}
	return (1);
}

void	parsing(int ac, char **av, char **input)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	*input = ft_strdup("");
	if (!*input)
		exit(1);
	while (++i < ac)
	{
		tmp = ft_strjoin(av[i], " ");
		if (!tmp)
			exit(1);
		tmp2 = *input;
		*input = ft_strjoin(*input, tmp);
		if (!*input)
			exit(1);
		free(tmp2);
		free(tmp);
	}
}

int	main(int ac, char **av)
{
	char	*input;

	if (ac < 2)
		return (0);
	else
		parsing(ac, av, &input);
	if (validation(input) == 1)
		make_deque(input);
	return (0);
}
