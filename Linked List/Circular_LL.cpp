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
void insertnode(Node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        Node *newnode = new Node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        Node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next;
        }
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(Node *tail)
{
    Node *temp = tail;
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    do
    {
        cout << tail->data << " -> ";
        tail = tail->next;
    } while (tail != temp);
    cout << endl;
}
bool iscircularll(Node *head)
{

    Node *temp = head->next;
    if (head == NULL)
        return true;

    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }
    if (temp == head)
        return true;

    return false;
}
// void deletion(Node *&tail, int value)
// {
//     // empty list
//     if (tail == NULL)
//     {
//         cout << "List is empty" << endl;
//         return;
//     }
//     else
//     {
//         Node *prev = tail;
//         Node *curr = prev->next;

//         while (curr->data != value)
//         {
//             prev = curr;
//             curr = curr->next;
//         }
//         prev->next = curr->next;

//         // 1 node
//         if (curr = prev)
//         {
//             tail = NULL;
//         }
//         // >= 2 node
//         else if (tail == curr)
//         {
//             tail = prev;
//         }

//         curr->next = NULL;
//         free(curr);
//     }
// }

void deleteNode(Node *&tail, int value)
{

    // empty list
    if (tail == NULL)
    {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else
    {
        // non-empty

        // assuming that "value" is present in the Linked List
        Node *prev = tail;
        Node *curr = prev->next;

        while (curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 Node Linked List
        if (curr == prev)
        {
            tail = NULL;
        }

        //>=2 Node linked list
        else if (tail == curr)
        {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node *tail = NULL;
    insertnode(tail, 1, 3);
    print(tail);
    insertnode(tail, 3, 5);
    print(tail);
    insertnode(tail, 5, 4);
    print(tail);
    insertnode(tail, 4, 6);
    print(tail);
    insertnode(tail, 5, 1);
    print(tail);
    insertnode(tail, 6, 9);
    print(tail);
    insertnode(tail, 3, 2);
    print(tail);
    // deletion(tail, 5);
    // print(tail);
    deleteNode(tail, 5);
    print(tail);
}

// floyd's cycle detection algo (interview based)