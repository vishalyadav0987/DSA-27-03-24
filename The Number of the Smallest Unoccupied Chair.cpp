class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int len = times.size();
        vector<int> chairs(len, -2);  

       
        vector<pair<int, pair<int, int>>> events;

        
        for (int i = 0; i < len; ++i) {
            events.push_back({times[i][0], {i, 1}}); 
            events.push_back({times[i][1], {i, 0}}); 
        }

        
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first) return a.second.second < b.second.second;
            return a.first < b.first;
        });

       
        vector<int> chairStatus(len, -2); 

        for (const auto& event : events) {
            int time = event.first;
            int friendIndex = event.second.first;
            int eventType = event.second.second;

            if (eventType == 1) { 
               
                for (int j = 0; j < len; j++) {
                    if (chairStatus[j] == -2) { 
                        chairStatus[j] = friendIndex; 
                   
                        if (friendIndex == targetFriend) {
                            return j;
                        }
                        break; 
                    }
                }
            } else { 
               
                for (int j = 0; j < len; j++) {
                    if (chairStatus[j] == friendIndex) {
                        chairStatus[j] = -2; 
                        break; 
                    }
                }
            }
        }

        return -1; 
    }
};

