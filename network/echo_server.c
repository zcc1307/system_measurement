#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "rdtsc.h"

#define BUF_SIZE 1024

int main(int argc, char** argv)
{
    int sfp,nfp;
    struct sockaddr_in s_add, c_add;
    int sin_size;
    char recv_buffer[BUF_SIZE];
    unsigned short portnum = atoi(argv[1]);
    int flag = 0;
    unsigned long long t0, t1;

    sfp = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sfp == -1)
        printf("socket fail\n");
    else
        printf("socket ok\n");

    bzero(&s_add, sizeof(struct sockaddr_in));
    
    s_add.sin_family = AF_INET;
    s_add.sin_addr.s_addr = htonl(INADDR_ANY);
    s_add.sin_port = htons(portnum);
    
    bind(sfp, (struct sockaddr*)(&s_add), sizeof(struct sockaddr));
    
    listen(sfp, 5);
    
    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        nfp = accept(sfp, (struct sockaddr*)(&c_add), &sin_size);
        
        printf("Server start get connect from %#x: %#x\n", ntohl(c_add.sin_addr.s_addr), ntohs(c_add.sin_port));
        
        read(nfp, recv_buffer, BUF_SIZE);
        t0 = rdtsc();
        while(read(nfp, recv_buffer, BUF_SIZE) != 0);
        t1 = rdtsc();
        
        printf("Time passed: %.3f(ms)\n", (t1 - t0)  / (1.66e+09) * 1000);
        
        close(nfp);
    }
    
    close(sfp);
    return 0;
}
