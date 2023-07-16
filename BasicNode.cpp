#include <iostream>
#include "Node.cpp"

using namespace std;

Node<int> *takeInput()
{
    int data;
    cin >> data;
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while (data != -1)
    {
        Node<int> *newNode = new Node<int>(data);
        if (head == NULL and tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->link = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}
int PrintLastElement(Node<int> *head)
{
    while (head != NULL)
    {
        head = head->link;
    }
    return head->data;
}

int main()
{
    Node<int> *head = takeInput();
    cout << PrintLastElement(head) << endl;
    return 0;
}