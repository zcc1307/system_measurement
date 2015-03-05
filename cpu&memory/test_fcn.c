/*
    test_fcn.c - main testing time overhead for CPU operations
    Charlie Chen, Chicheng Zhang
*/

#include "test_fcn.h"


// test_mem_lat() function for testing memory latency 
// based on randomly access a preprocessed array 
void test_mem_lat()
{
    srand(10000);
    
    int y, temp1, temp2, temp3;
    unsigned int k;
    unsigned long long avg = 0;
    double baseline;
    a = rdtsc();
    for (i = 0; i < n1; i++)
    {      
    }
    b = rdtsc();
    avg += b - a;
    baseline = (double)avg / n1;
    
    for(k=8; k<(1<<28); k<<=1)
    {
        //printf("using memory of size %u...\n", sizeof(int) * k);
        //printf("allocating memory of size %u...\n", sizeof(int) * k);
        int *arr = (int *)malloc(sizeof(int)*k);
        if (!arr)
        {
            printf("cannot allocate memory of size %u!\n", sizeof(int) * k);
        }
        
        for(i=0; i<k;i++)
            arr[i]=(i+1)%k;
            
        for(i=0; i<10*k;i++)
        {
            temp1 = rand()%k;
            temp2 = arr[temp1];
            temp3 = rand()%k;
            if (temp2 == temp3)
                continue;
            arr[temp1] = arr[temp2];
            arr[temp2] = arr[temp3];
            arr[temp3] = temp2;
        
        }

        avg = 0;
        a=rdtsc();
        y = 0;
        for(i=0;i<n1;i++)
        {
            y = arr[y];    
            //printf("%llu\n", b-a);
        }
        b=rdtsc();
        avg += b - a;
        printf("%.3f\n", (double)avg / n1 - baseline);
        
        free(arr);
    }   

    printf("%d\n",k);

}

// test_mem_bw() - test memory bandwidth
// based on running the library call memcpy()
void test_mem_bw()
{
    srand(10);
    
    for (i = 0; i < 5000; i++)
    {    
        a = rdtsc();
        b = rdtsc();
        //printf("%d\n", b - a);      
    }
    
    int k = (1<<27);
    int i,t;
    /*
    //for(k=(1<<0); k<(1<<27); k<<=1)
    {
        //printf("%d\n",sizeof(long double));
        printf("allocating memory of size %d...\n", sizeof(int) * k);
        //int *arr = (int *)malloc(sizeof(int)*k);
        int *arr = (int *)malloc(sizeof(int)*k);
        
        if (!arr)
        {
            printf("cannot allocate memory of size %d!\n", sizeof(int) * k);
        }
        
        a=rdtsc();
        for(i=0; i<k;i++)
            arr[i]=i;
        b=rdtsc();   
        printf("Write time: %llu (cycle), speed: %.3f (B/cycle): %.3f (MB/s)\n", b-a, sizeof(int) * k / (double)(b-a),  sizeof(int) * k * 1.66e+09 / ((1<<20) * (double)(b-a)));
        
        a=rdtsc();
         for(i=0; i<k;i++)
            t=arr[i];
        b=rdtsc();   
        printf("Read time: %llu (cycle), speed: %.3f (B/cycle): %.3f (MB/s)\n", b-a, sizeof(int) * k / (double)(b-a),  sizeof(int) * k * 1.66e+09 / ((1<<20) * (double)(b-a)));  

        free(arr);
    }   */

    //printf("%d\n",k);
    
    //k <<= 2;
    int *arr1 = (int *)malloc(sizeof(int)*k);
    int *arr2 = (int *)malloc(sizeof(int)*k);
    
    for (i = 0; i < k; i++)
    {
        arr1[i] = rand();
        arr2[i] = rand();
    }
    int z;
    for (z=0;z<50;z++)
    {
    a = rdtsc();
    memcpy(arr1, arr2, sizeof(int)*k);
    b = rdtsc();
    //printf("Memcpy time: %llu (cycle), speed: %.3f (B/cycle): %.3f (MB/s)\n", b-a-110, sizeof(int) * k / (double)(b-a-110), 2* sizeof(int) * k * 1.66e+09 / ((1<<20) * (double)(b-a-110)));
    printf("%.3f" 2* sizeof(int) * k * 1.66e+09 / ((1<<20) * (double)(b-a-110)));
    }
}


