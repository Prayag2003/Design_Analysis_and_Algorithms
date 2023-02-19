
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
string ans_str;
ll numOfDigitsOfNum1, numOfDigitsOfNum2, temp1, temp2;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
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

Node *getBiggerList(Node *& first, Node *& second)
{
    Node *temp1 = first;
    Node *temp2 = second;

    while (temp1 != NULL)
    {
        if (temp1->data > temp2->data)
        {
            return first;
        }
        else if (temp1->data < temp2->data)
        {
            return second;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return first;
}

Node *subtraction(Node *first, Node *second)
{
    Node head1 = *first;
    Node head2 = *second;
    Node *ansHead = NULL;

    /*  Swaps if second list is greater than first list  */
    if ((numOfDigitsOfNum1 < numOfDigitsOfNum2) || (numOfDigitsOfNum1 == numOfDigitsOfNum2 && second == getBiggerList(first, second)))
    {
        Node *temp = first;
        first = second;
        second = temp;
    }

    int diff = 0;
    bool borrow = false;

    while (first != NULL || second != NULL)
    {
        int val1 = 0, val2 = 0;
        if (first != NULL)
            val1 = first->data;

        if (second != NULL)
            val2 = second->data;

        /* If Borrowing required */
        if (borrow)
        {
            val1 -= 1;
            borrow = false;
        }

        /*  Both of them are not null and second's data is bigger than first's data  */
        if (first != NULL && second != NULL && val1 < val2)
        {
            val1 += 10;
            borrow = true;
        }

        diff = (first != NULL ? val1 : 0) - (second != NULL ? val2 : 0);

        // ans = new Node(diff);
        insertAtBeginning(ansHead, diff);
        ans_str += to_string(diff);

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
    cout << "Enter the Number of Digits for 1st Number :- ";

    cin >> numOfDigitsOfNum1;
    temp1 = numOfDigitsOfNum1;
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
        cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :-\n ";
        goto enterAgain;
    }
    temp1--;

    do
    {
        cin >> curr_dig;
        if (curr_dig >= 0 && curr_dig <= 9)
        {
            insertAtBeginning(first, curr_dig);
            temp1--;
            num1 += to_string(curr_dig);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :- \n";
        }
    } while (temp1);

    cout << "You Entered the Number : " << num1 << "\n";

    /*   Input 2nd Number  */
    cout << "Enter the Number of Digits for 2nd Number :- ";
    ll curr_dig2;

// Entering the first digit and storing it as Head Node
enterAgain2:
    cin >> temp2;
    cin >> curr_dig2;

    if (curr_dig2 >= 0 && curr_dig2 <= 9)
    {
        second = new Node(curr_dig2);
        num2 += to_string(curr_dig2);
    }
    else
    {
        cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :-\n ";
        goto enterAgain2;
    }
    temp2--;

    do
    {
        cin >> curr_dig2;
        if (curr_dig2 >= 0 && curr_dig2 <= 9)
        {
            insertAtBeginning(second, curr_dig2);
            temp2--;
            num2 += to_string(curr_dig2);
        }
        else
        {
            cout << "Enter a Digit Between  [ 0 to 9 ] only.\n Enter again :-\n ";
        }
    } while (temp2);

    cout << "You Entered the Number : " << num2 << "\n";

    Node *ans = subtraction(first, second);
    reverse(ans_str.begin(), ans_str.end());

    // int travel = 0;
    // string final = "";
    // if (ans_str[travel] == '0')
    // {
    //     while (ans_str[travel] == '0')
    //     {
    //         travel++;
    //     }
    // }

    // for (int i = travel; i < ans_str.length(); i++)
    // {
    //     final += ans_str[i];
    // }

    cout << "The Subtraction of " << num1 << " and " << num2 << " gives "  << "\n";
    printList(ans);
}