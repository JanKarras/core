/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:50:12 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:16:02 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	int	min;

	min = 2147483647;
	while (stack_a != NULL)
	{
		if (*stack_a->content < min)
			min = *stack_a->content;
		stack_a = stack_a->next;
	}
	return (min);
}

int	get_max(t_list *stack_a)
{
	int	max;

	max = -2147483647;
	while (stack_a != NULL)
	{
		if (*stack_a->content > max)
			max = *stack_a->content;
		stack_a = stack_a->next;
	}
	return (max);
}

int	get_pos(t_list *stack_a, int min)
{
	int	pos;

	pos = 0;
	while (stack_a != NULL)
	{
		if (*stack_a->content == min)
			return (pos);
		pos++;
		stack_a = stack_a->next;
	}
	return (0);
}

void	get_next_b_s(int *bigger, int *smaller, t_list *stack_b, int nb)
{
	int	diff;

	*smaller = -2147483648;
	*bigger = 2147483647;
	while (stack_b != NULL)
	{
		diff = *stack_b->content - nb;
		if (diff > 0 && *stack_b->content < *bigger)
			*bigger = *stack_b->content;
		if (diff < 0 && *stack_b->content > *smaller)
			*smaller = *stack_b->content;
		stack_b = stack_b->next;
	}
}

void	get_min_max(t_list *stack, int *min, int *max)
{
	*min = 2147483647;
	*max = -2147483648;
	while (stack != NULL)
	{
		if (*(stack->content) < *min)
			*min = *(stack->content);
		if (*(stack->content) > *max)
			*max = *(stack->content);
		stack = stack->next;
	}
}
