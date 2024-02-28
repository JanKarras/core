/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:56:34 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/31 14:57:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_big_small(t_list **st_a, t_list **st_b, int nb)
{
	int	rb_count;
	int	rrb_count;
	int	ra_count;
	int	rra_count;

	rb_count = 0;
	rrb_count = 0;
	get_ra_rra(*st_a, nb, &ra_count, &rra_count);
	if (get_pos(*st_b, get_max(*st_b)) <= ft_lstsize(*st_b) / 2)
		rb_count = get_pos(*st_b, get_max(*st_b));
	else
		rrb_count = ft_lstsize(*st_b) - get_pos(*st_b, get_max(*st_b));
	if (ra_count != 0 && rb_count != 0)
		exe_rr(&ra_count, &rb_count, st_a, st_b);
	if (rra_count != 0 && rrb_count != 0)
		exe_rrr(&rra_count, &rrb_count, st_a, st_b);
	exe_rest_r(ra_count, rb_count, st_a, st_b);
	exe_rest_rr(rra_count, rrb_count, st_a, st_b);
}

void	execute_middle(t_list **stack_a, t_list **stack_b, int nb)
{
	int	rb_count;
	int	rrb_count;
	int	next_smaller;
	int	ra_count;
	int	rra_count;

	rb_count = 0;
	rrb_count = 0;
	get_next_b_s(&rra_count, &next_smaller, *stack_b, nb);
	if (get_pos(*stack_b, next_smaller) <= ft_lstsize(*stack_b) / 2)
		rb_count = get_pos(*stack_b, next_smaller);
	else
		rrb_count = ft_lstsize(*stack_b) - get_pos(*stack_b, next_smaller);
	get_ra_rra(*stack_a, nb, &ra_count, &rra_count);
	if (ra_count != 0 && rb_count != 0)
		exe_rr(&ra_count, &rb_count, stack_a, stack_b);
	if (rra_count != 0 && rrb_count != 0)
		exe_rrr(&rra_count, &rrb_count, stack_a, stack_b);
	exe_rest_r(ra_count, rb_count, stack_a, stack_b);
	exe_rest_rr(rra_count, rrb_count, stack_a, stack_b);
}

void	execute(t_list **stack_a, t_list **stack_b, int i)
{
	int		nb;
	t_list	*tmp;
	int		min;
	int		max;

	tmp = *stack_a;
	nb = 0;
	while (tmp != NULL)
	{
		if (nb == i)
		{
			nb = *tmp->content;
			break ;
		}
		nb++;
		tmp = tmp->next;
	}
	get_min_max(*stack_b, &min, &max);
	if (*tmp->content > max || *tmp->content < min)
		execute_big_small(stack_a, stack_b, nb);
	else
		execute_middle(stack_a, stack_b, nb);
	pb(stack_a, stack_b);
}
