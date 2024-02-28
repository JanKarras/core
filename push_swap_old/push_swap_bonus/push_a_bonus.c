/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:23:40 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 16:37:02 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (*stack_b == NULL)
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	top_b->next = *stack_a;
	*stack_a = top_b;
}
