/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czinsou <czinsou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 13:29:58 by czinsou           #+#    #+#             */
/*   Updated: 2026/01/09 15:58:40 by czinsou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <time.h>
# include <unistd.h>

# define RESET "\033[0m"
# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN "\033[1;36m"
# define WHITE "\033[1;37m"

typedef struct s_table	t_table;

typedef pthread_mutex_t	t_mtx;

typedef struct s_fork
{
	t_mtx				fork;
	int					fork_id;
}						t_fork;

typedef struct s_philo
{
	int					id;
	long				nbr_meals;
	bool				full;
	long				last_meals_time;
	t_fork				*first_fork;
	t_fork				*second_fork;
	int					have_first;
	int					have_second;
	t_mtx				eat_mutex;
	pthread_t			thread_id;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				nbr_limit_meals;
	long				start_simulation;
	bool				end_simulation;
	bool				all_threads_ready;
	t_mtx				table_mutex;
	t_fork				*forks;
	t_philo				*philos;
}						t_table;

typedef enum e_mutex_action
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
}						t_mutex_action;

typedef enum e_threads_action
{
	CREATE,
	JOIN,
	DETACH,
}						t_threads_action;

int						error_exit(const char *msg);
void					*safe_malloc(size_t bytes);
int						handle_mutex_error(int status, t_mutex_action action);
int						handle_thread_error(int status,
							t_threads_action action);
int						safe_thread(pthread_t *thread, void *(*f)(void *),
							void *data, t_threads_action action);
int						safe_mutex(t_mtx *mutex, t_mutex_action action);
int						parse_arg(t_table *table, char **argv);
void					assign_forks(t_philo *philo, t_fork *forks,
							int philo_position);
void					philo_init(t_table *table);
int						data_init(t_table *table);
void					destroy_all(t_table *table);
void					print_action(t_philo *philo, const char *action);
long					gettime(void);
void					handle_forks(t_philo *philo, t_mutex_action action);
void					philo_eat(t_philo *philo);
void					philo_think(t_philo *philo);
void					*philo_routine(void *arg);
bool					all_full(t_table *table);
void					check_philos(t_table *table);
void					*routine(void *arg);
void					diner_simulation(t_table *table);
void					handle_fork(t_philo *philo, t_mutex_action action);
void					my_usleep(long duration_ms, t_table *table);
void					print_death(t_philo *philo, const char *action);
bool					get_bool(t_mtx *mtx, bool *b);
void					set_bool(t_mtx *mtx, bool *b, bool a);

#endif