//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    // Function to delete middle element of a stack.
    void solve(stack<int>& s, int sizeOfStack,int cnt){
        if(cnt==sizeOfStack/2){
            s.pop();
            return;
        }
        
        int num=s.top();
        s.pop();
        
        // recursive call
        solve(s,sizeOfStack,cnt+1);
        
        // or wapas aate wakt stack me wahi element dal denge jo nikale the
        s.push(num);
    }
    void deleteMid(stack<int>& s, int sizeOfStack) {
        // code here..
        int cnt = 0;
        solve(s,sizeOfStack,cnt);
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends