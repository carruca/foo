#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/param.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
/*
int	main(int argc, char **argv)
{
	pid_t	child_pid;
	errno = 0;

	printf("PID =	%d\n", (int)getpid());
	child_pid = fork();
	printf("Fork return: %d\n", (int)child_pid);
	if (child_pid < 0)
		perror("Failed");
	else if (child_pid == 0)
	{
		printf("I am the child process\n");
		exit(0);
	}
	wait(NULL);
	printf("I am the parent process\n");
	return (0);
}*/

void	error_handling(void)
{
	char *error;

	error = NULL;
	error = strerror(errno);
	write(1, "Error\n", 6);
	write(1, error, strlen(error));
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	DIR				*dirp;
	struct dirent	*entry;
	char 			*cwd;
	char 			buf[256];

//	buf = NULL;
	cwd = getcwd(buf, MAXPATHLEN);
	if (cwd == NULL)
	{
		error_handling();
		exit(0);
	}
	//free(buf);
	write(1, cwd, strlen(cwd));
	write(1, "\n", 1);
	/*
	dirp = opendir(".");

	if (dirp == NULL)
	{
		printf("Error\n%s\n", strerror(errno));
		return (0);
	}
	while ((entry = readdir(dirp)) != NULL)
	{
		printf("%s\n", entry->d_name);
	}
	*/
	return (0);
}
