/*************************************************************************
	> File Name: raw_mode.c
	> Author: AnSwEr
	> Mail: 1045837697@qq.com
	> Created Time: 2015年09月02日 星期三 22时41分14秒
 ************************************************************************/

#include<stdio.h>
#include<termios.h>
#include<stdlib.h>
#include<unistd.h>

static int RawMode(int fd) 
{  
    struct termios raw,old;

    if (!isatty(STDIN_FILENO))
    {
        fprintf(stderr,"not a tty!\n");
        exit(EXIT_FAILURE);
    }
    
    if (tcgetattr(fd,&old) == -1)
    {
        perror("tcgetattr failed");
        exit(EXIT_FAILURE);
    }

    raw = old;  /* modify the original mode */
    
    /* input modes: no break, no CR to NL, no parity check, no strip char,
     * no start/stop output control. */
    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    
    /* output modes - disable post processing */
    raw.c_oflag &= ~(OPOST);
    
    /* control modes - set 8 bit chars */
    raw.c_cflag |= (CS8);
    
    /* local modes - choing off, canonical off, no extended functions,
     * no signal chars (^Z,^C) */
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
    
    /* control chars - set return condition: min number of bytes and timer.
     * We want read to return every single byte, without timeout. */
    raw.c_cc[VMIN] = 1; raw.c_cc[VTIME] = 0; /* 1 byte, no timer */

    /* put terminal in raw mode after flushing */
    if (tcsetattr(fd,TCSAFLUSH,&raw) < 0)
    {
        perror("tcsetattr failed!\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
