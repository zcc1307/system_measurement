#define _GNU_SOURCE
#include "test_fcn.h"

int main(int argc, char* argv[])
{
    n1 = 1000000;
    //Let the process works only at CPU 1, 
    //which matches isolcpus=1(let all user processes work on CPU0)
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(1,&mask);
    if (sched_setaffinity(0, sizeof(cpu_set_t),&mask) < 0)
    {
    	perror("sched_setaffinity");
    }
    
    //we will select options based on command line
    switch(argv[1][0])
    {	
        case '1':
            test_read_time();
            break;
        case '2':
            test_for();
            break;
        case '3':
            test_procedure();
            break;
        case '4':
            test_syscall();
            break;
        case '5':
            test_creat_proc();
            break;
        case '6':
            test_ctx_switch();
            break;
        case '7':
            test_mem_lat();
            break;
        case '8':
            test_kth_ctx_switch2();
            break;
        case '9':
            test_creat_kth_2();
            break;
        case 'a':
            test_pg_flt();
            break;
        case 'b':
            test_mem_bw();
            break;
    }
    
    return 0;
}
 
