#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node(int newData): data(newData), next(NULL)
    {}
};

class Solution
{
public:
    Node* insert(Node* head, int newData);
    void display(Node* head);
};

Node* Solution::insert(Node* head, int newData)
{
    Node* newNode = new Node(newData);

    if(head == NULL)
    {
        return newNode;
    }

    Node* tmp = head;
    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = newNode;
    return head;
}

void Solution::display(Node* head)
{
    Node* start = head;

    while(start)
    {
        cout << start->data << ' ';
        start = start->next;
    }
}

int main()
{
    Node* head = NULL;
    Solution myList;
    int T;
    int data;

    cin >> T;

    while(T-- > 0)
    {
        cin >> data;
        head = myList.insert(head, data);
    }
    myList.display(head);
}
