//{ Driver Code Starts

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends

class Solution{
public:
    long long evenFibSum(int N){
        // code here
        long long a = 1;
        long long b = 1;
        long long temp = 0;
        long long sum = 0;
        while(b <= N){
            if(b % 2 == 0){
             sum = (sum + b);
            }
            temp = a;
            a = b;
            b = (temp + b);
        }
        return sum;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenFibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends