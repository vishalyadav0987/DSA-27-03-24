#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for with this list value -> " << value << endl;
    }
};

// insert the list at head
void insertAtHead(int d, Node *&head)
{
    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// insertthe list at tail
void insertAtTail(int d, Node *&tail)
{
    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// insert at given position
void insertAtPosition(int d, Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        insertAtHead(d, head);
        return;
    }

    int cnt = 1;
    Node *temp = head;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // insert At last position
    if (temp->next == NULL)
    {
        insertAtTail(d, tail);
        return;
    }

    Node *insertNode = new Node(d);
    insertNode->next = temp->next;
    temp->next->prev = insertNode;
    temp->next = insertNode;
    insertNode->prev = temp;
}

// delte list from list from given position
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head->next=NULL;
        temp->next =NULL;
        delete temp;
    }else{
        // delete from givent position
        Node* curr = head;
        Node* previousNode= NULL;

        int cnt=1;
        while (cnt < position)
        {
            previousNode=curr;
            curr =curr->next;
            cnt++;
        }

      curr->prev =NULL;
      previousNode->next=curr->next;
      curr->next = NULL;
      delete curr;

        
    }
}

// traversal the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    print(head);

    insertAtHead(12, head);
    print(head);

    insertAtHead(80, head);

    insertAtHead(32, head);
    print(head);

    insertAtTail(101, tail);
    print(head);
    insertAtTail(102, tail);
    insertAtTail(100, tail);
    print(head);

    insertAtPosition(1000, head, tail, 1);
    print(head);

    // insertAtPosition(2000, head, tail, 9);
    // print(head);

    insertAtPosition(3000, head, tail, 5);
    print(head);

    return 0;
}