#include <bits/stdc++.h>
using namespace std;
int numOfDigitsOfNum1, numOfDigitsOfNum2, temp1, temp2;
string ans_str;

int main()
{
    cout << "Enter the Number of Digits for 1st Number :- ";
    cin >> numOfDigitsOfNum1;
    temp1 = numOfDigitsOfNum1;
    list<int> l1, l2;
    string num1, num2;

enterAgain:
    int curr_dig;
    do
    {
        cin >> curr_dig;
        if (curr_dig >= 0 && curr_dig <= 9)
        {
            l1.push_back(curr_dig);
            num1 += to_string(curr_dig);
            --temp1;
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\nEnter again :- \n";
            goto enterAgain;
        }
    } while (temp1);

    cout << "You Entered the Number : " << num1 << "\n";

    /*   Input 2nd Number  */
    cout << "Enter the Number of Digits for 2nd Number :- ";
    cin >> numOfDigitsOfNum2;
    temp2 = numOfDigitsOfNum1;
enterAgain2:
    int curr_dig_2;
    do
    {
        cin >> curr_dig_2;
        if (curr_dig_2 >= 0 && curr_dig_2 <= 9)
        {
            l2.push_back(curr_dig_2);
            num2 += to_string(curr_dig_2);
            --temp2;
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\nEnter again :- \n";
            goto enterAgain2;
        }
    } while (temp2);
    cout << "You Entered the Number : " << num2 << "\n";

    if (numOfDigitsOfNum1 > numOfDigitsOfNum2)
    {
        int diff = numOfDigitsOfNum1 - numOfDigitsOfNum2;
        while (diff != 0)
        {
            l2.push_front(0);
            diff--;
        }
    }
    else if (numOfDigitsOfNum1 < numOfDigitsOfNum2)
    {
        int diff = numOfDigitsOfNum1 - numOfDigitsOfNum2;
        while (diff != 0)
        {
            l1.push_front(0);
        }
        swap(l1, l2);
    }
    else if (numOfDigitsOfNum1 == numOfDigitsOfNum2)
    {
        auto ptr = l2.begin();
        for (auto &i : l1)
        {
            if (i != *ptr)
            {
                if (i < *ptr)
                    swap(l1, l2);
                else if (i > *ptr)
                {
                    break;
                }
                break;
            }
        }
    }
    // L1 always contains the Greater Value and L2 is smaller one
    l1.reverse();
    l2.reverse();

    int sum1, sum2;
    bool borrow = false;
    list t1 = l1;
    list t2 = l2;
    int sub = 0;
    list<int> l3;
    
    for (auto  &i : l1)
    {

    }
}
