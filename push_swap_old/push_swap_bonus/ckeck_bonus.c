/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ckeck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:55:36 by jkarras           #+#    #+#             */
/*   Updated: 2024/01/10 16:54:16 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	print_solution(t_list *stack_a, t_list *stack_b)
{
	int	flag;
	int	prev_value;

	flag = 0;
	if (stack_a == NULL)
		return (-1);
	if (ft_lstsize(stack_b) != 0)
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
	if (flag == 1)
		return (1);
	else
		return (0);
}

void	f(int *nb)
{
	printf("%i ", *nb);
}

void	execute_function(char *function, t_list **a, t_list **b)
{
	if (ft_strcmp_bonus(function, "sa\n") == 0)
		sa_bonus(*a);
	else if (ft_strcmp_bonus(function, "sb\n") == 0)
		sb_bonus(*b);
	else if (ft_strcmp_bonus(function, "ss\n") == 0)
		ss_bonus(*a, *b);
	else if (ft_strcmp_bonus(function, "pa\n") == 0)
		pa_bonus(a, b);
	else if (ft_strcmp_bonus(function, "pb\n") == 0)
		pb_bonus(a, b);
	else if (ft_strcmp_bonus(function, "ra\n") == 0)
		ra_bonus(a);
	else if (ft_strcmp_bonus(function, "rb\n") == 0)
		rb_bonus(b);
	else if (ft_strcmp_bonus(function, "rr\n") == 0)
		rr_bonus(a, b);
	else if (ft_strcmp_bonus(function, "rra\n") == 0)
		rra_bonus(a);
	else if (ft_strcmp_bonus(function, "rrb\n") == 0)
		rrb_bonus(b);
	else if (ft_strcmp_bonus(function, "rrr\n") == 0)
		rrr_bonus(a, b);
}

int	check_command(char *buff, char **names, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	while (names[i] != NULL)
	{
		if (ft_strcmp_bonus(names[i], buff) == 0)
		{
			execute_function(names[i], a, b);
			break ;
		}
		i++;
	}
	if (names[i] == NULL)
		return (ft_putendl_fd("Error", 1), -1);
	else
		return (0);
}

int	check(t_list **stack_a, t_list **stack_b)
{
	char	*ptr;
	char	**names;

	if (ft_lstsize(*stack_a) == 1)
		return (0);
	names = get_functions_array();
	if (names == NULL)
		return (ft_putendl_fd("Error", 1), ft_lstclear(stack_a, free), 0);
	while (1)
	{
		ptr = get_next_line(0);
		if (ptr == NULL)
			break ;
		if (check_command(ptr, names, stack_a, stack_b) != 0)
			return (-1);
		free(ptr);
	}
	if (print_solution(*stack_a, *stack_b) == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (1);
}
