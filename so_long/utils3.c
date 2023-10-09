/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:06:35 by seonghmo          #+#    #+#             */
/*   Updated: 2023/10/09 16:10:44 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_error(char *str)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	return (1);
}

int	print_error2(char *str, t_game *game, t_check *check)
{
	int	len;

	len = ft_strlen(str);
	write(2, str, len);
	free(game->map_str);
	free(check->visited);
	return (1);
}

int	ft_strlen_for_map(char *s)
{
	int	len;

	len = 0;
	while (s && s[len] && s[len] != '\n')
		len++;
	return (len);
}
