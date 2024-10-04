#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
   int data;
   Node *next;

   Node(int d)
   {
      this->data = d;
      this->next = NULL;
   }

   ~Node()
   {
      int value = this->data;
      if (this->next != NULL)
      {
         delete next;
         next = NULL;
      }
      cout << "Dletete the list of with value of -> " << value<<endl;
   }
};
// insert node in circular list
void insertNode(Node *&tail, int element, int d)
{
   // if list is empty
   if (tail == NULL)
   {
      Node *newNode = new Node(d);
      tail = newNode;
      newNode->next = newNode;
   }
   else
   {
      // if elment already present
      Node *curr = tail;
      while (curr->data != element)
      {
         curr = curr->next;
      }

      Node *insertN = new Node(d);
      insertN->next = curr->next;
      curr->next = insertN;
   }
}

// Deleteion in circular Link List;
void deleteNode(Node *&tail, int element)
{
   if (tail == NULL)
   {
      cout << "Your list is empty." << endl;
      return;
   }
   else
   {
      Node *prev = tail;
      Node *curr = prev->next;

      while (curr->data != element)
      {
         prev = curr;
         curr = curr->next;
      }

      prev->next = curr->next;

      // if list have 1 Node
      // If there's only one node in the list
      if (curr == prev)
      {
         tail = NULL;
      }
      // if list 2 or more node;
      // If the node to be deleted is the tail, update the tail pointer
      else if (tail == curr)
      {
         tail = prev;
      }
      curr->next = NULL;
      delete curr;
   }
}

// Traversal circular link list
void print(Node *tail)
{
   if (tail == NULL)
   {
      cout << "Your list is empty." << endl;
      return;
   }

   Node *temp = tail;
   do
   {
      cout << tail->data << " ";
      tail = tail->next;
   } while (tail != temp);

   cout << endl;
}

int main()
{
   Node *tail = NULL;

   insertNode(tail, 5, 3); // tail , firstly dummy element , data
   print(tail);

   insertNode(tail, 3, 6);
   print(tail);

   // insertNode(tail, 6, 9);
   // print(tail);

   // insertNode(tail, 9, 12);
   // print(tail);

   deleteNode(tail, 6);
   print(tail);
}