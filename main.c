#include <immintrin.h>
#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include<limits.h>
#include <sys/time.h>
static double get_time(struct timespec *start, struct timespec *end) {
	return end->tv_sec - start->tv_sec +
		(end->tv_nsec - start->tv_nsec) * 1e-9;
}

int main(){
	    asm volatile(
    "vxorps %%ymm0, %%ymm0, %%ymm0\n"
    "vxorps %%ymm1, %%ymm1, %%ymm1\n"
    "vxorps %%ymm2, %%ymm2, %%ymm2\n"
    "vxorps %%ymm3, %%ymm3, %%ymm3\n"
    "vxorps %%ymm4, %%ymm4, %%ymm4\n"
    "vxorps %%ymm5, %%ymm5, %%ymm5\n"
    "vxorps %%ymm6, %%ymm6, %%ymm6\n"
    "vxorps %%ymm7, %%ymm7, %%ymm7\n"
    "vxorps %%ymm8, %%ymm8, %%ymm8\n"
    "vxorps %%ymm9, %%ymm9, %%ymm9\n"
    "vxorps %%ymm10, %%ymm10, %%ymm10\n"
    "vxorps %%ymm11, %%ymm11, %%ymm11\n"
     ::: "ymm0","ymm1","ymm2","ymm3","ymm4","ymm5","ymm6"
    ,"ymm7","ymm8","ymm9","ymm10","ymm11"
    );
    int loop_cnt = 500000000;
    int i = loop_cnt;
    for(;i;i -= 1){
		asm volatile(
		"vfmadd231ps %%ymm0, %%ymm0, %%ymm0\n"
		"vfmadd231ps %%ymm1, %%ymm1, %%ymm1\n"
		"vfmadd231ps %%ymm2, %%ymm2, %%ymm2\n"
		"vfmadd231ps %%ymm3, %%ymm3, %%ymm3\n"
		"vfmadd231ps %%ymm4, %%ymm4, %%ymm4\n"
		"vfmadd231ps %%ymm5, %%ymm5, %%ymm5\n"
		"vfmadd231ps %%ymm6, %%ymm6, %%ymm6\n"
		"vfmadd231ps %%ymm7, %%ymm7, %%ymm7\n"
		"vfmadd231ps %%ymm8, %%ymm8, %%ymm8\n"
		"vfmadd231ps %%ymm9, %%ymm9, %%ymm9\n"
        "vfmadd231ps %%ymm10, %%ymm10, %%ymm10\n"
		"vfmadd231ps %%ymm11, %%ymm11, %%ymm11\n"
		 ::: "ymm0","ymm1","ymm2","ymm3","ymm4","ymm5","ymm6"
		,"ymm7","ymm8","ymm9","ymm10","ymm11"
		);
	}
    i = loop_cnt;
    struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	for(;i;i -= 1){
		asm volatile(
		"vfmadd231ps %%ymm0, %%ymm0, %%ymm0\n"
		"vfmadd231ps %%ymm1, %%ymm1, %%ymm1\n"
		"vfmadd231ps %%ymm2, %%ymm2, %%ymm2\n"
		"vfmadd231ps %%ymm3, %%ymm3, %%ymm3\n"
		"vfmadd231ps %%ymm4, %%ymm4, %%ymm4\n"
		"vfmadd231ps %%ymm5, %%ymm5, %%ymm5\n"
		"vfmadd231ps %%ymm6, %%ymm6, %%ymm6\n"
		"vfmadd231ps %%ymm7, %%ymm7, %%ymm7\n"
		"vfmadd231ps %%ymm8, %%ymm8, %%ymm8\n"
		"vfmadd231ps %%ymm9, %%ymm9, %%ymm9\n"
        "vfmadd231ps %%ymm10, %%ymm10, %%ymm10\n"
		"vfmadd231ps %%ymm11, %%ymm11, %%ymm11\n"
		 ::: "ymm0","ymm1","ymm2","ymm3","ymm4","ymm5","ymm6"
		,"ymm7","ymm8","ymm9","ymm10","ymm11"
		);
	}
   	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    double time_use_s = get_time(&start, &end);
    long nflops = (long)loop_cnt * 12 * 8 * 2;
    printf("glops is %g\n",((double)nflops)/time_use_s * 1e-9);
    return 0;
}
