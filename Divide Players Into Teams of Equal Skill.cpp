#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int sum = 0;
        for (int i = 0; i < skill.size(); i++)
        {
            sum += skill[i];
        }
        int hmp = skill.size() / 2;
        long long psc = sum % hmp;
        long long ps1 = sum / hmp;
        if (psc != 0)
            return -1;
        sort(skill.begin(), skill.end());
        int i = 0;
        int j = skill.size() - 1;
        long long ans = 0;
        cout << ps1 << endl;
        while (i < j)
        {
            if (skill[i] + skill[j] == ps1)
            {
                long long chem = skill[i] * skill[j];
                ans += chem;
            }
            else if ((skill[i] + skill[j]) > ps1 || (skill[i] + skill[j]) < ps1)
            {
                break;
            }
            i++;
            j--;
        }
        if (i < j)
            return -1;
        return ans == 0 ? -1 : ans;
    }
};