class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        vector<int>ans(temp.size(),0);
        stack<pair<int,int>>stk;
        for(int index = temp.size()-1; index >= 0; index--)
        {
            int current = temp[index];
            int span = 1;
            while(!stk.empty() && stk.top().first <= current)
            {
                span += stk.top().second;
                stk.pop();
            }
            
            if(!stk.empty())
                ans[index] = span;
            
            stk.push({current,span});    
        }
        return ans;
    }
};