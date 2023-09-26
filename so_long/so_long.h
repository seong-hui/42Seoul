/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:46:18 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/09/26 17:06:31 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
    int		height;
    int		width;
	char	*map_str;
	void	*empty_img;
	void	*wall_img;
	void	*clt_img;
	void	*player_img;
	void	*exit_img;
	int		c;
	int		e;
	int		p;
	int		clt_cnt;
	int		walk_cnt;
    
}   t_game;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#define KEY_ESC				53
#define KEY_W				13
#define KEY_S				1
#define KEY_A				0
#define KEY_D				2
#define PRESS_RED_BUTTON	17

char	*get_next_line(int fd);
char	*allget(int fd, char *backup);
char	*parsing(char *backup);
char	*after_gnl(char *backup);
int		ft_strlen(char *s);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char*s2);
char	*ft_strchr(char *s, int c);
char	*ft_free(char **s);
int		check_map(t_game *game);
int		key_press(int keycode, t_game *game);
int		exit_game(t_game *game);
int		make_map(t_game *game);
int		clear_game(t_game *game);

#endif