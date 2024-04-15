//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    void recursive(int i, int j,string &str){
        if(i >= j){
            return;
        }
        swap(str[i],str[j]);
        recursive(i + 1,j - 1,str);
    }
    string reverseWord(string str)
    {
        // Your code goes here
     recursive(0,str.length() - 1,str);
     return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends