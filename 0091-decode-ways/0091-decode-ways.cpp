class Solution {
public:
    
    bool isValid(string current)
    {
        if(current.size() == 1 && "1" <= current && current <= "9")
            return true;
        if(current.size() == 2 && 
           (('1' == current[0] && current[1] <= '9') || ('2' == current[0] && current[1] <= '6')))
            return true;
        return false;
    }
    
    int totalWays(int currentIndex, string s, vector<int>&memo)
    {
        if(currentIndex >= s.size())
            return 1;
        
        if(memo[currentIndex] != -1)
            return memo[currentIndex];
        
        int ans = 0;
        for(int index = currentIndex; index < s.size(); index++)
        {
            string current = s.substr(currentIndex,index-currentIndex+1);
            if(isValid(current))
                ans += totalWays(index+1,s,memo);
        }
        memo[currentIndex] = ans;
        return memo[currentIndex];
    }
    
    int numDecodings(string s) 
    {
        vector<int>memo(s.size(),-1);
        return totalWays(0,s,memo);
    }
};