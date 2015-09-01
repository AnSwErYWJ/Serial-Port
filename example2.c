/*************************************************************************
	> File Name: example2.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月31日 星期一 18时48分47秒
 ************************************************************************/

/*
 *isatty 示例
 */

#include<stdio.h>
#include<unistd.h>

int main(void)
{
    printf("fd 0:%s\n",isatty(0)?"tty":"not a tty");
    printf("fd 1:%s\n",isatty(1)?"tty":"not a tty");
    printf("fd 2:%s\n",isatty(2)?"tty":"not a tty");

    return 0;
}
