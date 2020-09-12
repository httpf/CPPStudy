#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pid_t pid;

//num当前已经创建好的进程数，max需要创建的进程数
void createsubprocess(int num, int max)
{
    if(num >= max) return;
    pid = fork();
    if(pid < 0)
    {
        perror("fork error!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        sleep(3);
        printf("子进程id=%d, 父进程id=%d\n", getpid(), getppid());
    }
    else
    {
        num++;
        if(num == 1) printf("父进程id=%d\n", getpid());
        if(num < max) createsubprocess(num, max);
        sleep(2);
    }
}

int main()
{
    int num = 0;
    int max = 3;
    createsubprocess(num, max);
    return 0;
}