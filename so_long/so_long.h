/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:46:18 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/09 16:22:18 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include "./mlx/mlx.h"
# include <fcntl.h>

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
}	t_game;

typedef struct s_check
{
	int	*visited;
	int	c;
	int	vaild_path;
}	t_check;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif
# ifndef MAX_WIDTH
#  define MAX_WIDTH		2560
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT	1344
# endif

# define KEY_ESC			53
# define KEY_W				13
# define KEY_S				1
# define KEY_A				0
# define KEY_D				2
# define PRESS_RED_BUTTON	17

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
int		make_map1(t_game *game);
int		make_map2(t_game *game);
int		clear_game(t_game *game);
void	*ft_memset(void *b, int c, int len);
char	*ft_strdup_for_map(char *s1);
int		init_check(t_check *check, t_game *game);
void	dfs(t_game *game, t_check *check, int p_index);
int		print_error(char *str);
void	ft_putnbr(int nb);
int		print_error2(char *str, t_game *game, t_check *check);
int		check_map_size(t_game *game);
int		ft_strlen_for_map(char *s);
#endif