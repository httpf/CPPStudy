/*
参考：
https://blog.csdn.net/oguro/article/details/53841949

管道

本质：
由两个文件描述符来操作管道；其中一个管道进行写操作，另一个进行读操作；
实质为内核实用环形队列机制，借助内核缓冲区（4K）实现；
数据从写端流入，从读端流出；

局限：
数据自己读不能自己写；
半双工通信，数据只能在一个方向上流动；
只能在有公共祖先的进程间使用；
数据一旦取走，便不再存在，不可反复读取；
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void sys_err(const char *str)
{
    perror(str); //输出str,并加上错误原因，原因由errno决定
    exit(1);
}

int main(void)
{
    pid_t pid;
    char buf[1024];
    int fd[2];
    char *p = "Hello Pipe!\n";
    if(pipe(fd) == -1) //创建管道
    {
        sys_err("pipe");
    }

    pid = fork();  //创建子进程
    if(pid < 0)
    {
        sys_err("fork()");
    }
    else if(pid == 0) //子进程
    {
        close(fd[1]);  //关闭文件描述符
        int len = read(fd[0], buf, sizeof(buf)); //读数据
        write(STDOUT_FILENO, buf, len); //将数据写出到标准设备
        close(fd[0]);
    }
    else //父进程
    {
        close(fd[0]);
        write(fd[1], p, strlen(p));
        wait(NULL); //等待子进程结束，父进程再结束，否则子进程会成为僵尸进程
        close(fd[1]);
    }
    
    return 0;
}