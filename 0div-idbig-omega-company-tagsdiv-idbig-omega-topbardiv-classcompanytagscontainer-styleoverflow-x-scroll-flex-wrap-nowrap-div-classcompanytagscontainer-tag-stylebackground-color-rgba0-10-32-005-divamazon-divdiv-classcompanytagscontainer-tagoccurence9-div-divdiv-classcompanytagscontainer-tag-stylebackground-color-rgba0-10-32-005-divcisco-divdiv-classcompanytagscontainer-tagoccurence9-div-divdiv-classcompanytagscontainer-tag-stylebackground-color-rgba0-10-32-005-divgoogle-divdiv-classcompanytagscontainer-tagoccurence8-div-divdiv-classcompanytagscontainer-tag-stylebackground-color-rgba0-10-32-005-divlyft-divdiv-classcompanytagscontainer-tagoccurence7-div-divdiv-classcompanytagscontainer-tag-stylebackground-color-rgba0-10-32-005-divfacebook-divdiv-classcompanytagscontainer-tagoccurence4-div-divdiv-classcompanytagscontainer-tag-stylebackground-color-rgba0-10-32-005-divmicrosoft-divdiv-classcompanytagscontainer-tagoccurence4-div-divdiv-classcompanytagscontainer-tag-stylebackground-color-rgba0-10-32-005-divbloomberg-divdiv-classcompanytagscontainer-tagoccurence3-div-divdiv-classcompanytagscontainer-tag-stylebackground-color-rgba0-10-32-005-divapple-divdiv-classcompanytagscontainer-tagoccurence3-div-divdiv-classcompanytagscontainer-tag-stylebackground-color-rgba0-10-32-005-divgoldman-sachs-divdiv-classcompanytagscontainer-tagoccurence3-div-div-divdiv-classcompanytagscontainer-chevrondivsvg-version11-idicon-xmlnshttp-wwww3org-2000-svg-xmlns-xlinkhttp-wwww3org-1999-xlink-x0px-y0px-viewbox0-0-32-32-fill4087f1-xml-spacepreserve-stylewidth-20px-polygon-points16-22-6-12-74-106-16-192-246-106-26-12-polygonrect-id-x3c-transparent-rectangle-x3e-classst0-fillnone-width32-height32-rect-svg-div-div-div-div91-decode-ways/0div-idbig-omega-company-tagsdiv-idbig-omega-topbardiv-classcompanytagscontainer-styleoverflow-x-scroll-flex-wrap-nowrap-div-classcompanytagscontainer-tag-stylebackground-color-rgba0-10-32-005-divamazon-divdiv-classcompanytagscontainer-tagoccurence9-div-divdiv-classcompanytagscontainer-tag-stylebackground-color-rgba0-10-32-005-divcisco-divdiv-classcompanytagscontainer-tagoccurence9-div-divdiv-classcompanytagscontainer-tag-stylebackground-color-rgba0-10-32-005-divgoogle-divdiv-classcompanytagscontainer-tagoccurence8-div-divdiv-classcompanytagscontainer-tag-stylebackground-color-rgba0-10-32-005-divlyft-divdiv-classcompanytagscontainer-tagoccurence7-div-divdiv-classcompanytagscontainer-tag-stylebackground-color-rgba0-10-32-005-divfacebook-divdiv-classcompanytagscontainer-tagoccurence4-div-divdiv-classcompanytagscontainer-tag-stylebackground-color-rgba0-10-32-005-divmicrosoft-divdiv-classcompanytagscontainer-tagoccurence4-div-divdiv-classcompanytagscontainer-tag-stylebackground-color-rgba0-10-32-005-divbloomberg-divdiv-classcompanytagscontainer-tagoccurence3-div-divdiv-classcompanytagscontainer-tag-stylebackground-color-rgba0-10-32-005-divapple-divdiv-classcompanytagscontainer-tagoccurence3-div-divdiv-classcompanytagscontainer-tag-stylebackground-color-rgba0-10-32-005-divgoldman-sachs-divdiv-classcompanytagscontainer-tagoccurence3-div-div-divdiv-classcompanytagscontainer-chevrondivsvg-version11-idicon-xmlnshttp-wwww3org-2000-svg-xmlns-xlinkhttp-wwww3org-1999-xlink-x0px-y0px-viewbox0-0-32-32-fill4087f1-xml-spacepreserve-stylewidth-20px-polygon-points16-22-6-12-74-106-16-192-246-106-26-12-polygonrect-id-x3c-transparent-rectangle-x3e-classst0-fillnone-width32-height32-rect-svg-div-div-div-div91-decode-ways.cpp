class Solution {
public:
    
    bool isValid(string &s)
    {
        if(s.size() > 2)
            return false;
        
        if(s.size() == 1 && '1' <= s[0] && s[0] <= '9')
            return true;
        
        if(s.size() == 2 && (
            (s[0] == '2' && '0' <= s[1] && s[1] <= '6') ||
            (s[0] == '1' && '0' <= s[1] && s[1] <= '9')
        ) )
           return true;
          
         return false;
    }
    
    int totalWays(int currentIndex, string s, vector<int>&memo)
    {
        if(currentIndex == s.size())
            return 1;
        
        if(memo[currentIndex] != -1) return memo[currentIndex];
        
        int ans = 0;
        for(int index = currentIndex; index < s.size(); index++)
        {
            string str = s.substr(currentIndex,index-currentIndex+1);
            if(isValid(str))
            {
                ans += totalWays(index+1,s,memo);
            }
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