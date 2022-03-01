#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define STDERR	2

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return len;
}

void	print_error(char *msg , char *cmd)
{
	write(STDERR, msg, ft_strlen(msg));
	if (cmd)
		write(STDERR, cmd, ft_strlen(cmd));
	write(STDERR, "\n", 1);
	exit(EXIT_FAILURE);
}

char	**get_next(char **argv, char *end)
{
	while (argv && *argv)
	{
		if ( !strcmp(*argv, end))
		{
			*argv = NULL;
			return ++argv;
		}
		argv++;
	}
	return NULL;
}

void	builtin_cd(char **argv)
{
	if (*( argv + 1))
		return print_error("Error: cd: bad argumets", NULL);
	if (argv && *argv)
	{
		if (chdir(*argv) == -1)
			return print_error("Error: cannot change directory to ", *argv);
	}
}

void	execute_cmd(char **argv, char **env, int *fd_pipe, int fd_in)
{
	pid_t	child_pid;

	child_pid = fork();
	if (child_pid == -1)
		print_error("Error: fatal", NULL);
	else if (child_pid == 0)
	{
		if (fd_in)
		{
			if (dup2(fd_in, 0) == -1)
				return print_error("Error: fatal", NULL);
		}
		if (fd_pipe[1] != 1)
		{
			if (dup2(fd_pipe[1], 1) == -1)
				return print_error("Error: fatal", NULL);
		}
		if (execve(*argv, argv, env) == -1)
			print_error("Error: cannot execute ", *argv);
		exit(EXIT_SUCCESS);
	}
	waitpid(child_pid, NULL, 0);
}

void	execute_pipeline(char **argv, char **env)
{
	char	**next_cmd;
	int		fd_pipe[2];
	int		fd_in;

	fd_pipe[0] = 0;
	fd_pipe[1] = 1;
	fd_in = 0;
	while (argv && *argv)
	{
		next_cmd = get_next(argv, "|");
		if (!strcmp(*argv, "cd"))
			builtin_cd(++argv);
		else
		{
			if (next_cmd)
			{
				if (pipe(fd_pipe) == -1)
					return print_error("Error: fatal", NULL);
			}
			execute_cmd(argv, env, fd_pipe, fd_in);
			if (fd_in)
				close(fd_in);
			if (fd_pipe[1] != 1)
				close(fd_pipe[1]);
			if (next_cmd)
				fd_in = fd_pipe[0];
		}
		argv = next_cmd;
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**next_pipeline;

	argv++;
	while (argc && argv && *argv)
	{
		next_pipeline = get_next(argv, ";");
		execute_pipeline(argv, env);
		argv = next_pipeline;
	}
	return 0;
}
