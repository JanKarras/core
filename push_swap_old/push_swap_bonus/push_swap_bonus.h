/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:30 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/06 20:28:37 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"
# include "./get_next_line_bonus/get_next_line.h"

int		check(t_list **stack_a, t_list **stack_b);
int		ft_strcmp_bonus(char *s1, char *s2);
char	**get_functions_array(void);
void	sa_bonus(t_list *list);
void	sb_bonus(t_list *list);
void	ss_bonus(t_list *stack_a, t_list *stack_b);
void	pa_bonus(t_list **stack_a, t_list **stack_b);
void	pb_bonus(t_list **stack_a, t_list **stack_b);
void	ra_bonus(t_list **stack_a);
void	rb_bonus(t_list **stack_b);
void	rr_bonus(t_list **stack_a, t_list **stack_b);
void	rra_bonus(t_list **stack_a);
void	rrb_bonus(t_list **stack_b);
void	rrr_bonus(t_list **stack_a, t_list **stack_b);
void	free_argv_bonus(char **argv);
int		ft_check_double(int nb, char **argv, int i);
int		ft_isnum(char *nb);
void	ft_check_args(int argc, char **argv, int *flag);
t_list	*create_new_node(int nb);

#endif
