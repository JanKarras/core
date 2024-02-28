/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:32:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/06 19:07:46 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb_bonus(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
}
