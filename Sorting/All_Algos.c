#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define ll long long int

ll i, j, key;
ll min_index_selection = 0;
ll swaps_count_selection = 0;
ll swaps_quick = 0;

void swap(ll a, ll b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}

void reverse_array(ll arr[])
{
    for (i = 0; i < N / 2; i++)
    {
        swap(arr[i], arr[N - i - 1]);
    }
}

bool isSorted(ll arr[])
{
    for (i = 0; i < N - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            return false;
        }
        return true;
    }
}

//  I N S E R T I O N    S O R T
void insertion_sort(ll arr[])
{
    ll comparisons_insertion = 0;
    for (i = 1; i < N; i++)
    {
        key = arr[i];
        for (j = i - 1; j >= 0; j--)
        {
            comparisons_insertion++;
            if (key < arr[j])
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = key;
    }
    printf("The Number of Comparisons in Insertion Sort are %llu\n", comparisons_insertion);
}

// S E L E C T I O N     S O R T
void selection_sort(ll arr[])
{
    ll comparisons_selection = 0;

    for (i = 0; i < N - 1; i++)
    {
        min_index_selection = i;
        for (j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_index_selection])
            {
                min_index_selection = j;
            }
            comparisons_selection++;
        }

        if (min_index_selection = 0 != i)
        {
            swap(arr[min_index_selection], arr[i]);
            swaps_count_selection++;
        }
    }
    printf("The Number of Comparisons in Selection Sort are %llu\n", comparisons_selection);
}

//  Q U I C K     S O R T

ll comparisons_quick = 0;
ll partition(ll arr[], ll s, ll e)
{
    // starting element of that array ( PIVOT )
    ll pivot = arr[s];

    // counting numbers less than equal to pivot to allocate them to the left of the pivot
    ll cnt = 0;
    for (ll i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            comparisons_quick++;
            cnt++;
        }
    }
    // Finding the PivotIndex and replacing it with that element on it
    ll pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);
    swaps_quick++;

    // Create 2 pointers for making partition
    ll i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
        {
            comparisons_quick++;
            i++;
        }
        while (arr[j] > pivot)
        {
            comparisons_quick++;
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            comparisons_quick++;
            swap(arr[i++], arr[j--]);
            swaps_quick++;
        }
    }
    return pivotIndex;
}

void quickSort(ll arr[], ll s, ll e)
{

    if (s >= e)
    {
        return;
    }
    // finding Partitioning Index
    ll ind = partition(arr, s, e);

    // Recursive Call for left side
    quickSort(arr, s, ind - 1);
    quickSort(arr, ind + 1, e);
}

//  M E R G E   S O R T
ll comparisons_merge = 0;
void merge(ll arr[], ll start, ll end)
{
    ll mid = start + (end - start) / 2;
    ll len1 = mid - start + 1;
    ll len2 = end - mid;

    ll arr1[len1];
    ll arr2[len2];

    ll mainArrayIndex = start;

    for (i = 0; i < len1; i++)
    {
        arr1[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for (i = 0; i < len2; i++)
    {
        arr2[i] = arr[mainArrayIndex++];
    }

    int ind1 = 0, ind2 = 0;
    mainArrayIndex = start;

    while (ind1 < len1 && ind2 < len2)
    {
        if (arr1[ind1] < arr2[ind2])
        {
            comparisons_merge++;
            arr[mainArrayIndex++] = arr1[ind1++];
        }
        else
        {
            arr[mainArrayIndex++] = arr2[ind2++];
        }
    }
    while (len1 > ind1)
    {
        arr[mainArrayIndex++] = arr1[ind1++];
    }

    while (len2 > ind2)
    {
        arr[mainArrayIndex++] = arr2[ind2++];
    }
}

void mergeSort(ll arr[], ll start, ll end)
{

    if (start >= end)
    {
        return;
    }
    ll mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);

    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

void calculateTime(ll arr[], ll start, ll end)
{

    clock_t time;
    time = clock();
    insertion_sort(arr);
    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time for N = %d is  %.18lf seconds\n", N, time_taken);
    

    time = clock();
    selection_sort(arr);
    time = clock() - time;
    time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Selection Sort Time for N = %d is %.18lf seconds\n", N, time_taken);
    printf("Selection Sort Swaps for N = %d is  %llu \n", N,swaps_count_selection);

    time = clock();
    quickSort(arr, start, end);
    time = clock() - time;
    time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Quick Sort Time for N = %d is  %.18lf seconds\n", N, time_taken);
    printf("Quick Sort Swaps for N = %d is  %llu \n", N,swaps_quick);

    time = clock();
    mergeSort(arr, start, end);
    time = clock() - time;
    time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("Merge Sort Time for N = %d is  %.18lf seconds\n", N, time_taken);
    // printf("*********************************\n");
}

int main()
{
    ll arr[N];

    for (i = 0; i < N; i++)
    {
        arr[i] = rand();
    }
    //  ******************   A V E R A G E   C A S E    ****************

    printf("\nAverage Case\n");
    calculateTime(arr, 0, N - 1);

    printf("The Number of Comparisons in Quick Sort are %llu\n", comparisons_quick);
    printf("The Number of Comparisons in Merge Sort are %llu\n", comparisons_merge);

    printf("******************************************************\n\n");

    // *****************     B E S T    C A S E   *******************

    printf("\nBest Case\n");
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n") : printf("The Array is not Sorted :( \n");
    calculateTime(arr, 0, N - 1);
    printf("The Number of Comparisons in Quick Sort are %llu\n", comparisons_quick);
    printf("The Number of Comparisons in Merge Sort are %llu\n", comparisons_merge);

    printf("******************************************************\n\n");

    //   *****************      W O R S T   C A S E     ********************

    printf("\nWorst Case\n");
    reverse_array(arr);
    calculateTime(arr, 0, N - 1);
    printf("The Number of Comparisons in Quick Sort are %llu\n", comparisons_quick);
    printf("The Number of Comparisons in Merge Sort are %llu\n", comparisons_merge);
}