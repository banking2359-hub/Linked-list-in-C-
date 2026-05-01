#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
void display(Node *head)

{
    if (head == nullptr)
    {
        cout << "the node is empty";
        return;
    }
    Node *temp;
    temp = head;

    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
void pushEnd(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp;
    temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void pushFront(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (head == nullptr)
    {
        head = newNode;
        head->next = nullptr;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void pushingToMid(Node *head, int data, int pos)
{
    Node *newNode = new Node;
    newNode->data = data;
    if (head == nullptr)
    {
        head = newNode;
        head->next = nullptr;
        return;
    }
    Node *temp;
    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        if (temp->next != nullptr)
            temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
int main()
{
    Node *head = nullptr;
    pushEnd(head, 1);
    pushEnd(head, 2);
    pushEnd(head, 3);
    pushEnd(head, 4);
    pushEnd(head, 5);
    pushFront(head, 0);
    pushFront(head, -1);
    pushingToMid(head,10,3);
    display(head);
}