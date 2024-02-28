/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:24:58 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/07 15:52:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_a(t_list *stack_a)
{
	int	flag;
	int	prev_value;

	flag = 0;
	if (stack_a == NULL)
		return (1);
	prev_value = -2147483648;
	while (stack_a != NULL)
	{
		if (*(stack_a->content) < prev_value)
		{
			flag = 1;
			break ;
		}
		prev_value = *(stack_a->content);
		stack_a = stack_a->next;
	}
	return (flag);
}

void	sort_array(int *array, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_pivot(t_list *stack_a, int *pivot)
{
	int	*array;
	int	len;
	int	i;

	len = ft_lstsize(stack_a);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
		return (pivot = NULL, 2);
	i = 0;
	while (i < len)
	{
		array[i] = *(stack_a->content);
		stack_a = stack_a->next;
		i++;
	}
	sort_array(array, len);
	*pivot = array[len / 2];
	free(array);
	return (1);
}

int	split_stacks(t_list **stack_a, t_list **stack_b, int pivot)
{
	int		len;

	len = ft_lstsize(*stack_a);
	while (len > 0)
	{
		if (*((*stack_a)->content) < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		len--;
	}
	return (0);
}

int	sort(t_list **stack_a, t_list **stack_b)
{
	if (check_stack_a(*stack_a) == 0)
		return (1);
	if (ft_lstsize(*stack_a) <= 5)
		sort_small_amount(stack_a, stack_b);
	else
		sort_big_amount(stack_a, stack_b);
	return (1);
}
