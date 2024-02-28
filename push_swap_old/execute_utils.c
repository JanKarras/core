/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:57:09 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:06:11 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ra_rra(t_list *stack_a, int nb, int *ra, int *rra)
{
	int	pos;

	*ra = 0;
	*rra = 0;
	pos = get_pos(stack_a, nb);
	if (pos <= ft_lstsize(stack_a) / 2)
		*ra = pos;
	else
		*rra = ft_lstsize(stack_a) - pos;
}

void	exe_rr(int *a_count, int *b_count, t_list **st_a, t_list **st_b)
{
	if (*a_count < *b_count)
	{
		*b_count = *b_count - *a_count;
		while ((*a_count)-- != 0)
			rr(st_a, st_b);
	}
	else if (*a_count > *b_count)
	{
		*a_count = *a_count - *b_count;
		while ((*b_count)-- != 0)
			rr(st_a, st_b);
	}
	else
	{
		while ((*b_count)-- != 0)
			rr(st_a, st_b);
		*a_count = 0;
	}
}

void	exe_rrr(int *a_count, int *b_count, t_list **st_a, t_list **st_b)
{
	if (*a_count < *b_count)
	{
		*b_count = *b_count - *a_count;
		while ((*a_count)-- != 0)
			rrr(st_a, st_b);
	}
	else if (*a_count > *b_count)
	{
		*a_count = *a_count - *b_count;
		while ((*b_count)-- != 0)
			rrr(st_a, st_b);
	}
	else
	{
		while ((*b_count)-- != 0)
			rrr(st_a, st_b);
		*a_count = 0;
	}
}

void	exe_rest_r(int a_count, int b_count, t_list **st_a, t_list **st_b)
{
	while (a_count > 0)
	{
		ra(st_a);
		a_count--;
	}
	while (b_count > 0)
	{
		rb(st_b);
		b_count--;
	}
}

void	exe_rest_rr(int a_count, int b_count, t_list **st_a, t_list **st_b)
{
	while (a_count > 0)
	{
		rra(st_a);
		a_count--;
	}
	while (b_count > 0)
	{
		rrb(st_b);
		b_count--;
	}
}
