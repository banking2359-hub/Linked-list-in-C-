#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

void add(Node *&head, int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFront(Node *&head)
{
    if (head == nullptr)
    {
        cout << "Empty List!" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}
void deleteEnd(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty node";
        return;
    }
    Node *temp = head;

    if (temp->next == nullptr)
    {
        deleteFront(temp);
        return;
    }

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    delete temp;
}

void deleteMiddle(Node *head, int pos)
{
    if (head == nullptr)
    {
        cout << "Empty node";
        return;
    }
    Node *temp = head;

    if (temp->next == nullptr)
    {
        deleteFront(head);
        return;
    }
    for (int i = 1; i < pos; i++)
    {
        if (temp->next == nullptr)
            break;
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next->prev;
    delete temp;
}
int main()
{
    Node *head = nullptr;
    add(head, 1);
    add(head, 2);
    add(head, 3);

    cout << "List contents: ";

    deleteMiddle(head, 2);
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}