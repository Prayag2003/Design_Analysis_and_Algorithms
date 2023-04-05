#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string ans_str;
ll numOfDigitsOfNum1, numOfDigitsOfNum2, temp1, temp2;

int main()
{
    cout << "Enter the Number of Digits for 1st Number :- ";
    cin >> numOfDigitsOfNum1;
    temp1 = numOfDigitsOfNum1;
    list<int> l1, l2;
    string num1, num2;

enterAgain:
    ll curr_dig;
    cin >> curr_dig;
    do
    {
        temp1--;
        cin >> curr_dig;
        if (curr_dig >= 0 && curr_dig <= 9)
        {
            l1.push_front(curr_dig);
            num1 += to_string(curr_dig);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\nEnter again :- \n";
        }
    } while (temp1);

    cout << "You Entered the Number : " << num1 << "\n";

    /*   Input 2nd Number  */
    cout << "Enter the Number of Digits for 2nd Number :- ";
    ll curr_dig_2;

enterAgain2:
    do
    {
        temp2--;
        cin >> curr_dig_2;
        if (curr_dig_2 >= 0 && curr_dig_2 <= 9)
        {
            l1.push_front(curr_dig_2);
            num1 += to_string(curr_dig_2);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\nEnter again :- \n";
        }
    } while (temp2);

    cout << "You Entered the Number : " << num2 << "\n";

    cout << num1 << num2 << "\
    n";
}