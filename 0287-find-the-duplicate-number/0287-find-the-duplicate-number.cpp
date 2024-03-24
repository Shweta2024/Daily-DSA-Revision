class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        if(nums.size() == 1) return -1;
        
        int slow = nums[0];
        int fast = nums[nums[0]];
        
        // cycle exists or not: duplicate exists or not
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        
        // starting point of the cycle => duplicate number
        fast = 0;
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
};