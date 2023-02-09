#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define ll long long int
ll comparisons = 0;
ll swaps = 0;
ll i, j;

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
            comparisons++;
            cnt++;
        }
    }

    // Finding the PivotIndex and replacing it with that element on it
    ll pivotIndex = s + cnt;
    swap(arr[s], arr[pivotIndex]);
    swaps++;

    // Create 2 pointers for making partition
    ll i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        comparisons++;
        while (arr[i] < pivot)
        {
            comparisons++;
            i++;
        }
        while (arr[j] > pivot)
        {
            comparisons++;
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            comparisons++;
            swap(arr[i++], arr[j--]);
            swaps++;
        }
    }
    return pivotIndex;
}

// ll partition(ll arr[], ll start, ll end)
// {
//     // considering the right most element  as the pivot ele

//     ll pivot = arr[end];

//     // element index for comparison
//     i = (start - 1);

//     for (j = start; j < end; j++)
//     {
//         comparisons++;
//         if (arr[j] <= pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//             swaps++;
//         }
//     }
//     // Placing pivot at it correct position
//     swap(arr[i + 1], arr[end]);
//     swaps++;

//     // returning index for next pivot
//     return i + 1;
// }

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

void calculateTime(ll arr[], ll start, ll end)
{
    clock_t time;
    time = clock();

    quickSort(arr, 0, N - 1);

    time = clock() - time;
    double time_taken = ((double)time) / CLOCKS_PER_SEC;

    printf("The Time taken is equal to %.18lf seconds\n", time_taken);
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
    printf("%llu \n", comparisons);
    printf("%llu \n", swaps);
    comparisons = 0;
    swaps = 0;

    //   *****************      B E S T    C A S E    *******************
    // comparisons = 0;
    // swaps = 0;
    printf("\nBest Case\n");
    isSorted(arr) ? printf("\nThe Array is Sorted , All is Well\n") : printf("The Array is not Sorted :( \n");
    calculateTime(arr, 0, N - 1);
    printf("\n");
    printf("%llu \n", comparisons);
    printf("%llu \n", swaps);
    comparisons = 0;
    swaps = 0;

    //   *****************      W O R S T   C A S E     ********************

    // comparisons = 0;
    // swaps = 0;
    printf("\nWorst Case\n");
    reverse_array(arr);
    calculateTime(arr, 0, N - 1);
    printf("\n");
    printf("%llu \n", comparisons);
    printf("%llu \n", swaps);

}
