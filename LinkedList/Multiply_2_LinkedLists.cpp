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

Node *multiplication(Node *&first, Node *&second)
{
    Node *ansHead = NULL;

    Node *temp1 = first;
    Node *temp2 = second;

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

enterAgain:
    ll curr_dig;
    cin >> curr_dig;

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

    cout << "Enter the Number of Digits for 2nd Number :- ";
    ll numOfDigitsOfNum2, curr_dig2;

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

    Node *ans = multiplication(first, second);
    reverse(ans_str.begin(), ans_str.end());
    cout << "The Addition of " << num1 << " and "
         << "num2 is " << num2 << " is " << ans_str;
}
