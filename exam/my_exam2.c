#include <libc.h>

void err_print(char *str) {
	while (*str)
		write(2, str++, 1);
}

int exec_cd(char *argv[], int i) {
	if (i != 2)
		return 1;
	if (chdir(argv[1]) == -1)
		return 1;
	return 0;
}

void set_pipe(int *fd, int newfd) {
	if (dup2(fd[newfd], newfd) == -1) {
		err_printf("err");
		exit (1);
	}
	if (close(fd[0]) == -1 || close(fd[1]) == -1) {
		err_printf("err");
		exit (1);
	}
}


// トークンの実行
int exec_cmd(char *argv[], char *envp[], int len) {
	int has_pipe;
	int fd[2];
	int pid;
	int status;

	has_pipe = 0;
	// pipeがあるか
	if (argv[len] != NULL && strcmp(argv[len], "|"))
		has_pipe = 1;
	// pipeがないかつ, cdがあれば優先的に実行する
	if (has_pipe == 0 && !strcmp(argv[0], "cd")) {
		return exec_cd(argv, len);
	}
	// pipeを生成します
	// forkします
	pid = fork();
		// 子プロセス
			// cdは例外的な処理をします
				// exit() する
			// もしもpipeがあるならば
				// pipeの付け替えを行う (std in)
			// execveを実行する
				// exit(1);
		// 親プロセス
			// todo waitpidを使う
			// pipeの付け替えを行う (std out)
			// statusを用いる
		// todo W IF EXITED() && W EXIT STATUS()
}

// トークンに分解する
int main(int argc, char *argv[], char *envp[]) {

	int i = 0;
	int status = 0;
	
	while (argv[i])
		argv += i + 1;

		i = 0;
		while (argv[i] != NULL && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (i)
			status = exec_cmd(argv, envp, i);
	}

	return status;
}