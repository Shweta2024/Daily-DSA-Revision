class Solution {
public:
    
    int lis(int currentIndex, int prev, vector<int>& nums, vector<vector<int>>&memo)
    {
        if(currentIndex >= nums.size()) return 0;
        
        if(memo[currentIndex][prev+1] != -1) return memo[currentIndex][prev+1];
        
        int take = 0;
        if(prev == -1 || nums[prev] < nums[currentIndex])
             take = 1 + lis(currentIndex+1,currentIndex,nums,memo);
        int notTake = lis(currentIndex+1,prev,nums,memo);
        
        memo[currentIndex][prev+1] = max(take,notTake);
        return memo[currentIndex][prev+1];
    }
    
    int lengthOfLIS(vector<int>& nums) 
    {
        vector<vector<int>>memo(nums.size(),vector<int>(nums.size()+1,-1));
        return lis(0,-1,nums,memo);
    }
};