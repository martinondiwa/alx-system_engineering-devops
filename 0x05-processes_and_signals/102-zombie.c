#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N_ZOMBIES 5

/**
 * infinite_while - loop forever
 *
 * Return: Never
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 * main - spawn zombie processes
 *
 * Return: Never
 */
int main(void)
{
	int zpid = 0;
	int znum = 0;

	while (znum++ < N_ZOMBIES)
	{
		zpid = fork();
		if (zpid)
			printf("Zombie process created, PID: %d\n", zpid);
		else
			return (EXIT_SUCCESS);
	}
	return (infinite_while());
}
