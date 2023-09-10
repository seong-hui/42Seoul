#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	 main()
{
	pid_t pid;
	int fds[2];

	pid = fork();
	pipe(fds);
	for (int i = 0; i< 2; i++)
	{
		if (pid == 0 && i = 0)
		{
			fd = open("text.txt", )
			dup2(fds[1], 1);
			printf("자식 222\n");
		}
		else if (pid == 0 && i = 1)
		{
			dup2(fds[0], STDIN_FILENO);
			fd = open("text.txt", )
			execve("ls","asd ", NULL);
			dup2(fd, STDOUT_FILENO);
		}
	}
	else
	{
		waitpid(-1, 0, 0);
	}
}