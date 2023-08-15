class Solution {
public:
    int longestValidParentheses(string s) 
    {
        int maxLen = 0;
        stack<int>stk;
        stk.push(-1);
        
        for(int index = 0; index < s.size(); index++)
        {
            if(s[index] == '(')
                stk.push(index);
            else
            {
                stk.pop();
                
                if(stk.empty())
                    stk.push(index);
                else
                    maxLen = max(maxLen,index-stk.top());
            }
        }
        return maxLen;
    }
};