/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonghmo <seonghmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:22:33 by seonghmo          #+#    #+#             */
/*   Updated: 2023/07/23 17:24:07 by seonghmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_deque;

void	init_deque(t_deque *deque);
int		is_empty(t_deque *deque);
int		push_front(t_deque *deque, int data);
int		push_back(t_deque *deque, int data);
void	pop_head(t_deque *deque);
void	pop_back(t_deque *deque);
int		get_front(t_deque *deque);
int		get_back(t_deque *deque);
void	free_deque(t_deque *deque);
int		ft_strlen(const char *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
int		check_num(char *str);
void	sa(t_deque *deque_a);
void	sb(t_deque *deque_b);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rrr(t_deque *a, t_deque *b);
void	sort_three(t_deque *a);
void	sort_five(t_deque *a, t_deque *b);
void	atob_1(t_deque *a, t_deque *b, int len);
void	atob_2(t_deque *a, t_deque *b, int len);
void	atob_3(t_deque *a, t_deque *b);
void	sort_atob(t_deque *a, t_deque *b);
void	sort_btoa(t_deque *a, t_deque *b);
void	sort_final(t_deque *a);
void	push_d(t_deque *deque, char *input);
void	index_deque(t_deque *a, int *tmp);
int		*sort(int *tmp, t_deque *a);
int		print_error(void);
int		*make_tmp(t_deque *a);
int		find_min_a(t_deque *a);
int		find_max_a(t_deque *a);
int		count_sum(t_deque *a, t_deque *b, int min);
int		find_smallest_index(t_deque *a);
void	sort_order_a(t_deque *deq, int n);
void	sort_order_b(t_deque *deq, int n);
void	free_arr(char **arr);
int		free_arr1(char **arr);
int		free_arr2(char **arr);
int		free_all(char *check, char **nums);
void	sort_order_ab1(t_deque *a, t_deque *b, int a_n, int b_n);
void	sort_order_ab2(t_deque *a, t_deque *b, int a_n, int b_n);
int		get_b_top(t_deque *b, int n);

#endif