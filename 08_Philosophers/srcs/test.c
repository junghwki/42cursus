#include "../includes/philo.h"

int main(void)
{
	struct timeval timer;
	struct timeval new_timer;

	gettimeofday(&timer, NULL);
	while (1)
	{
		printf("old       : %ld %d\n", timer.tv_sec, timer.tv_usec);
		usleep(1000200);
		gettimeofday(&new_timer, NULL);
		printf("new       : %ld %d\n", new_timer.tv_sec, new_timer.tv_usec);
		printf("new - old : %ld\n", new_timer.tv_sec - timer.tv_sec);
	}
	return (0);
}