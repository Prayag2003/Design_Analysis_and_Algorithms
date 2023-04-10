#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class TimeTable
{
public:
    string subject;
    int startTime;
    int endTime;

    TimeTable(string sub, int start, int end)
    {
        this->subject = sub;
        this->startTime = start;
        this->endTime = end;
    }
};

bool sortByEndTime(const TimeTable &a, const TimeTable &b)
{
    return a.endTime < b.endTime;
}

int main()
{

    cout << "Enter the number of Subjects : ";
    int numberOfSubjects;
    cin >> numberOfSubjects;
    vector<TimeTable> tt;
    vector<TimeTable> ans;

    do
    {
        /*   Jump here if endTime < startTime  */
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

        TimeTable lecture(subject, start_time, end_time);
        tt.push_back(lecture);

        numberOfSubjects--;

    } while (numberOfSubjects);

    // Sorting acc to EndTime
    sort(tt.begin(), tt.end(), sortByEndTime);

    int cnt = 1;
    int subjects = 0;

    for (auto &i : tt)
    {
        if (cnt == 1)
        {
            ans.push_back(i);
            cnt = 0;
            continue;
        }
        auto lec = tt.begin() + 1;
        auto prevIter = prev(lec);
        TimeTable prevLecture = *prevIter;

        if (i.startTime >= prevLecture.endTime)
        {
            subjects++;
            ans.push_back(i);
        }
    }
    for (auto &i : ans)
    {
        cout << i.subject << " " << i.startTime << " " << i.endTime << "\n";
    }
}
