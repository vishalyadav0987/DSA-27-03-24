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

        // step 2: create a map 
        // mapping original node to clone node
        unordered_map<Node*,Node*>oldToNewNode;

        Node* cloneNode = cloneHead;
        Node* originalNode = head;

        while(originalNode !=NULL){
            oldToNewNode[originalNode] = cloneNode;
            cloneNode=cloneNode->next;
            originalNode=originalNode->next;
        }

        // step 3 : copy the random node original to clone node using map
        cloneNode = cloneHead;
       originalNode = head;
        while(originalNode !=NULL){
            cloneNode->random = oldToNewNode[originalNode->random];
            cloneNode=cloneNode->next;
            originalNode=originalNode->next;
        }

        // step 4: return ans

        return cloneHead;

        
    }
};