#include <iostream>
#include <vector>

using namespace std;

int find_peak_entry(vector<int> &A)
{
    int n = A.size();
    int left = 0, right = n - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (A[mid] < A[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

void printArr(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i] << "  ";
    }
}

int main()
{
    vector<int> A = {1, 3, 5, 7, 9, 19, 8, 6, 4, 2};
    int peak_entry = find_peak_entry(A);

    cout << " \nPeak entry in the array : { ";
    printArr(A);
    cout << " }  is "
         << A[peak_entry] << "\n\n";
}
