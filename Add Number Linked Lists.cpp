#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<deque>
#include<stack>
#include<bitset>
#include<numeric>
#include<sstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<functional>
#include<iomanip>
#include<ctime>

using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head) {

        if(head==NULL || head->next == NULL){
            return head;
        }
        
        Node* curr = head;
        Node* prev = NULL;
        Node* forward = NULL; // taki node kho na jaye
        while(curr!=NULL){
            forward = curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
        }

        return prev;
    }
    Node *addListRec(Node *num1, Node *num2, int &carry) {

    // Base case: If both lists are empty and no carry is left
    if (num1 == nullptr && num2 == nullptr && carry == 0) {
        return nullptr;
    }

    int sum = carry;

    // Add the value from the first list if it exists
    if (num1 != nullptr) {
        sum += num1->data;
        num1 = num1->next;
    }

    // Add the value from the second list if it exists
    if (num2 != nullptr) {
        sum += num2->data;
        num2 = num2->next;
    }

    carry = sum / 10;
    Node *result = new Node(sum % 10);

    // Recursively add remaining digits
    result->next = addListRec(num1, num2, carry);

    return result;
}

// function to trim leading zeros in linked list
Node* trimLeadingZeros(Node* head) {
    while (head != nullptr && head->data == 0) {
        head = head->next;
    }
    return head;
}

// function for adding two linked lists
Node *addTwoLists(Node *num1, Node *num2) {
    num1 = trimLeadingZeros(num1);
    num2 = trimLeadingZeros(num2);

    // Reverse both lists to start addition from 
    // the least significant digit
    num1 = reverse(num1);
    num2 = reverse(num2);

    int carry = 0;
    Node *result = addListRec(num1, num2, carry);

    // If there's any carry left after the addition,
    // create a new node for it
    if (carry != 0) {
        Node *newNode = new Node(carry);
        newNode->next = result;
        result = newNode;
    }

    // Reverse the result list to restore
    // the original order
    return reverse(result);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends