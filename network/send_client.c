#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "rdtsc.h"

#define BUF_SIZE (1<<20)
const int trials = 10;

int main(int argc, char** argv)
{
    int cfd, recbytes, sin_size, i, j;
    unsigned long long t0, t1;
    char send_buffer[BUF_SIZE]={0}, rec_buffer[BUF_SIZE]={0};
    struct sockaddr_in s_add, c_add;
    unsigned short portnum = atoi(argv[2]);
    
    srand(time(0));
    for (i = 0; i < BUF_SIZE-1; i++)
        send_buffer[i] = rand()%26 + 'a';
    send_buffer[BUF_SIZE-1] = '\0';
    
    
    for (i = 0; i < trials; i++)
    {
        cfd = socket(AF_INET, SOCK_STREAM, 0);
        
        //if (cfd == -1)
        //    printf("socket fail!\n");
        
        bzero(&s_add, sizeof(struct sockaddr_in));
        
        s_add.sin_family = AF_INET;
        s_add.sin_addr.s_addr = inet_addr(argv[1]);
        s_add.sin_port = htons(portnum);
        //printf("server address = %#x, port address = %#x\n",s_add.sin_addr.s_addr, s_add.sin_port);
        
        
        connect(cfd, (struct sockaddr*)(&s_add), sizeof(struct sockaddr));
        
        //printf("gonna send: %s\n", send_buffer);
        
        t0 = rdtsc();
        /*if (-1 == write(cfd, send_buffer, 32))
            printf("send fail\n");
        else
            printf("send ok\n");
        */
        for (j = 0; j < (1 << 5); j++)
            write(cfd, send_buffer, BUF_SIZE);
        
        //read(cfd, rec_buffer, 32); 
        /*if (-1 == (recbytes = read(cfd, rec_buffer, 1024)))
            printf("rec fail\n");
        else
            printf("rec ok\n");
        */
        t1 = rdtsc();
        
            
        //printf("received: %s\n", rec_buffer);
        printf("Time passed: %.3f(ms)\n", (t1 - t0)  / (1.66e+09) * 1000);
            
        close(cfd);
    }
    return 0;

}
