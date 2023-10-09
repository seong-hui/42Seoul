/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:19:04 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/09 15:54:23 by seonghmo         ###   ########.fr       */
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
		ft_putnbr(g->walk_cnt);
		write(1, "\n", 1);
		make_map1(g);
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
		ft_putnbr(g->walk_cnt);
		write(1, "\n", 1);
		make_map1(g);
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
		ft_putnbr(g->walk_cnt);
		write(1, "\n", 1);
		make_map1(g);
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
		ft_putnbr(g->walk_cnt);
		write(1, "\n", 1);
		make_map1(g);
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
	return (0);
}
