class Solution
{
public:
    int maximumSwap(int num)
    {
        string num1 = to_string(num);
        string num2 = to_string(num);
        sort(num1.begin(), num1.end(), [](int a, int b)
             { return a > b; });
        int k = 0;
        for (int i = 0; i < num1.length(); i++)
        {
            if (num1[i] != num2[i])
            {
                k = i;
                break;
            }
        }

        // int value nums[i]  jis value ko swap kar na hai
        // i index uska hai jis swap karna hai num2 me
        int numIdx = -1;
        for (int j = 0; j < num2.length(); j++)
        {
            if (num2[j] == num1[k])
            {
                numIdx = j;
            }
        }

        swap(num2[k], num2[numIdx]);
        cout << num2 << " " << numIdx << k;
        int ans = stoi(num2);
        return ans;
    }
};