/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:25:28 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/04 15:13:10 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_running(t_programm *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i].running == false)
			return (1);
		i++;
	}
	return (0);
}

int	is_nrunning(t_programm *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i].running == true)
			return (1);
		i++;
	}
	return (0);
}

int	is_dead(t_programm *prog)
{
	size_t	i;

	i = 0;
	while (i < prog->nb_philos)
	{
		if (prog->philos[i].last_meal == 0)
		{
			if (get_time() - prog->philos[i].start_time >= prog->time_to_die)
				return (print_dead_msg(prog->stfu, (prog->philos)[i].id), 0);
		}
		else
		{
			if (get_time() - prog->philos[i].last_meal >= prog->time_to_die)
				return (print_dead_msg(prog->stfu, (prog->philos)[i].id), 0);
		}
		i++;
	}
	return (1);
}

int	meals_eaten(t_programm *prog)
{
	size_t	i;

	i = 0;
	if (prog->argc != 6)
		return (1);
	while (i < prog->nb_philos)
	{
		if (prog->philos[i].meals_eaten >= prog->meals_to_eat)
			return (print_meals_eaten_msg(prog, &prog->philos[i]), 0);
		i++;
	}
	return (1);
}

void	*monitor_thread(void *arg)
{
	t_programm	*prog;

	prog = (t_programm *)arg;
	prog->start_flag = true;
	if (prog->nb_philos != 1)
	{
		while (is_running(prog) != 0)
			usleep(1);
	}
	else
		usleep(1000);
	while (1)
	{
		if (is_dead(prog) == 0 || meals_eaten(prog) == 0)
		{
			prog->end = true;
			break ;
		}
	}
	while (is_nrunning(prog) != 0)
		usleep(1);
	return (NULL);
}
