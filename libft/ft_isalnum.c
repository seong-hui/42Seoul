/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:43:12 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/15 19:56:59 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}
