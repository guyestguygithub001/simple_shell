#include "shell.h"
#include <sys/wait.h>

void prompt(char **av, char **env)
{
	char *string - NULL;
	int a, status;
	size_t n = 0;
	ssize_t char_num;
	char *argv[] = {NULL,NULL};
	pid_t child_pid;

	while (1)
	{
		printf("terminal$ ");
		char_num = getline(&string, &n, stdin)

		if (char_num == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		a = 0;
		while (string[a])
		{
			if (string[a] == '\n')
			string[a] = 0;
			a++;
		}
		argv[0] = string;
		child_pid = fork();
		if (child_pid == -1)
		{
			free(string);
			exit(EXIT_FAILURE);
		}
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
			printf("%s: No such file or directory\n", av[0]);
		}
		else
			wait(&status);
	}
}
