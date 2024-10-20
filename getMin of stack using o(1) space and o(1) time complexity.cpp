class MinStack
{
    long long mini;     // Use long long here
    stack<long long> s; // Use long long here for all calculations

public:
    MinStack() {}

    void push(int val)
    {
        // checking s is empty if push val and set to the empty
        if (s.empty())
        {
            s.push(val);
            mini = val; // Initialize mini with the value
        }
        else
        {
            long long curr = val; // Use long long for the current value
            if (curr < mini)
            {
                // push the encoded value
                long long valX = 2 * curr - mini; // Avoid overflow by using long long
                s.push(valX);
                // update mini
                mini = val;
            }
            else
            {
                // if curr is greater than or equal to mini, simply push it
                s.push(curr);
            }
        }
    }

    void pop()
    {
        // checking for empty condition
        if (s.empty())
        {
            cout << "Stack underflow";
            return;
        }

        long long curr = s.top();
        s.pop();
        if (curr > mini)
        {
            // Do nothing, just pop the element
        }
        else
        {
            // Update mini to its previous state
            long long prevMin = mini;
            int ValX = 2 * mini - curr; // Restore the previous mini value
            mini = ValX;
        }
    }

    int top()
    {
        if (s.empty())
        {
            return -1;
        }
        long long curr = s.top();
        if (curr < mini)
        {
            // curr is encoded, so return mini
            return mini;
        }
        else
        {
            return curr;
        }
    }

    int getMin()
    {
        if (s.empty())
        {
            return -1;
        }
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
