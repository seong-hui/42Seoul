/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:19:04 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/26 17:02:02 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i - g->width] == 'C')
		g->clt_cnt++;
	if (g->map_str[i - g->width] == 'E' && g->c == g->clt_cnt)
		clear_game(g);
	else if (g->map_str[i - g->width] != '1' && g->map_str[i - g->width] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i - g->width] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		make_map(g);
	}
}

void	move_a(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i - 1] == 'C')
		g->clt_cnt++;
	if (g->map_str[i - 1] == 'E' && g->c == g->clt_cnt)
		clear_game(g);
	else if (g->map_str[i - 1] != '1' && g->map_str[i - 1] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i - 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		make_map(g);
	}
}

void	move_s(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i + g->width] == 'C')
		g->clt_cnt++;
	if (g->map_str[i + g->width] == 'E' && g->c == g->clt_cnt)
		clear_game(g);
	else if (g->map_str[i + g->width] != '1' && g->map_str[i + g->width] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i + g->width] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		make_map(g);
	}
}

void	move_d(t_game *g)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(g->map_str))
	{
		if (g->map_str[i] == 'P')
			break ;
	}
	if (g->map_str[i + 1] == 'C')
		g->clt_cnt++;
	if (g->map_str[i + 1] == 'E' && g->c == g->clt_cnt)
		clear_game(g);
	else if (g->map_str[i + 1] != '1' && g->map_str[i + 1] != 'E')
	{
		g->map_str[i] = '0';
		g->map_str[i + 1] = 'P';
		g->walk_cnt++;
		printf("%d\n", g->walk_cnt);
		make_map(g);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		move_w(game);
	else if (keycode == KEY_S)
		move_s(game);
	else if (keycode == KEY_A)
		move_a(game);
	else if (keycode == KEY_D)
		move_d(game);
	else if (keycode == KEY_ESC)
		exit_game(game);
	else if (keycode == PRESS_RED_BUTTON)
		exit_game(game);
	return (0);	
}
