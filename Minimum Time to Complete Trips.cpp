#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long isPossible(vector<int>& time, long long mid) {
        long long sum = 0;
        for (long long i = 0; i < time.size(); i++) {
            sum += mid / time[i];
        }
        return sum;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL*(*min_element(time.begin(),time.end()))*totalTrips;
        
        long long ans = LONG_MAX;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long x = isPossible(time, mid);
            if (x >= totalTrips) {
                ans = min(mid, ans);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};