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
/*
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
	return (0);
}*/

int	main(int argc, char **argv, char **environ)
{
	int	stdin_tmp;
	int	stdout_tmp;
	int	fdin;
	int	fdout;
	int	child_pid;
	int	i;
	int	cmd_num;
	int	fd[2];
	int	status;

	stdin_tmp = dup(stdin);
	stdout_tmp = dup(stdout);
	if (argc == 3)
		fdin = open(argv[1], O_RDONLY);
	else
		fdin = dup(stdin_tmp);
	i = 0;
	cmd_num = 2;
	while (i < cmd_num)
	{
		dup2(fdin, stdin);
		close(fdin);
		if (i == cmd_num - 1)
		{
			if (argc == 3)
				fdout = open(argv[2], O_WRONLY);
			else
				fdout = dup(stdout_tmp);
		}
		else
		{
			pipe(fd);
			fdin = fd[0];
			fdout = fd[1];
		}
		dup2(fdout, 1);
		close(fdout);
		child_pid = fork();
		if (child_pid == 0)
		{
			execve("/bin/ls", argv, environ);
			exit(0);
		}
		i++;
	}
	dup2(stdin_tmp, stdin);
	dup2(stdout_tmp, stdout);
	close(stdin_tmp);
	close(stdout_tmp);
	waitpid(child_pid, &status, 0);
}
