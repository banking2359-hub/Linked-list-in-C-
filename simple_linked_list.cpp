#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void add(Node *&head, int data)
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
    head = newNode;
}
int main()
{
    Node *head = nullptr;
    add(head, 1);
    add(head, 2);
    add(head, 3);

    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
}