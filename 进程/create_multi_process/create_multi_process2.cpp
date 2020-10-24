#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void createsubprocess(int num)
{
    pid_t pid;
    int i;
    for(i=0;i<num;i++)
    {
        pid = fork();
        sleep(1);
        if(pid == 0 || pid == -1)
        {
            break;
        }
    }
    if(pid == -1)
    {
        perror("fail to fork!\n");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程对应id=%d, 父进程id=%d\n", getpid(), getppid());
        exit(0);
    }
    else
    {
        printf("父进程id=%d", getpid());
        exit(0);
    }
}

int main()
{
    int num = 3;
    createsubprocess(num);
    return 0;
}