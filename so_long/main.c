/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:12:37 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/08 15:08:16 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

int make_map(t_game *game)
{
	int i;
	int	j;

	i = 0;
	while(i < game->height)
	{
		j = 0;
		while(j < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->empty_img, j * 64, i * 64);
			if (game->map_str[i * game->width + j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall_img, j * 64, i * 64);
			else if (game->map_str[i * game->width + j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->clt_img, j * 64, i * 64);
			else if (game->map_str[i * game->width + j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player_img, j * 64, i * 64);
			else if(game->map_str[i * game->width + j] != '0')
				mlx_put_image_to_window(game->mlx, game->win, game->exit_img, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}

int ft_strlen_for_map(char *s)
{
	int	len;

	len = 0;
	while (s && s[len] && s[len]!='\n')
		len++;
	return (len);
}

void read_map(char *map ,t_game *game)
{
	int fd;
	char *line;
	char *tmp;

	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	game->width = ft_strlen_for_map(line);
	game->height = 1;
	game->map_str = ft_strdup_for_map(line);
	free(line);
	while((line = get_next_line(fd)) != NULL)
	{
		if ((ft_strlen_for_map(line)) != game->width)
		{
			game->width = -1;
			return;
		}
		tmp = ft_strdup_for_map(line);
		game->map_str = ft_strjoin(game->map_str, tmp);
		game->height += 1;
		free(tmp);
	}
	close(fd);
}

void set_map(t_game *game)
{
	int width = 64;
	int height = 64;
	game->mlx = mlx_init();
	if (!game->mlx) {
        perror("mlx_init");
        exit(1);
    }
	game->win = mlx_new_window(game->mlx, 64 * game->width, 64 * game->height, "so_long");
	game->clt_cnt = 0;
	game->walk_cnt = 0;
	game->empty_img = mlx_xpm_file_to_image(game->mlx, "./img/empty.xpm", &width, &height);
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "./img/wall.xpm",  &width, &height);
	game->clt_img = mlx_xpm_file_to_image(game->mlx, "./img/clt.xpm",  &width, &height);
	game->player_img = mlx_xpm_file_to_image(game->mlx, "./img/player.xpm", &width, &height);
	game->exit_img = mlx_xpm_file_to_image(game->mlx, "./img/exit.xpm", &width, &height);
}

void	check_leak(void)
{
	system("leaks pipex");
}

int	main(int ac, char **av)
{
	t_game	game;
	t_check	check;
	int		p_index;

	
	if (ac != 2)
		return (1);
	read_map(av[1], &game);
	if (check_map(&game))
		return(1);
	p_index = init_check(&check, &game);
	dfs(&game, &check, p_index);
	if (!check.vaild_path || check.c != game.c)
		return(print_error("Error : There is no valid path\n"));
	set_map(&game);
	mlx_loop_hook(game.mlx, &make_map, &game);
	mlx_key_hook(game.win, &key_press, &game);
	mlx_hook(game.win, PRESS_RED_BUTTON, 0, &exit_game, &game);
	mlx_loop_hook(game.mlx, &make_map, &game);
	mlx_loop(game.mlx);
	return(0);
}
