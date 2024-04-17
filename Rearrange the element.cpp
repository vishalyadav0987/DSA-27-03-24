//{ Driver Code Starts
// C++ program to rearrange an array in minimum 
// maximum form 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	int k = 0;
    	int j = n - 1;
    	bool flag = true;
    	vector<long long>temp(n);
    // 	while(i < j){
    // 	   // long long int *maxi = max_element(arr + i,arr + j);
    // 	   // long long int *mini = min_element(arr + i,arr + j);
    // 	   // i++;
    // 	   // j--;
    // 	   // arr[0] = maxi;
    // 	   // arr[1] = mini;
    	   
    // 	}
    for(int i = 0; i<n; i++){
        if(flag){
            temp[i] = arr[j--];
        }
        else{
            temp[i] = arr[k++];
        }
        flag = !flag;
    }
    for(int j = 0; j < n; j++){
        arr[j] = temp[j];
    }
    	 
    }
    
};

//{ Driver Code Starts.

// Driver program to test above function 
int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        
        //calling rearrange() function
        ob.rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
} 

// } Driver Code Ends