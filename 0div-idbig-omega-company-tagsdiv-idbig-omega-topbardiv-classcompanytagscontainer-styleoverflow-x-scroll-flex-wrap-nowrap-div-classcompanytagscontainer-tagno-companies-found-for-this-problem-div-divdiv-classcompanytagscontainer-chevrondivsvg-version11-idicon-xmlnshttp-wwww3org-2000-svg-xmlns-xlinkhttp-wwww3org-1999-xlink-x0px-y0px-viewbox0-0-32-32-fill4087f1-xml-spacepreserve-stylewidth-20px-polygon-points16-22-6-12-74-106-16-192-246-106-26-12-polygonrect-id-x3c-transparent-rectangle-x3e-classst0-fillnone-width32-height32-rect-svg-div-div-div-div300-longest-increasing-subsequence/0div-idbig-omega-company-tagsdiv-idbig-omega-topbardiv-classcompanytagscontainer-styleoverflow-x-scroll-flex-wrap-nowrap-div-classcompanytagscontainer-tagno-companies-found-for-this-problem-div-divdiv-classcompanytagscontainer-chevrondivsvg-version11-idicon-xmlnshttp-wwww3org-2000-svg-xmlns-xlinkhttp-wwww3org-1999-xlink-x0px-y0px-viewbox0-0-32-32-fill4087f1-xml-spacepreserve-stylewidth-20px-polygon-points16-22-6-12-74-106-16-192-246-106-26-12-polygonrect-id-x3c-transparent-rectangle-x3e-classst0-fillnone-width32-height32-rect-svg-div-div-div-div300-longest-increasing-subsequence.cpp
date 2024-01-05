class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int maxLen = 1;
        vector<int>dp(nums.size(),1);
        
        for(int currentIndex = 1; currentIndex < nums.size(); currentIndex++)
        {
            for(int prevIndex = 0; prevIndex < currentIndex; prevIndex++)
            {
                if(nums[prevIndex] < nums[currentIndex])
                {
                    dp[currentIndex] = max(dp[prevIndex]+1,dp[currentIndex]);
                    maxLen = max(maxLen,dp[currentIndex]);
                }
            }
        }
        return maxLen;
    }
};