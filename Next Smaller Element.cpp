#include <iso646.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        int currE = arr[i];
        while (s.top() >= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
    }

    return ans;
}

int main()
{
    int arr[5] = {2, 1, 4, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = nextSmallerElement(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;

    // int arr[5] = {2, 1, 4, 5, 3};
    // ans = {1,-1,3,3,-1}
}