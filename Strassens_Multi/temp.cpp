#include <bits/stdc++.h>
using namespace std;
#define N 2

int p[N][N];

/* Stresson's Multiplication */
// void stressonMultiplaction(int a[N][N], int b[N][N]) {}

int rec_MM(int a[N][N], int b[N][N])
{
    int ind = N / 2;
    if (N == 1)
    {
        return a[N][N] * b[N][N];
    }

    p[ind][ind] = rec_MM(a[ind][ind], b[ind][ind]) + rec_MM(
    a[2 * ind][ind], b[ind][2 * ind]);

    p[2 * ind][ind] = rec_MM(a[ind][ind], b[ind][2 * ind]) + rec_MM(a[2 * ind][ind], b[2 * ind][2 * ind]);

    p[ind][2 * ind] = rec_MM(a[ind][2 * ind], b[ind][ind]) + rec_MM(a[2 * ind][ind], b[ind][2 * ind]);

    p[2 * ind][2 * ind] = rec_MM(a[ind][2 * ind], b[ind][ind]) + rec_MM(a[2 * ind][ind], b[2 * ind][2 * ind]);
}

int main()
{
    cout << "Enter the Value of N : ";

    int a[N][N], b[N][N], p[N][N];

    cout << "   Enter the First Matrix \N";
    for (int row = 0; row < N; row++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> a[row][cols];
        }
    }

    cout << "   Enter the Second Matrix \N";
    for (int row = 0; row < N; row++)
    {
        for (int cols = 0; cols < N; cols++)
        {
            cin >> b[row][cols];
        }
    }
}