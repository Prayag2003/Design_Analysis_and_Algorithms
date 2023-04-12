#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int> &v, int s, int e)
{
    int mid = s + (e - s) / 2;
    if (v[mid] < v[mid + 1])
    {
        return binSearch(v, mid + 1, e);
    }
    else
        return binSearch(v, s, mid - 1);
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 9, 7, 0, -1, -2};
    int s = 0, e = v.size() - 1;
    cout << binSearch(v, s, e);
}