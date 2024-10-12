/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* copyRandomList(Node* head) {

        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        // step 1: creating link list using next point of original ll
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }

        // step 2: insert cloneNode between original Node
        // 1->1'->2->2'->3->3'->4->4'->NULL

        Node* cloneNode = cloneHead;
        Node* originalNode = head;

        // to create next pointer to tracker of node
        Node* next1 = NULL;
        Node* next2 = NULL;

        while (originalNode != NULL) {
            next1 = originalNode->next;
            originalNode->next = cloneNode;
            originalNode = next1;

            next2 = cloneNode->next;
            cloneNode->next = originalNode;
            cloneNode = next2;
        }

        // step 3: copy the random node original to copy node
        temp = head;
        while (temp != NULL) {
            if (temp->next != NULL) {
                temp->next->random =
                    temp->random != NULL ? temp->random->next : temp->random;
            }

            temp = temp->next->next;
        }

        // step 4: remove the original node from its in betweens
        // revert the changes
        cloneNode = cloneHead;
        originalNode = head;

        while (originalNode != NULL && cloneNode != NULL) {
            originalNode->next = cloneNode->next;
            originalNode = originalNode->next;

            if (originalNode != NULL) {
                cloneNode->next = originalNode->next;
            }
            cloneNode = cloneNode->next;
        }

        // step 5:return ans;

        return cloneHead;
    }
};