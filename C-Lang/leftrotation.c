#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* leftRotation(int* a, int d, int *result_size) {
    int temp=a[0],i;
    for(i=0;i<=d;i++){
      a[i]=a[i+1];
    }
    a[i+1]=temp;
    for(i=0;i<)
    return &result_size;
}

int main() {
    int n;
    int d;
    scanf("%i %i", &n, &d);
    int *a = malloc(sizeof(int) * n);
    for (int a_i = 0; a_i < n; a_i++) {
       scanf("%i",&a[a_i]);
    }
    int result_size;
    int* result = leftRotation(a, d, &result_size);
    for(int result_i = 0; result_i < result_size; result_i++) {
        if(result_i) {
            printf(" ");
        }
        printf("%d", result[result_i]);
    }
    puts("");


    return 0;
}
