class Solution {
public:
    
    bool canPartition(int currentIndex, vector<int>&nums, vector<int>&memo)
    {
        if(currentIndex >= nums.size())
            return true;
        
        if(currentIndex == nums.size()-1) // [1]
            return false;
        
        if(memo[currentIndex] != -1)
            return (memo[currentIndex] == 1) ? true : false;
        
        bool  ans = false;
        
        // explore all the possibilities
        if(nums[currentIndex] == nums[currentIndex+1])
            ans = ans || canPartition(currentIndex+2,nums,memo);
        
        
        if(currentIndex+2 < nums.size())
        {
            if((nums[currentIndex] == nums[currentIndex+1] && nums[currentIndex] == nums[currentIndex+2]) ||
               (nums[currentIndex+1]-nums[currentIndex] == 1 && nums[currentIndex+2]-nums[currentIndex+1] == 1))
                ans = ans || canPartition(currentIndex+3,nums,memo);
        }
        
        memo[currentIndex] = (ans == true)? 1 : 0;
        return (memo[currentIndex] == 1)? true : false;
    }
    
    bool validPartition(vector<int>& nums) 
    {
        vector<int>memo(nums.size(),-1);
        return canPartition(0,nums,memo);
    }
};