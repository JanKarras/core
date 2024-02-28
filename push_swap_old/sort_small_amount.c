/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_amount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:57:46 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/07 17:57:11 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_numbers(t_list **stack_a)
{
	if (*((*stack_a)->content) > *((*stack_a)->next->content))
		sa(*stack_a);
}

void	sort_three_numbers(t_list **stack_a)
{
	int		min;
	int		max;

	min = 2147483647;
	max = -2147483648;
	get_min_max(*stack_a, &min, &max);
	if (get_pos(*stack_a, min) == 1 && get_pos(*stack_a, max) == 2)
		sa(*stack_a);
	if (get_pos(*stack_a, min) == 2 && get_pos(*stack_a, max) == 0)
	{
		sa(*stack_a);
		rra(stack_a);
	}
	if (get_pos(*stack_a, min) == 1 && get_pos(*stack_a, max) == 0)
		ra(stack_a);
	if (get_pos(*stack_a, min) == 0 && get_pos(*stack_a, max) == 1)
	{
		sa(*stack_a);
		ra(stack_a);
	}
	if (get_pos(*stack_a, min) == 2 && get_pos(*stack_a, max) == 1)
		rra(stack_a);
}

void	sort_four_numbers(t_list **stack_a, t_list **stack_b)
{
	int		pivot;

	if (get_pivot(*stack_a, &pivot) == 2)
		return ;
	split_stacks(stack_a, stack_b, pivot);
	sort_two_numbers(stack_a);
	if (*((*stack_b)->content) < *((*stack_b)->next->content))
		sb(*stack_b);
	while (ft_lstsize(*stack_b) != 0)
		pa(stack_a, stack_b);
}

void	sort_five_number(t_list **stack_a, t_list **stack_b)
{
	int		pivot;

	if (get_pivot(*stack_a, &pivot) == 2)
		return ;
	split_stacks(stack_a, stack_b, pivot);
	sort_three_numbers(stack_a);
	if (*((*stack_b)->content) < *((*stack_b)->next->content))
		sb(*stack_b);
	while (*stack_b != NULL)
		pa(stack_a, stack_b);
}

int	sort_small_amount(t_list **stack_a, t_list **stack_b)
{
	if (check_stack_a(*stack_a) == 0)
		return (1);
	else if (ft_lstsize(*stack_a) == 2)
		sort_two_numbers(stack_a);
	else if (ft_lstsize(*stack_a) == 3)
		sort_three_numbers(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		sort_four_numbers(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		sort_five_number(stack_a, stack_b);
	return (1);
}
