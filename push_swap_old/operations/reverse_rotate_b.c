/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:36:54 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:13:22 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrb(t_list **stack_b)
{
	t_list	*last_node;
	t_list	*second_last_node;

	ft_putendl_fd("rrb", 1);
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
