#include <libc.h>

void	ft_pipe()
{
	pid_t	pid_write;
	pid_t	pid_read;
	int pipefd[2];

	pipe(pipefd);

	//first fork
	pid_write = fork();
	if (pid_write == 0)
	{
		int fd = open("./infile", O_RDONLY);
		dup2(fd, 0);
		dup2(pipefd[1], 1);

		char *test[2];
		test[0] = strdup("cat");
		test[1] = NULL;
		close(fd);
		execve("/bin/cat", test, NULL);
	}

	close(pipefd[1]);

	//second fork
	pid_read = fork();
	if (pid_read == 0)
	{
		int fd = open("./outfile", O_WRONLY);
		dup2(fd, 1);
		dup2(pipefd[0], 0);

		char *test[2];
		test[0] = strdup("cat");
		test[1] = NULL;
		close(fd);
		execve("/bin/cat", test, NULL);
	}

	close(pipefd[0]);

	int stats;
	printf("%d -> %d\n", pid_write, pid_read);
	waitpid(pid_write, &stats, 0);
	printf("write OK\n");
	waitpid(pid_read, &stats, 0);
	printf("read OK\n");
	exit(0);
}

int	main(int argc, char **argv, char *envp[])
{
	ft_pipe();
}
