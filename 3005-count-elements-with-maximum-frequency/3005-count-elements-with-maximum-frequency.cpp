class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int ans = 0;
        int maxVal = -1;
        unordered_map<int,int>memo;
        for(auto current : nums)
        {
            memo[current]++;
            maxVal = max(maxVal,memo[current]);
        }
        
        for(auto current : memo)
        {
            if(current.second == maxVal)
                ans += current.second;
        }
        return ans;
    }
};