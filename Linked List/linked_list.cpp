#include <iostream>
using namespace std;
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
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtMiddle(Node *&head, Node *&tail, int posi, int d)
{
    // at start
    if (posi == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;
    while (cnt < posi - 1)
    {
        temp = temp->next;
        cnt++;
    }
    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;

    // at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
}
void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void deletion(int posi, Node *&head)
{
    // for first posi
    if (posi == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    else
    {
        Node *curr = head;
        Node *prev = NULL;
        int cnt = 1;
        while (cnt < posi)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        free(curr);
    }
}
int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    // call for head
    // insertAtHead(head, 12);
    // print(head);

    // call for tail
    insertAtTail(tail, 22);
    print(head);
    insertAtTail(tail, 15);
    print(head);
    insertAtTail(tail, 18);
    print(head);

    // call for middle
    insertAtMiddle(head, tail, 4, 14);
    print(head);

    deletion(4, head);
    print(head);
}