/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:37 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/09 17:46:18 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *map, t_game *game)
{
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strdup_for_map(line);
		game->map_str = ft_strjoin(game->map_str, tmp);
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	read_size(char *map, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen_for_map(line);
	game->height = 1;
	free(line);
	line = get_next_line(fd);
	while (line)
	{
		if ((ft_strlen_for_map(line)) != game->width)
		{
			game->width = -1;
			free(line);
			close(fd);
			return ;
		}
		game->height += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

void	set_map(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64, game->height * 64,
			"so_long");
	game->clt_cnt = 0;
	game->walk_cnt = 0;
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "./textures/empty.xpm",
			&width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./textures/wall.xpm",
			&width, &height);
	game->clt_img = mlx_xpm_file_to_image(game->mlx, "./textures/clt.xpm",
			&width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./textures/player.xpm",
			&width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./textures/exit.xpm",
			&width, &height);
}

int	read_file(char *map)
{
	int	fd;
	int	len;

	len = ft_strlen(map);
	if (len < 5 || map[len - 1] != 'r'
		|| map[len - 2] != 'e'
		|| map[len - 3] != 'b'
		|| map[len - 4] != '.')
		return (print_error("Error : Invalid extension\n"));
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (print_error("Error : Failed to open file\n"));
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_check	check;
	int		p_index;

	if (ac != 2)
		return (1);
	if (read_file(av[1]))
		return (1);
	read_size(av[1], &game);
	if (check_map_size(&game))
		return (1);
	read_map(av[1], &game);
	if (check_map(&game))
		return (1);
	p_index = init_check(&check, &game);
	dfs(&game, &check, p_index);
	if (!check.vaild_path || check.c != game.c)
		return (print_error2("Error : There is no valid path\n", &game, &check));
	set_map(&game);
	mlx_loop_hook(game.mlx, &make_map2, &game);
	mlx_key_hook(game.win, &key_press, &game);
	mlx_hook(game.win, PRESS_RED_BUTTON, 0, &exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
