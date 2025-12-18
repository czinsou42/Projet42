/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:21:04 by czinsou           #+#    #+#             */
/*   Updated: 2025/11/24 16:02:32 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
	{
		error_exit("Error with malloc");
		return (NULL);
	}
	return (ret);
}

int	handle_mutex_error(int status, t_mutex_action action)
{
	if (status == 0)
		return (0);
	if (status == EINVAL && (action == LOCK || action == UNLOCK))
		return (error_exit("Invalid Mutex"));
	else if (status == EINVAL && action == INIT)
		return (error_exit("Invalid mutex attribute"));
	else if (status == EDEADLK)
		return (error_exit("Deadlock detected"));
	else if (status == ENOMEM)
		return (error_exit("Not enough memory to create mutex"));
	else if (status == EBUSY)
		return (error_exit("Mutex is already locked/destroyed"));
	else
		return (error_exit("Unknown mutex error"));
}

int	handle_thread_error(int status, t_threads_action action)
{
	if (status == 0)
		return (0);
	if (status == EAGAIN)
		return (error_exit("No resources to create another thread"));
	else if (status == EPERM)
		return (error_exit("The caller does not have appropriate permission"));
	else if (status == EINVAL && action == CREATE)
		return (error_exit("Invalid value specified for thread creation"));
	else if (status == EINVAL && (action == JOIN || action == DETACH))
		return (error_exit("Thread is not joinable"));
	else if (status == ESRCH)
		return (error_exit("No thread could be found"));
	else if (status == EDEADLK)
		return (error_exit("Deadlock detected"));
	else
		return (error_exit("Unknown thread error"));
}

int	safe_mutex(t_mtx *mutex, t_mutex_action action)
{
	int	status;

	if (action == LOCK)
		status = pthread_mutex_lock(mutex);
	else if (action == UNLOCK)
		status = pthread_mutex_unlock(mutex);
	else if (action == DESTROY)
		status = pthread_mutex_destroy(mutex);
	else if (action == INIT)
		status = pthread_mutex_init(mutex, NULL);
	else
		return (error_exit("Wrong action for mutex handle"));
	return (handle_mutex_error(status, action));
}

int	safe_thread(pthread_t *thread, void *(*f)(void *), void *data,
		t_threads_action action)
{
	int	status;

	if (action == CREATE)
		status = pthread_create(thread, NULL, f, data);
	else if (action == JOIN)
		status = pthread_join(*thread, NULL);
	else if (action == DETACH)
		status = pthread_detach(*thread);
	else
		return (error_exit("Wrong action for thread"));
	return (handle_thread_error(status, action));
}
