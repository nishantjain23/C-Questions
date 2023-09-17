#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    cout << " NULL";
    while (temp != NULL)
    {
        cout << " <- " << temp->data << " ->";
        temp = temp->next;
    }
    cout << " NULL " << endl;
}
int getlength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
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

    // at end
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *nodetoinsert = new Node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    temp->next = nodetoinsert;
    nodetoinsert->prev = temp;
}
void deletion(int posi, Node *&head)
{
    // for first posi
    if (posi == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next->prev = NULL;
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
        // curr -> next -> prev = curr -> prev; ??
        curr->prev = NULL;
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

    insertAtHead(head, 12);
    print(head);
    insertAtHead(head, 15);
    print(head);
    insertAtHead(head, 2);
    print(head);

    insertAtTail(tail, 9);
    print(head);

    insertAtMiddle(head, tail, 3, 20);
    print(head);
    insertAtMiddle(head, tail, 1, 25);
    print(head);
    insertAtMiddle(head, tail, 8, 28);
    print(head);

    deletion(1, head);
    print(head);
    deletion(3, head);
    print(head);
    deletion(6, head);
    print(head);
}