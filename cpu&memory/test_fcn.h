/*
    test_fcn.h - main testing time overhead for CPU operations
    Charlie Chen, Chicheng Zhang
*/
#pragma once
#include <sched.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "rdtsc.h"
#include <sys/wait.h>
#include <linux/sched.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


#define handle_error_en(en, msg) \
do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

unsigned long long a,b,count,c;
int i, n1;
time_t t;
pid_t pid;
int stat;
FILE* fp;
int pipefd_1[2]; // parent read, child write
int pipefd_2[2]; // child read, parent write
//int arr[(1<<28)];

void test_mem_lat();
void test_mem_bw();
void test_pg_flt();
void* thread_1_(void* p);
void* thread_2_(void* p);
int thread_1(void* p);
int thread_2(void* p);
void test_kth_ctx_switch();
void test_ctx_switch();
void test_pipe_baseline();
void test_read_time();
void test_for();
void test_procedure();
void test_syscall();
void test_creat_proc();
int dummy(void* p);
void* dummy2(void* p);
void test_creat_kth_2();
void test_kth_ctx_switch2();
void test_creat_kth();
void proc0();
void proc1(int a1);
void proc2(int a1, int b1);
void proc3(int a1, int a2, int a3);
void proc4(int a1, int a2, int a3, int a4);
void proc5(int a1, int a2, int a3, int a4, int a5);
void proc6(int a1, int a2, int a3, int a4, int a5, int a6);
void proc7(int a1, int a2, int a3, int a4, int a5, int a6, int a7);

