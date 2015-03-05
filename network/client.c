#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include "rdtsc.h"

const int trials = 300;

int main(int argc, char** argv)
{
    int cfd, recbytes, sin_size, i;
    unsigned long long t0, t1, setup_total = 0, teardown_total = 0, lat_total = 0;
    char send_buffer[1024]={0}, rec_buffer[1024]={0};
    struct sockaddr_in s_add, c_add;
    unsigned short portnum = atoi(argv[2]);
    
    srand(time(0));
    for (i = 0; i < 31; i++)
        send_buffer[i] = rand()%26 + 'a';
    send_buffer[31] = '\0';
  
  
    for(i = 0; i < trials; i++)
    {  
        cfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //if (cfd == -1)
    //    printf("socket fail!\n");
    

        bzero(&s_add, sizeof(struct sockaddr_in));
        
        s_add.sin_family = AF_INET;
        s_add.sin_addr.s_addr = inet_addr(argv[1]);
        s_add.sin_port = htons(portnum);
        //printf("server address = %#x, port address = %#x\n",s_add.sin_addr.s_addr, s_add.sin_port);
        
        t0 = rdtsc();
        connect(cfd, (struct sockaddr*)(&s_add), sizeof(struct sockaddr));
        t1 = rdtsc();
        
        setup_total += t1 - t0;
        printf("%llu\t", t1 - t0);
        
        //printf("gonna send: %s\n", send_buffer);
        
        t0 = rdtsc();
        
        
        /*if (-1 == write(cfd, send_buffer, 32))
            printf("send fail\n");
        else
            printf("send ok\n");
        */
        write(cfd, send_buffer, 32);
        read(cfd, rec_buffer, 32); 
        /*if (-1 == (recbytes = read(cfd, rec_buffer, 1024)))
            printf("rec fail\n");
        else
            printf("rec ok\n");
        */
        t1 = rdtsc();
        lat_total += t1 - t0;
        printf("%llu\t", t1 - t0);
            
        //printf("received: %s\n", rec_buffer);
        //printf("Time passed: %llu(cycles), %.3f(ms)\n", t1 - t0, (t1 - t0)  / (1.66e+09) * 1000);
            
        t0 = rdtsc();
        close(cfd);
        t1 = rdtsc();
        teardown_total += t1 - t0;
        printf("%llu\n", t1 - t0);
    }
    //printf("Setup time: %.4f | Latency: %.4f | Teardown time: %.4f (ms)\n", setup_total / (1.66e+09) * 1000 / trials, lat_total / (1.66e+09) * 1000 / trials, teardown_total / (1.66e+09) * 1000 / trials);
    
    return 0;

}
