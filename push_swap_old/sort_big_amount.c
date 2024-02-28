/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_amount.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:53:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/07 15:52:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_smalles_amount(int *array, int size)
{
	int	i;
	int	smallest;

	i = 0;
	smallest = 2147483647;
	while (i < size)
	{
		if (array[i] < smallest)
			smallest = array[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (array[i] == smallest)
			return (i);
		i++;
	}
	return (0);
}

void	push_back(t_list *stack_a, t_list	*stack_b)
{
	int		max;
	int		min;

	get_min_max(stack_b, &min, &max);
	while (ft_lstsize(stack_b) != 0)
		pa(&stack_a, &stack_b);
	while (*stack_a->content != min)
	{
		if (get_pos(stack_a, min) <= ft_lstsize(stack_a))
			ra(&stack_a);
		else
			rra(&stack_a);
	}
}

void	sort_big_amount(t_list **stack_a, t_list	**stack_b)
{
	int		*array;
	t_list	*temp;
	int		i;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	array = (int *)malloc(sizeof(int) * ft_lstsize(*stack_a));
	if (array == NULL)
		return ;
	while (ft_lstsize(*stack_a) != 0)
	{
		temp = *stack_a;
		i = 0;
		while (temp != NULL)
		{
			array[i] = get_calls(*stack_a, *stack_b, temp);
			temp = temp->next;
			i++;
		}
		i = get_index_of_smalles_amount(array, ft_lstsize(*stack_a));
		execute(stack_a, stack_b, i);
	}
	push_back(*stack_a, *stack_b);
	free(array);
}
