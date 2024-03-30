//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    /*Function to count even and odd elements in the array
    * arr : Array with its elements
    * sizeof_array : number of array elements
    * countOdd : variable to count number of odd elements
    * countEven : variable to count number of even elements
    */
    vector<int> countOddEven(int arr[], int sizeof_array)
    {
        // your code here
        // vector<int>result;
        int e = 0;
        int o = 0;
        for(int i = 0; i < sizeof_array; i++){
            if(arr[i] % 2 == 0){
                e++;
            }
            else{
                o++;
            }
        }
       
        return {o,e} ;
    }
};

//{ Driver Code Starts.
int main() {
	
	// Testcase input
	int testcase;
	cin >> testcase;
	
	while(testcase--){
	    int sizeof_array;
	    cin >> sizeof_array;
	    
	    int arr[sizeof_array];
	    
	    // Array elements input
	    for(int i = 0; i < sizeof_array; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    // Calling function to count even and odd
	    vector<int> res = ob.countOddEven(arr, sizeof_array);
	    for(auto t:res)
	    {
	        cout<<t<<" ";
	    }
	    cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends