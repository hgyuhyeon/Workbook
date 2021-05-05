#define HAVE_STRUCT_TIMESPEC
#define _CRT_SECURE_NO_WARNINGS
#include <pthread.h>
#include <stdio.h>

void *sum(int num) {
	int sum = 0;
	for (int i = 1; i <= num; i++) {
		//printf("sum %d 실행중\n", i); //debug
		sum += i;
	}
	printf("sum = %d\n", sum);
	return NULL;
}

void *factorial(int num) {
	long long fac = 1;
	for (int i = 2; i <= num; i++) {
		//printf("factorial %d 실행중\n", i); //debug
		fac *= i;
	}
	printf("factorial = %lld\n", fac);
	return NULL;
}

int main(void) {

	pthread_t _t1, _t2;
	int n, status;
	scanf("%d", &n);
	
	pthread_create(&_t1, NULL, sum, (int)n);
	pthread_create(&_t2, NULL, factorial, (int)n);

	pthread_join(_t1, (void**)&status);
	pthread_join(_t2, (void**)&status);

	return 0;
}
