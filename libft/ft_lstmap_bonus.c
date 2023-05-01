/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:36:46 by seonghmo          #+#    #+#             */
/*   Updated: 2023/03/23 18:33:19 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*start;
	void	*con;

	start = NULL;
	while (lst)
	{
		con = f(lst->content);
		new_node = ft_lstnew(con);
		if (!new_node)
		{
			ft_lstclear(&start, del);
			del(con);
			return (0);
		}
		ft_lstadd_back(&start, new_node);
		lst = lst->next;
	}
	return (start);
}
