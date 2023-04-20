#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int finalPath[N + 1];
bool visited[N];
int finalResult = INT_MAX;

void copyToFinal(int currPath[])
{
    for (int i = 0; i < N; i++)
    {
        finalPath[i] = currPath[i];
    }
    finalPath[N] = currPath[0];
}

int firstMin(int adj[N][N], int i)
{
    int min = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (adj[i][j] < min && i != j)
        {
            min = adj[i][j];
        }
    }
    return min;
}

int secondMin(int adj[N][N], int i)
{
    int first = INT_MAX;
    int second = INT_MAX;
    for (int j = 0; j < N; j++)
    {
        if (i == j){
            continue;
        }
        if (adj[i][j] <= first){
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first){
            second = adj[i][j];
        }
    }
    return second;
}

void TSPRec(int adj[N][N], int lowerbound, int currWeight, int level, int currPath[])
{
    if (level == N)
    {
        if (adj[currPath[level - 1]][currPath[0]] != 0)
        {
            int currResult = currWeight + adj[currPath[level - 1]][currPath[0]];
            if (currResult < finalResult)
            {
                copyToFinal(currPath);
                finalResult = currResult;
            }
        }
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (adj[currPath[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = lowerbound;
            currWeight += adj[currPath[level - 1]][i];

            if (level == 1){
                lowerbound -= ((firstMin(adj, currPath[level - 1]) + firstMin(adj, i)) / 2);
            }
            else
            {
                lowerbound -= ((secondMin(adj, currPath[level - 1]) + firstMin(adj, i)) / 2);
            }

            if (lowerbound + currWeight < finalResult)
            {
                currPath[level] = i;
                visited[i] = true;
                TSPRec(adj, lowerbound, currWeight, level + 1, currPath);
            }

            currWeight -= adj[currPath[level - 1]][i];
            lowerbound = temp;

            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
            {
                visited[currPath[j]] = true;
            }
        }
    }
}

void TSP(int adj[N][N])
{
    int currPath[N + 1];
    int lowerbound = 0;
    memset(currPath, -1, sizeof(currPath));
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++)
    {
        lowerbound += (firstMin(adj, i)) + secondMin(adj, i);
    }

    lowerbound = (lowerbound & 1) ? lowerbound / 2 + 1 : lowerbound / 2;

    visited[0] = true;
    currPath[0] = 0;

    TSPRec(adj, lowerbound, 0, 1, currPath);
}

int main()
{
    int adj[4][4] = {{2, 23, 15, 21},
                     {10, 1, 35, 23},
                     {15, 39, 1, 25},
                     {18, 25, 30, 4}};

    TSP(adj);

    cout << "\n\nMinimum cost : " << finalResult << endl;
    cout << "Optimal path is as traced : ";
    for (int i = 0; i <= N; i++)
    {
        cout << finalPath[i] << "  ";
    }
    cout << "\n\n";
}