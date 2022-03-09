#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = fork();

    if (pid == 0)
    {
        execl("SL_child", "Command-Line", NULL);
    }
    waitpid(pid, NULL, 0);

    printf("Lefutott a child-process!");
    return 0;
}
