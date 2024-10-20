class Solution
{
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> s;
        for (char ch : expression)
        {
            if (ch == ')')
            {
                vector<char> val;
                while (!s.empty() && s.top() != '(')
                {
                    val.push_back(s.top());
                    s.pop();
                }
                s.pop();
                // when push_back value from till '('
                // the before any operator not ('!','&','|')
                char checkForOperator = s.top();
                if (checkForOperator == '|' || checkForOperator == '&' ||
                    checkForOperator == '!')
                {
                    s.pop();
                }
                char result;
                if (checkForOperator == '!')
                {
                    result = (val.back() == 't') ? 'f' : 't';
                }
                else if (checkForOperator == '&')
                {
                    result = 't';
                    for (char ch : val)
                    {
                        if (ch == 'f')
                        {
                            result = 'f';
                            break;
                        }
                    }
                }
                else if (checkForOperator == '|')
                {
                    result = 'f';
                    for (char ch : val)
                    {
                        if (ch == 't')
                        {
                            result = 't';
                            break;
                        }
                    }
                }
                s.push(result);
            }
            else
            {
                s.push(ch);
            }
        }
        return s.top() == 't';
    }
};