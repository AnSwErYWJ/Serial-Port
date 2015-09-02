/*************************************************************************
> File Name: example4.c
> Author: AnSwEr
> Mail: 1045837697@qq.com
> Created Time: 2015年09月02日 星期三 09时29分00秒
************************************************************************/

/*
* print winsize
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <termios.h>
#ifndef TIOCGWINSZ
#include <sys/ioctl.h>
#endif

static void pr_winsize(int fd)
{
    struct winsize size;

    if(ioctl(fd,TIOCGWINSZ,(char *) &size) < 0)
    perror("TIOCGWINSZ error");

    printf("%d rows,%d columns\n",size.ws_row,size.ws_col);
}

static void sig_winch(int signo)
{
    printf("SIGWINCH received\n");
    pr_winsize(STDIN_FILENO);
}

int main(void)
{
    if(isatty(STDIN_FILENO)==0)
    {
        exit(EXIT_FAILURE);
    }

    if(signal(SIGWINCH,sig_winch)==SIG_ERR)
        perror("signal error\n");

    pr_winsize(STDIN_FILENO);//打印初始值

    for(;;)
    {
        pause();
    }

    return 0;
}


