#define _GNU_SOURCE
#define _LARGEFILE64_SOURCE
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../rdtsc.h"
#define BUF_SIZE 262144
const int trials = 100;

unsigned long long a,b,count,c;

int main(int argc, char* argv[])
{
	int i, j, temp;
	long long filesize;
	ssize_t result;
	static char buffer[BUF_SIZE] __attribute__ ((__aligned__ (512)));

	/*FILE *fd;
	if ((fd = fopen("a","r")) == NULL)
	{
		printf("file name should be a");
		exit(1);
	}*/
	srand(time(0));
	for (i=0; i<20; i++)
	{
	    int fd;
	    fd = open(argv[1], O_RDONLY);
	    //fd = open(argv[1], O_RDONLY | O_LARGEFILE);
	    if (fd == -1)
	        printf("open error\n");
	
	    //find file size
	    //fseek (fd , 0 , SEEK_END);
	    //filesize = ftell (fd);
	    //rewind (fd);
	    struct stat sb;
	    fstat(fd, &sb);
	    filesize = sb.st_size;
	    //printf("%lld\n", filesize);
	    //printf("block size = %u blocks = %u\n", sb.st_blksize, sb.st_blocks);
	
	
	    //allocate buffer memory
	    //buffer = (char*) malloc (BUF_SIZE);
	    //printf("%x\n", buffer);
	    //if (buffer == NULL)
	    //    printf("malloc error!\n");
	
	
	    //sequential read?

	    //lseek(fd,0,SEEK_SET);
		//temp = posix_fadvise(fd, 0, 0, POSIX_FADV_DONTNEED);
		
		//ssize_t remain = filesize;
		
		unsigned long long total = 0;
		
		for(j = 0; j < trials; j++)
		{
		    unsigned long long a1 = rand()%32768;
		    unsigned long long a2 = rand()%32768;
		    unsigned long long a3 = rand()%32768;
		    unsigned long long r = a1 * 32768 * 32768 + a2 * 32768 + a3;
		    //printf("%llu %llu %llu %llu\n",a1,a2,a3,r);
		    //printf("%llu\n",r % (((unsigned long long)1) << 31));
		    a=rdtsc();
		    lseek(fd, (r % filesize) / 512 * 512, SEEK_SET);
		    read(fd, buffer, BUF_SIZE);
		    b=rdtsc();
		    total += b - a;
		    
		    //printf("%d\n",);
		}
		/*a = rdtsc();
		printf("------\n");
		while(read(fd, buffer, BUF_SIZE) > 0);
		printf("------\n");
		b = rdtsc();
		*/
		//printf("%llu\n",b-a);
		printf("%.3f\n", (total / 1.66e+06) / (trials / 4));
	
	
	//fclose(fd);
	close(fd);
	//free(buffer);
	}
	return 0;
	
}
