/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:32:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/01 16:13:15 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	ft_putendl_fd("pb", 1);
	if (*stack_a == NULL)
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	top_a->next = *stack_b;
	*stack_b = top_a;
}
