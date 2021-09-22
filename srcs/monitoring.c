#include "../includes/philo.h"

void	death_monitor(t_main *main)
{
	while (!main->dead_found)
		usleep(100);
	printf("\n\t PHILO SHOULDN'T DIE \n\n");
}

void	meal_and_death_monitor(t_main *main)
{
	char	*time;

	while (!main->dead_found
		&& main->nb_finished_meal < main->nb_philo)
		usleep(100);
	if (main->nb_finished_meal == main->nb_philo && !main->dead_found)
	{
		time = ft_itoa(elapsed_time(main->start_time));
		printf("%s\t", time);
		printf("Each philosopher have eat %d times.\n", main->nb_meal);
		free(time);
	}
}