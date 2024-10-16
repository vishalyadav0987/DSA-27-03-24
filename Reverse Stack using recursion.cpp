//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void addElementAtBottom(stack<int> &s,int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        
        int num=s.top();
        s.pop();
        
        // recursive call
        addElementAtBottom(s,x);
        
        // wapas add kar do element jo nikale the
        s.push(num);
    }
    void solve(stack<int> &s){
        if(s.empty()){
            return;
        }
        
        int num=s.top();
        s.pop();
        
        // recursive call
        solve(s);
        
        // after empty top element top bottom
        addElementAtBottom(s,num);
    }
    
    void Reverse(stack<int> &St){
        solve(St);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends