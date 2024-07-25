/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:21:17 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/17 14:57:56 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_meals_eaten_msg(t_programm *prog)
{
	pthread_mutex_lock(prog->stfu);
	ft_putstr_fd("All philos have eaten ", 1);
	ft_putnbr_fd(prog->meals_to_eat);
	ft_putendl_fd(" times", 1);
	pthread_mutex_unlock(prog->stfu);
}

void	print_uptate(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->prog->stfu);
	if (philo->prog->end != true)
	{
		ft_putnbr_fd(get_time() - philo->start_time);
		ft_putstr_fd(" -> ", 1);
		ft_putnbr_fd(philo->id);
		write(1, " ", 1);
		ft_putendl_fd(str, 1);
	}
	pthread_mutex_unlock(philo->prog->stfu);
}

void	print_dead_msg(t_philo *philo)
{
	pthread_mutex_lock(philo->prog->stfu);
	ft_putnbr_fd(get_time() - philo->start_time);
	ft_putstr_fd(" -> ", 1);
	ft_putnbr_fd(philo->id);
	write(1, " ", 1);
	ft_putendl_fd("died", 1);
	pthread_mutex_unlock(philo->prog->stfu);
	pthread_mutex_unlock(philo->meal_lock);
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_uptate("took a fork", philo);
	pthread_mutex_lock(philo->l_fork);
	print_uptate("took a fork", philo);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
