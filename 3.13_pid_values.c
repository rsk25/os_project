#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t  pid, pid1;
    pid = fork();
    if (pid == 0) {
        pid1 = getpid();
        printf("child: pid = %d\n",pid);
        printf("child: pid = %d\n",pid1);
    }
    else if (pid > 0) {
        pid1 = getpid();
        printf("parent: pid = %d\n",pid);
        printf("child: pid = %d\n",pid1);
        wait(NULL);
    }
    return 0;
}