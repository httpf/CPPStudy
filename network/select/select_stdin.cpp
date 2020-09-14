#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fno = fileno(stdin);
    fd_set fdR;
    struct timeval timeout = {.tv_sec = 10, .tv_usec = 0};
    FD_ZERO(&fdR);
    FD_SET(fno, &fdR);
    char str[64];
    int goOn = 1;
    while(goOn)
    {
        printf("goOning...\n");
        switch(select(fno+1, &fdR, NULL, NULL, &timeout))
        {
            case -1:
                printf("select failed!\n");
                goOn = 0;
                break;
            case 0:
                printf("select end!\n");
                goOn = 0;
                break;
            default:
                scanf("%s", str);
                printf("str=%s\n", str);
        }
    }
}