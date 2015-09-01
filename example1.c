/*************************************************************************
	> File Name: example1.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年08月31日 星期一 16时25分24秒
 ************************************************************************/

/*
 * tcgetattr和tcsetattr演示
 */

#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
    struct termios t;

    /*先获取终端属性*/
    if(tcgetattr(STDIN_FILENO,&t) < 0)
    {
        perror("tcgetattr failed!");
        exit(EXIT_FAILURE);
    }

    /*与字符屏蔽标志进行与操作，得到当前的字符长度*/
    switch(t.c_cflag & CSIZE)
    {
        case CS5:
        printf("5 bits/byte\n");
        break;
        case CS6:
        printf("6 bits/byte\n");
        break;
        case CS7:
        printf("7 bits/byte\n");
        break;
        case CS8:
        printf("8 bits/byte\n");
        break;
        default:
        printf("unkown bits/byte\n");
    }

    t.c_cflag &= ~CSIZE; //clear out the c_cflag
    t.c_cflag |= CS8; //set 8bits/byte

    /*设置终端属性*/
    if(tcsetattr(STDIN_FILENO,TCSANOW,&t) < 0)
    {
        perror("tcsetattr failed!");
        exit(EXIT_FAILURE);
    }

    /*获取新的终端属性*/
    if(tcgetattr(STDIN_FILENO,&t) < 0)
    {
        perror("tcgetattr failed!");
        exit(EXIT_FAILURE);
    }

    /*检测是否设置成功*/
    if((t.c_cflag & CSIZE) == CS8)
        printf("set successfully!\n");
    else
        printf("set failed!\n");

    exit(EXIT_SUCCESS);
}
