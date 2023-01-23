#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 1000

void swap(int a, int b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

int partition(int *arr, int s, int e)
{
    int pivotElement = arr[s];
    int count = 0;
    for (int i = s + 1; i < e; i++)
    {
        if (arr[i] <= pivotElement)
        {
            count++;
        }
    }
    int pivotIndex = count + pivotElement;
    swap(arr[pivotElement], arr[pivotIndex]);

    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= arr[pivotElement])
        {
            i++;
        }
        while (arr[i] > arr[pivotElement])
        {
            j--;
        }
        if (i > pivotIndex && j < pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
}

void quick_sort(int *arr, int s, int e)
{
    int ind = partition(arr, s, e);
    
    quick_sort(arr, s, ind - 1);
    quick_sort(arr, ind + 1, e);
}

double calculateTime(int *arr)
{
    clock_t time;
    time = clock();

    quick_sort(arr, 0, N - 1);

    time = clock() - time;
    double time_taken = ((double)time / CLOCKS_PER_SEC);

    printf("The Time Taken for Quick Sort is %.12f ", time_taken);
}

int main()
{
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = rand();
    }

    quick_sort(arr, 0, N - 1);
}