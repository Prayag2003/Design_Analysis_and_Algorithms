#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/* Comparator Function according to the End Time */
bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    return a.second < b.second;
}

int main()
{

    cout << "Enter the number of Subjects : ";
    int numberOfSubjects;
    cin >> numberOfSubjects;
    vector<pair<int, int>> timeTable;

    do
    {
        /* Jump here if endTime < startTime*/
    enterAgain:

        ll start_time, end_time;
        string subject;
        cout << "\nEnter the subject : ";
        cin >> subject;
        cout << "Enter the Start Time : ";
        cin >> start_time;
        cout << "Enter the End Time : ";
        cin >> end_time;

        if (end_time < start_time)
        {
            cout << "  !! Invalid End Time !! \n It cannot be lesser than start time !! ";
            goto enterAgain;
        }

        timeTable.push_back({start_time, end_time});
        numberOfSubjects--;

    } while (numberOfSubjects);

    /* Sorting with respect to End Time */
    sort(timeTable.begin(), timeTable.end(), cmp);

    ll maxSubjectsInOneDay = 1;
    for (ll i = 1; i < timeTable.size(); i++)
    {
        if (timeTable[i].first >= timeTable[i - 1].second)
        {
            maxSubjectsInOneDay++;
        }
    }

    cout << "The Number of Maximum Subjects that can be scheduled in a day are " << maxSubjectsInOneDay << "\n";
}
