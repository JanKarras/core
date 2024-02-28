/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:33 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:13:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*second_node;
	t_list	*last_node;

	ft_putendl_fd("rr", 1);
	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_node = (*stack_a)->next;
	last_node = ft_lstlast(*stack_a);
	(*stack_a)->next = NULL;
	last_node->next = *stack_a;
	*stack_a = second_node;
	if (stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second_node = (*stack_b)->next;
	last_node = ft_lstlast(*stack_b);
	(*stack_b)->next = NULL;
	last_node->next = *stack_b;
	*stack_b = second_node;
}
