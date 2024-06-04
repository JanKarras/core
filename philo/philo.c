/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:24:03 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/04 14:26:26 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_sleep(size_t time)
{
	size_t	new_time;

	new_time = get_time();
	while (get_time() - new_time <= time)
		usleep(1000);
}

void	one_philo(t_philo *philo)
{
	philo->start_time = get_time();
	print_uptate("took a fork", philo);
	philo->running = false;
}

void	*philo_thread(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->prog->start_flag == false)
		usleep(1);
	if (philo->prog->nb_philos == 1)
		return (one_philo(philo), NULL);
	philo->start_time = get_time();
	philo->running = true;
	if (philo->id % 2 != 0)
		my_sleep(15);
	while (philo->prog->end == false)
	{
		take_forks(philo);
		philo->last_meal = get_time();
		print_uptate("is eating", philo);
		my_sleep(philo->time_to_eat);
		put_forks(philo);
		philo->meals_eaten += 1;
		print_uptate("is sleeping", philo);
		my_sleep(philo->time_to_sleep);
		print_uptate("is thinking", philo);
	}
	philo->running = false;
	return (NULL);
}
