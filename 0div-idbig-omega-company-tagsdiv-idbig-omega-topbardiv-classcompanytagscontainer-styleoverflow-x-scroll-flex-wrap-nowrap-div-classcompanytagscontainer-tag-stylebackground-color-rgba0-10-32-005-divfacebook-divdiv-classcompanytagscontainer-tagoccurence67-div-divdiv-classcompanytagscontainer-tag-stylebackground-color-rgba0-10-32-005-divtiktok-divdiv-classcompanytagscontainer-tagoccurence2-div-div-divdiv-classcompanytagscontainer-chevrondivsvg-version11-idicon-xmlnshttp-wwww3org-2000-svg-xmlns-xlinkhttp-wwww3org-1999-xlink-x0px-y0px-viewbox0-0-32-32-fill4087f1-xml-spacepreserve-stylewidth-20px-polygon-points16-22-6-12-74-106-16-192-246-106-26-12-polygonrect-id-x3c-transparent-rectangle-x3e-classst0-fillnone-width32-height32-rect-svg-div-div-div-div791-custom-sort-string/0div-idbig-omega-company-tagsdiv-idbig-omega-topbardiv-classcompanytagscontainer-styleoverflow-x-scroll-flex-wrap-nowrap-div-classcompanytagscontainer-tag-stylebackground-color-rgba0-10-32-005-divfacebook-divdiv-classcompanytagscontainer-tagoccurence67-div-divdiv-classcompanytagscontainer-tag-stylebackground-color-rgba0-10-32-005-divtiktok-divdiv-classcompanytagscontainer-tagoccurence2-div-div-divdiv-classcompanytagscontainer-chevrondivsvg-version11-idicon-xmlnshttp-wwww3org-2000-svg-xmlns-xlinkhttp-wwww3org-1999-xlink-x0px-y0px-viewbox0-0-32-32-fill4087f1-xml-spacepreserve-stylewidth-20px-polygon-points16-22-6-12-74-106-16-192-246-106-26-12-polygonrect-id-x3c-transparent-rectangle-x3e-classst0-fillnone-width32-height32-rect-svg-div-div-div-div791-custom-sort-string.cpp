class Solution {
public:
    string customSortString(string order, string s)
    {
        unordered_map<char,int>memo;// element : freq
        string ans = "";
        
        for(auto current : s)
            memo[current]++;
        
        for(auto current : order)
        {
            int freq = memo[current];
            while(freq > 0 && freq--)
                ans += current;
            memo[current] = 0;
        }
        
        for(auto current : memo)
        {
            int freq = current.second;
            while(freq > 0 && freq--)
                ans += current.first;
        }
        return ans;
    }
};