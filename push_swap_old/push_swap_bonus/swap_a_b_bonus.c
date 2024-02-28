/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:21:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 17:01:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_or_sb_ss_bonus(t_list *list)
{
	t_list	*second_node;
	int		*tmp;

	if (list == NULL)
		return ;
	second_node = list->next;
	if (second_node == NULL)
		return ;
	tmp = list->content;
	list->content = second_node->content;
	second_node->content = tmp;
}

void	ss_bonus(t_list *stack_a, t_list *list)
{
	sa_or_sb_ss_bonus(stack_a);
	sa_or_sb_ss_bonus(list);
}
