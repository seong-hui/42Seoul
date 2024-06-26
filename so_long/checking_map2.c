/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:58:42 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/10 14:06:35 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_check(t_check *check, t_game *game)
{
	int	i;

	i = 0;
	check->c = 0;
	if (game->map_str)
	{
		check->visited
			= (int *)malloc(sizeof(int) * (ft_strlen(game->map_str)));
		if (!check->visited)
			exit(1);
		ft_memset(check->visited, 0, sizeof(int) * (ft_strlen(game->map_str)));
	}
	while (i < ft_strlen(game->map_str))
	{
		if (game->map_str[i] == 'P')
			break ;
		i++;
	}
	return (i);
}

void	dfs(t_game *game, t_check *check, int p_index)
{
	const int	moving[4] = {-game->width, -1, game->width, 1};
	int			i;
	int			index;

	check->visited[p_index] = 1;
	if (game->map_str[p_index] == 'C')
		check->c++;
	if (game->map_str[p_index] == 'E')
	{
		check->vaild_path = 1;
		return ;
	}
	i = 0;
	while (i < 4)
	{
		index = p_index + moving[i];
		if ((game->map_str[index] != '1' && !check->visited[index]))
			dfs(game, check, index);
		i++;
	}
}

int	check_map_size(t_game *game)
{
	if (game->height < 3 || game->width < 3 || game->width * 64 > MAX_WIDTH
		|| game->height * 64 > MAX_HEIGHT)
		return (print_error("Error : Invalid map\n"));
	return (0);
}
