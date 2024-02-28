/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:37:42 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 16:37:09 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrr_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_node;
	t_list	*second_last_node;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last_node = ft_lstlast(*stack_a);
	second_last_node = *stack_a;
	while (second_last_node->next != last_node)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = *stack_a;
	*stack_a = last_node;
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	last_node = ft_lstlast(*stack_b);
	second_last_node = *stack_b;
	while (second_last_node->next != last_node)
		second_last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = *stack_b;
	*stack_b = last_node;
}
