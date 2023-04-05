#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string ans_str;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtBeginning(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printList(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

Node *addition(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL, *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0, val2 = 0;
        if (first != NULL)
            val1 = first->data;

        if (second != NULL)
            val2 = second->data;

        ll sum = carry + val1 + val2;
        ll dig = sum % 10;

        insertAtBeginning(ansHead, dig);
        ans_str += to_string(dig);
        carry = sum / 10;

        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }
    return ansHead;
}

int main()
{
    /* creating 2 LinkedLists */
    cout << "Enter the Number of Digits for 1st Number :- ";
    ll numOfDigitsOfNum1;
    cin >> numOfDigitsOfNum1;
    Node *first = NULL, *second = NULL;
    string num1, num2;

/*   Input 1st Number  */
enterAgain:
    ll curr_dig;
    cin >> curr_dig;
    // Entering the first digit and storing it as Head Node
    if (curr_dig >= 0 && curr_dig <= 9)
    {
        first = new Node(curr_dig);
        num1 += to_string(curr_dig);
    }
    else
    {
        cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :- ";
        goto enterAgain;
    }
    numOfDigitsOfNum1--;

    do
    {
        cin >> curr_dig;
        if (curr_dig >= 0 && curr_dig <= 9)
        {
            insertAtBeginning(first, curr_dig);
            numOfDigitsOfNum1--;
            num1 += to_string(curr_dig);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :- ";
        }
    } while (numOfDigitsOfNum1);

    cout << "You Entered the Number : " << num1 << "\n";

    /*   Input 2nd Number  */
    cout << "Enter the Number of Digits for 2nd Number :- ";
    ll numOfDigitsOfNum2, curr_dig2;

// Entering the first digit and storing it as Head Node
enterAgain2:
    cin >> numOfDigitsOfNum2;
    cin >> curr_dig2;

    if (curr_dig2 >= 0 && curr_dig2 <= 9)
    {
        second = new Node(curr_dig2);
        num2 += to_string(curr_dig2);
    }
    else
    {
        cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :- ";
        goto enterAgain2;
    }
    numOfDigitsOfNum2--;

    do
    {
        cin >> curr_dig2;
        if (curr_dig2 >= 0 && curr_dig2 <= 9)
        {
            insertAtBeginning(second, curr_dig2);
            numOfDigitsOfNum2--;
            num2 += to_string(curr_dig2);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :- ";
        }
    } while (numOfDigitsOfNum2);

    cout << "You Entered the Number : " << num2 << "\n";

    Node *ans = addition(first, second);
    reverse(ans_str.begin(), ans_str.end());
    cout << "The Addition of " << num1 << " and "
         << num2 << " is " << ans_str;
}
