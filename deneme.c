#include "philo.h"

int i = 0;

void	*bir_fonksiyon(void *arg)
{
	int i = *(int *)arg;
	printf("i: %d\n", i);
	usleep(100000);
	return (0);
}

void	*iki_fonksiyon(void *arg)
{
	int i = *(int *)arg;
	printf("i: %d\n", i);
	usleep(500);
	return (0);
}

int main()
{
	pthread_t	ali[100];
	int sıfır = 0;
	int bir = 1;

	pthread_create(&ali[0], NULL, bir_fonksiyon, &sıfır);
	pthread_create(&ali[1], NULL, iki_fonksiyon, &bir);

	
	pthread_join(ali[0], NULL);
	pthread_join(ali[1], NULL);

	// for (size_t i = 0; i < 2; i++)
	// {
	// }
	return (0);
}