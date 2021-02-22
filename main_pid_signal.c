#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>

/*
int main()
{
	pid_t	child_pid;
	int		fd[2];
	char	buf[10];
	int		nbytes;

	pipe(fd);
	child_pid = fork();

	if (child_pid > 0)
	{
		close(fd[0]);
		write(fd[1], "|abcdef|", 8);
		close(fd[1]);
	}
	else if (child_pid == 0)
	{
		close(fd[1]);
		nbytes = read(fd[0], buf, sizeof(buf));
		printf("El padre lee %d bytes de la string %s\n", nbytes, buf);
		close(fd[0]);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}*/
/*
void	signal_handler(int sig)
{
	printf("Signal number is %d\n", sig);
}

int		main(void)
{	
	signal(SIGALRM, &signal_handler);
	while (1)
	{
		printf("waiting for signal...\n");
		sleep(5);
	}
}*/

int		main(void)
{
//	struct stat	buf;

//	stat("untitled.txt", &buf);
	perror("Error");
	return (0);
}
