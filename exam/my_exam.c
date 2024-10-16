#include <libc.h>

void err_print(char *str) {
	while (*str)
		write(2, str++, 1);
}

int exec_cd(char *cmd[], int i) {
	if (i != 2) {
		err_print("error: fatal\n");
		return 1;
	}
	if (chdir(cmd[1]) == -1) {
		err_print("error: cd: cannot change directory to ");
		err_print(cmd[1]);
		err_print("\n");
		return 1;
	}
	return 0;
}

void set_pipe(int has_pipe, int *fds, int std_file) {
	if (has_pipe == 0)
		return ;
		printf("debug in set pipe\n");
	if (dup2(fds[std_file], std_file) == -1) {
		err_print("error: fatal\n");
		exit(1);
	}
	if (close(fds[0]) == -1) {
		err_print("error: fatal\n");
		exit(1);
	}
	if (close(fds[1]) == -1) {
		err_print("error: fatal\n");
		exit(1);
	}

		printf("debug set pipe done\n");
}

int exec_cmd(char *cmds[], int len, char *envp[]) {
	int has_pipe;
	int fds[2];
	int pid;
	int status;

	has_pipe = 0;

	// pipeがあるかどうか
	if (cmds[len] != NULL && !strcmp(cmds[len], "|"))
		has_pipe = 1;

			printf("hello -1\n");

	//cd は率先して行う
	if (has_pipe == 0 && !strcmp(cmds[0], "cd")) {
			printf("debug: has pipe\n");
		return exec_cd(cmds, len);
	}

			printf("hello 0\n");

	// pipeがあればforkとpipeを行う
	if (has_pipe == 1) {
		if (pipe(fds) == -1) {
			err_print("error: fatal\n");
			exit(1);
		}
	}
			printf("hello 1\n");

	pid = fork();
	if (pid == -1) {
		err_print("error: fatal\n");
		exit(1);
	}

	if (pid) {
		// todo 終端に0をセットする
		cmds[len] = NULL;

			printf("hello 1\n");
		
		// set_pipe(has_pipe, fds, STDOUT_FILENO);
		set_pipe(has_pipe, fds, 1);

			printf("hello 2\n");

		if (!strcmp(cmds[0], "cd"))
			exit(exec_cd(cmds, len));

			printf("hello 3\n");

		execve(*cmds, cmds, envp);

		err_print("error: cannnot execute ");
		err_print(*cmds);
		err_print("\n");
		exit(1);
	}

	waitpid(pid, &status, 0);
	// set_pipe(has_pipe, fds, STDIN_FILENO);
	set_pipe(has_pipe, fds, 0);

	return WIFEXITED(status) && WEXITSTATUS(status);
}

int main(int argc, char *argv[], char *envp[]) {
	int i, status;

	i = 0;
	status = 0;
	while (argv[i]) {
		argv += i + 1;
		i = 0;

		while (argv[i] != NULL && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
		{
			i++;
		}

		if (i > 0) {
			printf("enter\n");
			status = exec_cmd(argv, i, envp);
		}

		printf("hello--\n");
	}

	printf("status = %d\n", status);
	return status;
}