#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // hold the next value adrress

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor for memeory free;
    ~Node()
    {
        int value = this->data;
        // memeory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for this node with data -> " << value << endl;
    }
};

// Insert in to Head
void insertIntoHead(int d, Node *&head)
{
    // create new node
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

// Insert in to tail
void insertIntoTail(int d, Node *&tail)
{
    // create new node
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

// Inset At Position
void insetAtPosition(Node *&head, Node *&tail, int d, int position)
{

    // when if insert in to pos == 1;
    if (position == 1)
    {
        insertIntoHead(d, head);
        return;
    }
    Node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // when inset inaert in to left
    if (temp->next == NULL)
    {
        insertIntoTail(d, tail);
        return;
    }

    Node *insertNode = new Node(d);
    insertNode->next = temp->next;
    temp->next = insertNode;
}

// Deleted node through the postion
void deleteNode(int position, Node *&head)
{
    // delete node from start or first
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        // memeory free
        delete temp;
    }
    else
    {
        // deleteing node from middle and last position
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

// print data the link List
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

    // dynamically created
    Node *node1 = new Node(10);
    /*
    cout << node1->data << endl;
    cout << node1->next << endl; // print address of next value
    */

    Node *head = node1;
    Node *tail = node1; // if i have single node

    // insertIntoHead(15, head);
    // insertIntoHead(20, head);
    // insertIntoHead(12, head);
    // insertIntoHead(11, head);

    insertIntoTail(25, tail);
    insertIntoTail(35, tail);
    insertIntoTail(21, tail);

    print(head);

    // insetAtPosition(head,tail,40,2);
    // insetAtPosition(head,tail,40,1);
    insetAtPosition(head, tail, 40, 5);

    cout << "Head -> " << head->data << endl;
    cout << "Tail -> " << tail->data << endl;

    print(head);


    // deleteNode(1,head);
    // deleteNode(2,head);
    deleteNode(5,head);


    // question tail ko handle karna jab hum last element ko delete karte hai


    print(head);

    return 0;
}