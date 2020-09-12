#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    FILE *fpr = NULL, *fpw = NULL;
    char buf[256];
    int ret;
    fpr = popen("cat /etc/group", "r");
    fpw = popen("grep root", "w");
    while((ret = fread(buf, 1, sizeof(buf), fpr)) != 0)
    {
        fwrite(buf, 1, ret, fpw);
    }
    pclose(fpr);
    pclose(fpw);
    sleep(5);
    return 0;
}
