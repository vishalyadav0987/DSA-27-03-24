#include <bits/stdc++.h>
using namespace std;
class MyCalendar
{
public:
    MyCalendar()
    {
    }
    std::set<std::pair<int, int>> mySet;

    bool book(int start, int end)
    {

        auto it = mySet.lower_bound({start, end});

        if (it != mySet.end() && it->first < end)
        {
            return false;
        }

        if (it != mySet.begin())
        {
            auto prev = std::prev(it);
            cout << prev->second << " ";
            if (prev->second > start)
            {
                return false;
            }
        }

        mySet.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */