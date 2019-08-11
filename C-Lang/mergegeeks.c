#include<stdlib.h>
#include<stdio.h>
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{  printf("Merge function called\n");

    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];
    printf("Left array filling ahead\n");

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    printf("Right array filling ahead\n");
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    printf("Merge function concludes\n");

}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)

{

  printf("MergeSort function begins\n");
  printArray(arr, r+1);
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
        printf("Merge sort recursion for first called ahead\n");
        // Sort first and second halves
        mergeSort(arr, l, m);
        printArray(arr, r+1);
        printf("Merge sort recursion for second called ahead\n");
        mergeSort(arr, m+1, r);
        printArray(arr, r+1);
        printf("Merge call ahead\n");
        printArray(arr, r+1);
        merge(arr, l, m, r);
        printArray(arr, r+1);

    }
    printf("MergeSort function concludes\n");

}

/* UTILITY FUNCTIONS */
/* Function to print an array */


/* Driver program to test above functions */
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);
    printf("\nMerge Sort called for the first time ahead\n");

    mergeSort(arr, 0, arr_size - 1);
    printf("Code Compiled Successfully\nPrinting Ahead\n");

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
