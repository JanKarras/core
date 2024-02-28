/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_calls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:53:21 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:38:37 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rr_rrr_calls(int *a_count, int *b_count)
{
	if (*a_count < *b_count)
		*b_count = *b_count - *a_count;
	else if (*a_count > *b_count)
		*a_count = *a_count - *b_count;
	else
		*a_count = 0;
}

int	get_calls_small_big(t_list *st_b, int ra_count, int rra_count)
{
	int	rb_count;
	int	rrb_count;

	rb_count = 0;
	rrb_count = 0;
	if (get_pos(st_b, get_max(st_b)) <= ft_lstsize(st_b) / 2)
		rb_count = get_pos(st_b, get_max(st_b));
	else
		rrb_count = ft_lstsize(st_b) - get_pos(st_b, get_max(st_b));
	if (ra_count != 0 && rb_count != 0)
		get_rr_rrr_calls(&ra_count, &rb_count);
	if (rra_count != 0 && rrb_count != 0)
		get_rr_rrr_calls(&rra_count, &rrb_count);
	return (rb_count + ra_count + rrb_count + rra_count + 1);
}

int	get_calls_middle(t_list *stack_b, int nb, int ra_count, int rra_count)
{
	int	rb_count;
	int	rrb_count;
	int	next_smaller;
	int	next_bigger;

	rb_count = 0;
	rrb_count = 0;
	get_next_b_s(&next_bigger, &next_smaller, stack_b, nb);
	if (get_pos(stack_b, next_smaller) <= ft_lstsize(stack_b) / 2)
		rb_count = get_pos(stack_b, next_smaller);
	else
		rrb_count = ft_lstsize(stack_b) - get_pos(stack_b, next_smaller);
	if (ra_count != 0 && rb_count != 0)
		get_rr_rrr_calls(&ra_count, &rb_count);
	if (rra_count != 0 && rrb_count != 0)
		get_rr_rrr_calls(&rra_count, &rrb_count);
	return (rb_count + ra_count + rrb_count + rra_count + 1);
}

int	get_calls(t_list *stack_a, t_list	*stack_b, t_list *temp)
{
	int	ra_count;
	int	rra_count;
	int	pos;
	int	min;
	int	max;

	pos = get_pos(stack_a, *temp->content);
	ra_count = 0;
	rra_count = 0;
	if (pos <= ft_lstsize(stack_a) / 2)
		ra_count = pos;
	else
		rra_count = ft_lstsize(stack_a) - pos;
	get_min_max(stack_b, &min, &max);
	if (*temp->content > max || *temp->content < min)
		pos = get_calls_small_big(stack_b, ra_count, rra_count);
	else
		pos = get_calls_middle(stack_b, *temp->content, ra_count, rra_count);
	return (pos);
}