// test_pg_flt() - test the time overhead for system to handle page fault
// randomly access an array in a wide range, such that with high probability the program will trigger a pagefault, and we filter out the fault statstics.
void test_pg_flt()
{
    int v = 28;
    int* array1 = malloc((1<<v)*4);
    int* array2 = malloc((1<<v)*4);
    int k;
    
    if (array1 == NULL || array2 == NULL)
        printf("malloc() failed!\n");
    //else
    //    printf("malloc() success!\n");
    //printf("--\n");

    for (k = 0; k < (1<<v); k++)
    {
        //printf("%d\n", k);
        //if (k %  (1024) == 0)
        //{
            array1[k] = k;
            array2[k] = k;
        //}
    } 
    
    int j = 0;
    for (i = 0; i <                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     100                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     ; i++)
    {  
        //printf("--\n");
        //a = rdtsc();
        //array1[1<<17 - 1] = 1;
        //b = rdtsc();
        
        //printf("%llu\n", b-a);
   
        int l;
        for (l=0; l <(1<<8);l++)
        {    
        j += (1<<(v-3)) + 2347853;
        j %= (1<<v);
   
        array1[j] = j;
        }
        
        j += (1<<(v-2)) + 13432453;
        j %= (1<<v);
        a = rdtsc();
        array2[j] = j;
        b = rdtsc();
        if ((b-a) > 100000 && (b-a) < 40000000)
        printf("%llu\n", b-a);
        
        j += (1<<(v-2)) + 34242353;
        j %= (1<<v);
        
        a=b;
        array2[j] = j;
        b = rdtsc();
        if ((b-a) > 100000)
        printf("%llu\n", b-a); 
        for (l=0; l <(1<<8);l++)
        {    
        j += (1<<(v-2)) + 34123453;
        j %= (1<<v);
   
        array2[j] = j;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
            
    }
    free(array1);
    free(array2);
        

}


void* thread_1_(void* p)
{
    thread_1(p);
    return NULL;
}
void* thread_2_(void* p)
{
    thread_2(p);
    return NULL;
}


int thread_1(void* p)
{
    unsigned long long a,b;
    char buf_1 = 'A',buf_2 = 'A';
    srand(1);
    int k;
    
    //close(pipefd_1[0]);
    //close(pipefd_2[1]);          

    for (k = 0; k < n1; k++)
    {
        //buf_1 = rand()%26 + 'A';
        //printf("child send: %c\n", buf_1);
        write(pipefd_1[1], &buf_1, 1); 
        read(pipefd_2[0], &buf_2, 1);
        //printf("child read: %c\n", buf_2);
    }
    //close(pipefd_1[1]);
    //close(pipefd_2[0]);
    
    printf("thread 1 exits\n");
    return 0;
}

int thread_2(void* p)
{
    unsigned long long a,b;
    char buf_1 = 'A',buf_2 = 'A';
    srand(2);
    int k;

    //close(pipefd_1[1]);
    //close(pipefd_2[0]);          
        
    a = rdtsc();    
    for (k = 0; k < n1; k++)
    {      
        read(pipefd_1[0], &buf_1, 1); 
        //printf("parent read: %c\n", buf_1);
        //buf_2 = rand()%26 + 'A';   
        //printf("parent send: %c\n", buf_2);    
        write(pipefd_2[1], &buf_2, 1);
        
    }
    b = rdtsc();
    printf("2*read+2*write+2*ctxswc = %.3f\n", (double)(b-a)/n1); 
    //close(pipefd_1[0]);  
    //close(pipefd_2[1]);  
    
    printf("thread 2 exits\n");
    return 0;
}

void test_kth_ctx_switch()
{
    test_pipe_baseline();
    pid_t cpid_1, cpid_2;  
    const int stack_size = 16384;
    char* stack_1, *stack_2;
    char* stacktop_1, *stacktop_2;
    
    stack_1 = malloc(stack_size);
    stacktop_1 = stack_1 + stack_size;
    stack_2 = malloc(stack_size);
    stacktop_2 = stack_2 + stack_size;
    
    if (pipe(pipefd_1) == -1 || pipe(pipefd_2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    cpid_1 = clone(thread_1, stacktop_1, CLONE_VM | CLONE_FILES | CLONE_FS | CLONE_IO | CLONE_SIGHAND | SIGCHLD, NULL);
    cpid_2 = clone(thread_2, stacktop_2, CLONE_VM | CLONE_FILES | CLONE_FS | CLONE_IO | CLONE_SIGHAND | SIGCHLD, NULL);
    
    if (cpid_1 == -1 || cpid_2 == -1)
    {
        perror("clone");
        exit(EXIT_FAILURE);
    }
    
    if (waitpid(cpid_1, NULL, 0) == -1)
    {
        perror("wait");
        exit(EXIT_FAILURE);
    }
    if (waitpid(cpid_2, NULL, 0) == -1)
    {
        perror("wait");
        exit(EXIT_FAILURE);
    }
}



void test_ctx_switch()
{
    pid_t cpid;
    unsigned long long a,b;
    char buf_1 = 'A',buf_2 = 'A';
   
    test_pipe_baseline();


    if (pipe(pipefd_1) == -1 || pipe(pipefd_2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // child process
    if (cpid == 0) 
    {
        srand(1);
        int k;
        
        char* buffer = malloc(1<<31);
        if (buffer == NULL)
        {
            wait(NULL);
            return 0;
        }
        for (k = 0; k < n1; k++)
            buffer[k] = '0';
        
        close(pipefd_1[0]);
        close(pipefd_2[1]);          
  
        for (k = 0; k < n1; k++)
        {
            //buf_1 = rand()%26 + 'A';
            //printf("child send: %c\n", buf_1);
            //printf("child sending.. k = %d, %llu\n",k, rdtsc());
            write(pipefd_1[1], &buf_1, 1); 
            read(pipefd_2[0], &buf_2, 1);
            //printf("child read: %c\n", buf_2);
        }
        close(pipefd_1[1]);
        close(pipefd_2[0]);
        
        free(buffer);

    } 
    // parent process
    else 
    {
        srand(2);
        fp = fopen("res_ctx_switch.txt","w");
        int k;
        
        char* buffer = malloc(1<<31);
        if (buffer == NULL)
        {
            wait(NULL);
            return 0;
        }
        
        
        
        for (k = 0; k < n1; k++)
            buffer[k] = '1';    
        
        close(pipefd_1[1]);
        close(pipefd_2[0]);          
                
                
        a = rdtsc();
        for (k = 0; k < n1; k++)
        {
            //printf("parent waiting.. k = %d, %llu\n",k, rdtsc());
            read(pipefd_1[0], &buf_1, 1); 
            //printf("2 ctx switch time %llu\n", b-a);
            //printf("b1 - a1 = %llu, b1 = %llu, a1 = %llu\n", b1-a1, b1, a1);
            //fprintf(fp,"%llu\n", b1-a1);
            //printf("parent read: %c\n", buf_1);
            //buf_2 = rand()%26 + 'A';   
            //printf("parent send: %c\n", buf_2);    
            write(pipefd_2[1], &buf_2, 1);
        }
        b = rdtsc();
        printf("2*read+2*write+2*ctxswc = %.3f\n", (double)(b - a) / n1);
        
        close(pipefd_1[0]);  
        close(pipefd_2[1]);   
        
        wait(NULL); 
        free(buffer);                 
    }
}

void test_pipe_baseline()
{
    int pipefd[2];
    unsigned long long a,b;
    
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    char buf_1 = 'A',buf_2 = 'A';
    
    a = rdtsc();
    for (i = 0; i < n1; i++)
    {
        write(pipefd[1], &buf_1, 1);
        read(pipefd[0], &buf_2, 1);
    }
    b = rdtsc();
    printf("read + write: %.3f\n", (double)(b - a) / n1);
    close(pipefd[0]);
    close(pipefd[1]);
}

// test_read time()
// measure the time overhead of two subsequent reading time stamp counters in CPU
void test_read_time()
{
    for (i = 0; i < n1; i++)
    {
        //another way is to try directly using subl in assembly, but it turns out these two approaches' performance does not differ much.
        //int diff, dummy, a, b;
        //__asm__ volatile ("rdtsc \n\t" \
                              "movl %%eax, %%ebx \n\t" \
                              "rdtsc \n\t" \
                              "subl %%ebx, %%eax \n\t" \
             : "=a" (diff), "=b" (dummy) \
             : \
             :);               
        //printf("%d ", diff);      
        a = rdtsc();
        b = rdtsc();
        printf("%d\n", b - a);      
    }

    return;
}
	
// test_for()
// measure the time overhead of a empty loop which only loops once
void test_for()
{

    int j;
    for(i=0;i<n1;i++)
    {
        a = rdtsc();
        
        for(j=0; j<1;j++){}
        
        b = rdtsc();
        printf("%llu\n", b - a);
    }
  
 }
 
 // test_procedure()
 // measure the overhead of calling procedures with parameters varying from 0 to 7
 void test_procedure()
 {
       
    int arg0, arg1, arg2, arg3, arg4, arg5, arg6;
 
    for(i=0;i<n1;i++)
    {
        a=rdtsc();
        proc0();
        printf("%llu ", b-a);
 
        a=rdtsc();
        proc1(arg0);
        printf("%llu ", b-a);
 
        a=rdtsc();
        proc2(arg0,arg1);
        printf("%llu ", b-a);
 
        a=rdtsc();
        proc3(arg0,arg1,arg2);
        printf("%llu ", b-a);
 
        a=rdtsc();
        proc4(arg0,arg1,arg2,arg3);
        printf("%llu ", b-a);
  
        a=rdtsc();
        proc5(arg0,arg1,arg2,arg3,arg4);
        printf("%llu ", b-a);
 
        a=rdtsc();
        proc6(arg0,arg1,arg2,arg3,arg4,arg5);
        printf("%llu ", b-a);
        
        a=rdtsc();
        proc7(arg0,arg1,arg2,arg3,arg4,arg5,arg6);
        printf("%llu\n", b-a);
    }
 
 }
 
 // test_syscall()
 // measure the overhead of a minimum system call. According to our knowledge, the getpid() and time(time_t*) is the ones with lightest weight.
 void test_syscall()
 {
 
    for (i=0;i<n1;i++){
        a = rdtsc();
        pid = getpid();
        b = rdtsc();
        printf("%llu ", b-a);
        
        a = rdtsc();
        time(&t);
        b = rdtsc();
        printf("%llu\n", b-a);
        
    }
    printf("%d",pid);
 }
 
 // test_creat_proc()
 // measure the overhead of creating a process. We use fork() in our implementation, measuring the time difference before and after fork() in parent process.
void test_creat_proc()
{
    fp = fopen("test_creat_proc.txt","w");
    for (i=0;i<n1;i++)
    {
        a = rdtsc();
        pid = fork();
        b = rdtsc();
        
        if (pid == -1)
        {
            printf("fork error\n");
        }
        else if (pid == 0)
        {
            //printf("C:%llu ",b-a); 
            //sleep(1);
            return;    
        }
        else
        {    
            //wait for the child process to exit so that it does not creat child out of control
            wait(NULL);
            printf("%llu %d\n",b-a,i);
            fprintf(fp,"%llu\n",b-a);
        }
    }
    fclose(fp);
}
 
int dummy(void* p)
{
    return 0;
}

void* dummy2(void* p)
{
    return NULL;
}

void test_creat_kth_2()
{
    int s, stack_size = 16384, res;
    for (i = 0; i < n1; i++)
    {
        pthread_t tid;
        pthread_attr_t attr;
        
        s = pthread_attr_init(&attr);
        if (s != 0)
            handle_error_en(s, "pthread_attr_init");
        
        if (stack_size > 0) 
        {
            s = pthread_attr_setstacksize(&attr, stack_size);
            if (s != 0)
                handle_error_en(s, "pthread_attr_setstacksize");
        }
        
        a = rdtsc();
        pthread_create(&tid, &attr, &dummy2);
        b = rdtsc();
        
        printf("pth_creat: %llu\n", b - a);
        
        s = pthread_join(tid, &res);
        if (s != 0)
            handle_error_en(s, "pthread_join");
    }
}

void test_kth_ctx_switch2()
{
    test_pipe_baseline();
    pthread_t tid_1, tid_2;
    pthread_attr_t attr;
    int stack_size = 16384, s, res;
    
    if (pipe(pipefd_1) == -1 || pipe(pipefd_2) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    
    s = pthread_attr_init(&attr);
    if (s != 0)
        handle_error_en(s, "pthread_attr_init");
    
    if (stack_size > 0) 
    {
        s = pthread_attr_setstacksize(&attr, stack_size);
        if (s != 0)
            handle_error_en(s, "pthread_attr_setstacksize");
    }
    
    pthread_create(&tid_1, &attr, &thread_1_);
    pthread_create(&tid_2, &attr, &thread_2_);
    
    s = pthread_join(tid_1, &res);
    if (s != 0)
        handle_error_en(s, "pthread_join");
    s = pthread_join(tid_2, &res);
    if (s != 0)
        handle_error_en(s, "pthread_join");


}
void test_creat_kth()
{
    pid_t cpid;  
    const int stack_size = 16384;
    char* stack;
    char* stacktop;
    
    stack = malloc(stack_size);
    stacktop = stack + stack_size;
    

    for (i=0;i<n1;i++)
    {
        a = rdtsc();
        cpid = clone(dummy, stacktop, CLONE_VM | CLONE_FILES | SIGCHLD, NULL);
        b = rdtsc();
        
        printf("%llu\n", b - a);
        printf("cpid = %d\n", cpid);
           
        if (cpid == -1)
        {
            perror("clone");
            exit(EXIT_FAILURE);
        }
        
        if (waitpid(cpid, NULL, 0) == -1)
        {
            perror("wait");
            exit(EXIT_FAILURE);
        }   
    }
}

 //dummy functions for testing the procedure call
 void proc0()
 {
    b=rdtsc();
 }
 
 void proc1(int a1)
 {
    b=rdtsc();
 }
 
 void proc2(int a1, int a2)
 {
    b=rdtsc();
 }
 
 void proc3(int a1, int a2, int a3)
 {
    b=rdtsc();
 }
 
 void proc4(int a1, int a2, int a3, int a4)
 {
    b=rdtsc();
 }
 
 void proc5(int a1, int a2, int a3, int a4, int a5)
 {
    b=rdtsc();
 }
 void proc6(int a1, int a2, int a3, int a4, int a5, int a6)
 {
    b=rdtsc();
 }
 void proc7(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
 {
    b=rdtsc();
 }
 
