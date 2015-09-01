/*************************************************************************
	> File Name: example3.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月31日 星期一 18时54分09秒
 ************************************************************************/

/*
 *ttyname函数示例
 */

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    char *name;

    if(isatty(STDIN_FILENO))
    {
        name = ttyname(STDIN_FILENO);
        if(name == NULL)
            name = "undefined";
    }
    else
        name = "not a tty";
    printf("fd 0:%s\n",name);

    if(isatty(STDOUT_FILENO))
    {
        name = ttyname(STDOUT_FILENO);
        if(name == NULL)
            name = "undefined";
    }
    else
        name = "not a tty";
    printf("fd 1:%s\n",name);

    if(isatty(STDERR_FILENO))
    {
        name = ttyname(STDERR_FILENO);
        if(name == NULL)
            name = "undefined";
    }
    else
        name = "not a tty";
    printf("fd 2:%s\n",name);

    return 0;
}
