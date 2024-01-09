class Solution {
public:
    
    bool canSegment(int currentIndex, string &s, unordered_map<string,int>&dict, vector<int>&memo)
    {
        if(currentIndex == s.size()) return true;
        if(memo[currentIndex] != -1) return (memo[currentIndex] == 1)?true:false;
        
        string temp = "";
        for(int index = currentIndex; index < s.size(); index++)
        {
            temp += string(1,s[index]);
            if(dict[temp])
            {
                if(canSegment(index+1,s,dict,memo))
                    return true;
            }
        }
        memo[currentIndex] = 0;
        return memo[currentIndex];
    }
    
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        vector<int>memo(s.size(),-1);
        unordered_map<string,int>dict;
        for(auto current : wordDict)
            dict[current] = 1;
        
        if(canSegment(0,s,dict,memo))
            return true;
        return false;
    }
};