#include "../includes/philo.h"

int main (int argc, char **argv)
{
	t_main	main;

	if (argc >= 5 && argc <= 6)
	{
		if (!init(&main, argc, argv))
		{
			printf("Invalid arguments\n");
			return (1);
		}
		//launch_threads(&main);
		//launch_monitoring(&main);
		//free_all(&main);
	}
	else
	{
		printf("Invalid number of parameters\n");
		return (1);
	}
	return (0);
}