/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moonseonghui <moonseonghui@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:51:07 by moonseonghu       #+#    #+#             */
/*   Updated: 2023/10/08 14:25:46 by moonseonghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	clear_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
    write(1, "CLEAR GAME!\n", 12);
	exit(0);
}

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*p;
	int			i;

	i = 0;
	p = (unsigned char *)b;
	while (i < len)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

char *ft_strdup_for_map(char *s1)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(len);
	if (!p)
		return (0);
	while (s1[i] && s1[i] !='\n')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}