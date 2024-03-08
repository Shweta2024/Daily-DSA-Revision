class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int ans = 0;
        int maxFreq = 0;
        unordered_map<int,int>memo; // element : freq.
        
        for(auto current : nums)
        {
            memo[current]++;
            maxFreq = max(maxFreq,memo[current]);
        }
        
        for(auto current : memo)
        {
            if(current.second == maxFreq)
                ans += current.second;
        }
        
        return ans;
    }
};