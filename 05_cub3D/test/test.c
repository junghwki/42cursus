#include <math.h>
#include <stdio.h>

double ft_dist_calc(double x, double y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

int	main(void)
{
	printf("%f\n",ft_dist_calc(2,2));
	return (0);
}