class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        for(int index = 0; index < nums.size(); index++)
            nums[index] = nums[index]*nums[index];
        sort(nums.begin(),nums.end());
        return nums;
    }
};