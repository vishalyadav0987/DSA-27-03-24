/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        Node *curr = head;

        while (curr != NULL)
        {
            if (curr->child)
            {
                Node *end = curr->child;
                while (end->next != NULL)
                { // Traverse until end->next is NULL
                    end = end->next;
                }
                end->next = curr->next;
                if (curr->next)
                {
                    curr->next->prev = end; // If there's a next node, set its
                                            // prev to the end of the child list
                }
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            curr = curr->next;
        }
        return head;
    }
};