/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   making_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:09:22 by seonghmo          #+#    #+#             */
/*   Updated: 2023/10/09 16:10:18 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	make_map1(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->empty_img,
				j * 64, i * 64);
			if (game->map_str[i * game->width + j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
					j * 64, i * 64);
			else if (game->map_str[i * game->width + j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->clt_img,
					j * 64, i * 64);
			else if (game->map_str[i * game->width + j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img,
					j * 64, i * 64);
		}
	}
	return (0);
}

int	make_map2(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	if (game->walk_cnt == 0)
		make_map1(game);
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map_str[i * game->width + j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img,
					j * 64, i * 64);
		}
	}
	return (0);
}
