#include <immintrin.h>
#include <x86intrin.h>
#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>
#include <sys/time.h>
static double get_time(struct timespec *start, struct timespec *end)
{
	return end->tv_sec - start->tv_sec +
		   (end->tv_nsec - start->tv_nsec) * 1e-9;
}

int bench_vfmadd231ps_256bit()
{
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
		"vxorps %%ymm11, %%ymm11, %%ymm11\n" ::
			: "ymm0", "ymm1", "ymm2", "ymm3", "ymm4", "ymm5", "ymm6", "ymm7", "ymm8", "ymm9", "ymm10", "ymm11");
	int loop_cnt = 500000000;
	int i = loop_cnt;
	for (; i; i -= 1)
	{
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
			"vfmadd231ps %%ymm11, %%ymm11, %%ymm11\n" ::
				: "ymm0", "ymm1", "ymm2", "ymm3", "ymm4", "ymm5", "ymm6", "ymm7", "ymm8", "ymm9", "ymm10", "ymm11");
	}
	i = loop_cnt;
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	for (; i; i -= 1)
	{
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
			"vfmadd231ps %%ymm11, %%ymm11, %%ymm11\n" ::
				: "ymm0", "ymm1", "ymm2", "ymm3", "ymm4", "ymm5", "ymm6", "ymm7", "ymm8", "ymm9", "ymm10", "ymm11");
	}
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double time_use_s = get_time(&start, &end);
	long nflops = (long)loop_cnt * 12 * 8 * 2;
	printf("256bit vfmadd231ps glops is %g\n", ((double)nflops) / time_use_s * 1e-9);
}

int bench_vfmadd231ps_512bit()
{
	asm volatile(
		"vxorps %%zmm0, %%zmm0, %%zmm0\n"
		"vxorps %%zmm1, %%zmm1, %%zmm1\n"
		"vxorps %%zmm2, %%zmm2, %%zmm2\n"
		"vxorps %%zmm3, %%zmm3, %%zmm3\n"
		"vxorps %%zmm4, %%zmm4, %%zmm4\n"
		"vxorps %%zmm5, %%zmm5, %%zmm5\n"
		"vxorps %%zmm6, %%zmm6, %%zmm6\n"
		"vxorps %%zmm7, %%zmm7, %%zmm7\n"
		"vxorps %%zmm8, %%zmm8, %%zmm8\n"
		"vxorps %%zmm9, %%zmm9, %%zmm9\n"
		"vxorps %%zmm10, %%zmm10, %%zmm10\n"
		"vxorps %%zmm11, %%zmm11, %%zmm11\n" ::
			: "zmm0", "zmm1", "zmm2", "zmm3", "zmm4", "zmm5", "zmm6", "zmm7", "zmm8", "zmm9", "zmm10", "zmm11");
	int loop_cnt = 500000000;
	int i = loop_cnt;
	for (; i; i -= 1)
	{
		asm volatile(
			"vfmadd231ps %%zmm0, %%zmm0, %%zmm0\n"
			"vfmadd231ps %%zmm1, %%zmm1, %%zmm1\n"
			"vfmadd231ps %%zmm2, %%zmm2, %%zmm2\n"
			"vfmadd231ps %%zmm3, %%zmm3, %%zmm3\n"
			"vfmadd231ps %%zmm4, %%zmm4, %%zmm4\n"
			"vfmadd231ps %%zmm5, %%zmm5, %%zmm5\n"
			"vfmadd231ps %%zmm6, %%zmm6, %%zmm6\n"
			"vfmadd231ps %%zmm7, %%zmm7, %%zmm7\n"
			"vfmadd231ps %%zmm8, %%zmm8, %%zmm8\n"
			"vfmadd231ps %%zmm9, %%zmm9, %%zmm9\n"
			"vfmadd231ps %%zmm10, %%zmm10, %%zmm10\n"
			"vfmadd231ps %%zmm11, %%zmm11, %%zmm11\n" ::
				: "zmm0", "zmm1", "zmm2", "zmm3", "zmm4", "zmm5", "zmm6", "zmm7", "zmm8", "zmm9", "zmm10", "zmm11");
	}
	i = loop_cnt;
	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC_RAW, &start);
	for (; i; i -= 1)
	{
		asm volatile(
			"vfmadd231ps %%zmm0, %%zmm0, %%zmm0\n"
			"vfmadd231ps %%zmm1, %%zmm1, %%zmm1\n"
			"vfmadd231ps %%zmm2, %%zmm2, %%zmm2\n"
			"vfmadd231ps %%zmm3, %%zmm3, %%zmm3\n"
			"vfmadd231ps %%zmm4, %%zmm4, %%zmm4\n"
			"vfmadd231ps %%zmm5, %%zmm5, %%zmm5\n"
			"vfmadd231ps %%zmm6, %%zmm6, %%zmm6\n"
			"vfmadd231ps %%zmm7, %%zmm7, %%zmm7\n"
			"vfmadd231ps %%zmm8, %%zmm8, %%zmm8\n"
			"vfmadd231ps %%zmm9, %%zmm9, %%zmm9\n"
			"vfmadd231ps %%zmm10, %%zmm10, %%zmm10\n"
			"vfmadd231ps %%zmm11, %%zmm11, %%zmm11\n" ::
				: "zmm0", "zmm1", "zmm2", "zmm3", "zmm4", "zmm5", "zmm6", "zmm7", "zmm8", "zmm9", "zmm10", "zmm11");
	}
	clock_gettime(CLOCK_MONOTONIC_RAW, &end);
	double time_use_s = get_time(&start, &end);
	long nflops = (long)loop_cnt * 12 * 16 * 2;
	printf("512bit vfmadd231ps gflop is %g\n", ((double)nflops) / time_use_s * 1e-9);
}
int main()
{
	bench_vfmadd231ps_256bit();
	bench_vfmadd231ps_512bit();
	return 0;
}
