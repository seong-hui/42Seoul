/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:01:21 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/09 16:07:36 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall_row(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map_str[i * game->width + j] != '1')
				return (1);
			j++;
		}
		i += (game->height - 1);
	}
	return (0);
}

int	check_wall_col(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->width)
	{
		j = 0;
		while (j < game->height)
		{
			if (game->map_str[j * game->width + i] != '1')
				return (1);
			j++;
		}
		i += (game->width - 1);
	}
	return (0);
}

int	essential(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map_str[i * game->width + j] == 'C')
				game->c++;
			else if (game->map_str[i * game->width + j] == 'P')
				game->p++;
			else if (game->map_str[i * game->width + j] == 'E')
				game->e++;
			else if (game->map_str[i * game->width + j] != '0'
				&& game->map_str[i * game->width + j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	if (game->p != 1 || game->c < 1 || game->e != 1)
		return (1);
	return (0);
}

int	check_map(t_game *game)
{
	game->c = 0;
	game->e = 0;
	game->p = 0;
	if (check_wall_row(game) || check_wall_col(game))
	{
		free(game->map_str);
		return (print_error("Error : Map is not surrounded by walls\n"));
	}
	if (essential(game))
	{
		free(game->map_str);
		return (print_error("Error : Map requirements are not met\n"));
	}
	return (0);
}
