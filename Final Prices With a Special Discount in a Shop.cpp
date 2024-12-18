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
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(-1);
        int n = prices.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
           
            while (!s.empty() && s.top() > prices[i]) {
                s.pop();
            }
            if (s.top() == -1) {
                ans[i] = prices[i];
            } else {
                ans[i] = prices[i] - s.top();
            }
            s.push(prices[i]);
        }
        return ans;
    }
};
int main()
{
   return 0;
}