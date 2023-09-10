/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 22:25:23 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/22 21:05:48 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_redup(char **nums, char *check, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_strcmp(nums[j], check) == 0)
			return (-1);
		j++;
	}
	return (0);
}

int	already_done(char **nums)
{
	int	i;
	int	check;

	i = 1;
	check = 1;
	while (nums[i])
	{
		if (ft_atoi(nums[i - 1]) > ft_atoi(nums[i]))
			return (check);
		i++;
	}
	return (-1);
}

int	check_num(char *str)
{
	int		i;
	char	**nums;
	char	*check;

	nums = ft_split(str, ' ');
	if (!nums)
		exit(1);
	i = -1;
	while (nums[++i])
	{
		check = ft_itoa(ft_atoi(nums[i]));
		if (!check)
			exit(1);
		if (ft_strcmp(nums[i], check) == 0)
		{
			if (check_redup(nums, nums[i], i) == -1)
				return (free_all(check, nums));
		}
		else
			return (free_all(check, nums));
		free(check);
	}
	if (i == 0 || already_done(nums) == -1)
		return (free_arr2(nums));
	return (free_arr1(nums));
}
