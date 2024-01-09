class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int maxLen = 1;
        int n = nums.size();
        vector<int>dp(nums.size(),1);
        for(int current = 1; current < n; current++)
        {
            for(int prev = 0; prev < current; prev++)
            {
                if(nums[current] > nums[prev])
                {
                    dp[current] = max(dp[current],dp[prev]+1);
                    maxLen = max(maxLen,dp[current]);
                }
            }
        }
        return maxLen;
    }
};