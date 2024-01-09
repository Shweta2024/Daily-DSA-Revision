class Solution {
public:
    
    int maxProfit(int currentIndex, int n, vector<int>&nums, vector<int>&memo)
    {
        if(currentIndex > n) return 0;
        
        if(memo[currentIndex] != -1) return memo[currentIndex];
        
        int take = nums[currentIndex] + maxProfit(currentIndex+2,n,nums,memo);
        int notTake = maxProfit(currentIndex+1,n,nums,memo);
        
        memo[currentIndex] = max(take,notTake);
        return memo[currentIndex];
    }
    
    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        
        int n = nums.size();
        vector<int>memo1(n,-1);
        vector<int>memo2(n,-1);
        int a1 = maxProfit(0,n-2,nums,memo1);
        int a2 = maxProfit(1,n-1,nums,memo2);
        return max(a1,a2);
    }
};