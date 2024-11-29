#include <iostream>
using namespace std;
#include <string>
#include <cctype>
using namespace std;

class Solution
{
public:
    bool isAlphanumeric(char s)
    {
        return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z') || (s >= '0' && s <= '9');
    }

    string reverse(const string &s)
    {
        string reversed = s;
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            swap(reversed[i], reversed[j]);
            i++;
            j--;
        }
        return reversed;
    }

    string toLowercase(const string &s)
    {
        string lowercase = s;
        for (char &c : lowercase)
        {
            c = tolower(c);
        }
        return lowercase;
    }

    bool isPalindrome(const string &s)
    {
        string filtered;
        for (char c : s)
        {
            if (isAlphanumeric(c))
            {
                filtered += c;
            }
        }

        string lowercaseFiltered = toLowercase(filtered);
        string reversedLowercaseFiltered = toLowercase(reverse(lowercaseFiltered));

        return lowercaseFiltered == reversedLowercaseFiltered;
    }
};
