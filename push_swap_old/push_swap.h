/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:56:03 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/06 21:02:39 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdbool.h>

void	free_argv_bonus(char **argv);
int		ft_check_double(int nb, char **argv, int i);
int		ft_isnum(char *nb);
void	ft_check_args(int argc, char **argv, int *flag);
t_list	*create_new_node(int nb);
int		ft_strcmp(char *s1, char *s2);
int		sort(t_list **stack_a, t_list **stack_b);
void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *stack_a, t_list *stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
int		sort_small_amount(t_list **stack_a, t_list **stack_b);
int		check_stack_a(t_list *stack_a);
int		split_stacks(t_list **stack_a, t_list **stack_b, int pivot);
int		get_pivot(t_list *stack_a, int *pivot);
void	sort_big_amount(t_list **stack_a, t_list **stack_b);
//getter utils
void	get_min_max(t_list *stack, int *min, int *max);
int		get_pos(t_list *stack_a, int min);
int		get_min(t_list *stack_a);
int		get_max(t_list *stack_a);
void	get_next_b_s(int *bigger, int *smaller, t_list *stack_b, int nb);
//get calls
int		get_calls(t_list *stack_a, t_list	*stack_b, t_list *temp);
int		get_calls_middle(t_list *stack_b, int nb, int ra_count, int rra_count);
int		get_calls_small_big(t_list *st_b, int ra_count, int rra_count);
void	get_rr_rrr_calls(int *a_count, int *b_count);
//execute
void	execute_big_small(t_list **st_a, t_list **st_b, int nb);
void	execute_middle(t_list **stack_a, t_list **stack_b, int nb);
void	execute(t_list **stack_a, t_list **stack_b, int i);
//execute utils
void	exe_rest_rr(int a_count, int b_count, t_list **st_a, t_list **st_b);
void	exe_rest_r(int a_count, int b_count, t_list **st_a, t_list **st_b);
void	exe_rrr(int *a_count, int *b_count, t_list **st_a, t_list **st_b);
void	exe_rr(int *a_count, int *b_count, t_list **st_a, t_list **st_b);
void	get_ra_rra(t_list *stack_a, int nb, int *ra, int *rra);
#endif
