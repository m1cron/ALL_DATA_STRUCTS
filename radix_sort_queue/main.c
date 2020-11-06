#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include "queue.h"

int select_digit (int number, int place) 
{ return number/place % 10; }

void radix_sort(int a[], int length) {
    unsigned long long c = 0, m = 0;

	const int MAX_DIGIT = 6;
	const int NUM_BINS = 10;
	const int RADIX = 10;

	queue *bins[NUM_BINS];
	for(int i = 0; i < NUM_BINS; i++)
		bins[i] = createQueue(8192);

	for (int d = 1, place = 1; d <= MAX_DIGIT; place *= RADIX, ++d) {
        c++;
        for (int i = 0; i < length; ++i) {
            enqueue(bins[select_digit(a[i], place)], a[i]);
            m++;
        }

        int a_pos = 0;
        for (int i = 0; i < NUM_BINS; ++i) {
            c++;
            while (!isEmpty(bins[i])) {
                a[a_pos++] = front(bins[i]);
                dequeue(bins[i]);
                m++;
            }
        }
    }

    printf("----\tn = %d\t%llu\t%llu\t----\n", length, c, m);

	for(int i = 0; i < NUM_BINS; i++)
		free(bins[i]);
}

void arrFill(int* arr, int N) {
    for (long long i = 0; i < N; i++) {
        arr[i] = rand() % 1000;
    }
}

void arrBest(int* arr, int N){
    for(int i = 0; i < N; i++)
        arr[i] = i;
}

void arrBad(int* arr, int N){
    for(int i = N - 1; i >= 0; i--)
        arr[i] = i;
}

int main(void){
    int a, a2;
    printf("Введите 1 или 2 >>>");
    std::cin >> a;
    if (a == 1){
        int *arr = (int *)malloc(sizeof(int) * 10);
        for(int i = 0; i < 10; i++)
            std::cin >> arr[i];
        radix_sort(arr, 10);
    }else{
        for(int i = 1000; i <= 5000; i+= 1000){
            int *arr = (int *)malloc(sizeof(int) * i);
            arrFill(arr, i);
            radix_sort(arr, i);
            free(arr);

            arr = (int *)malloc(sizeof(int) * i);
            arrBest(arr, i);
            radix_sort(arr, i);
            free(arr);

            arr = (int *)malloc(sizeof(int) * i);
            arrBad(arr, i);
            radix_sort(arr, i);
            free(arr);
            printf("-------------------------\n");
        }
    }
    return 0;
}