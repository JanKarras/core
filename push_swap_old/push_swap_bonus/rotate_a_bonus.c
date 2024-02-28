/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:48:23 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 16:37:26 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ra_bonus(t_list **stack_a)
{
	t_list	*second_node;
	t_list	*last_node;

	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_node = (*stack_a)->next;
	last_node = ft_lstlast(*stack_a);
	(*stack_a)->next = NULL;
	last_node->next = *stack_a;
	*stack_a = second_node;
}
