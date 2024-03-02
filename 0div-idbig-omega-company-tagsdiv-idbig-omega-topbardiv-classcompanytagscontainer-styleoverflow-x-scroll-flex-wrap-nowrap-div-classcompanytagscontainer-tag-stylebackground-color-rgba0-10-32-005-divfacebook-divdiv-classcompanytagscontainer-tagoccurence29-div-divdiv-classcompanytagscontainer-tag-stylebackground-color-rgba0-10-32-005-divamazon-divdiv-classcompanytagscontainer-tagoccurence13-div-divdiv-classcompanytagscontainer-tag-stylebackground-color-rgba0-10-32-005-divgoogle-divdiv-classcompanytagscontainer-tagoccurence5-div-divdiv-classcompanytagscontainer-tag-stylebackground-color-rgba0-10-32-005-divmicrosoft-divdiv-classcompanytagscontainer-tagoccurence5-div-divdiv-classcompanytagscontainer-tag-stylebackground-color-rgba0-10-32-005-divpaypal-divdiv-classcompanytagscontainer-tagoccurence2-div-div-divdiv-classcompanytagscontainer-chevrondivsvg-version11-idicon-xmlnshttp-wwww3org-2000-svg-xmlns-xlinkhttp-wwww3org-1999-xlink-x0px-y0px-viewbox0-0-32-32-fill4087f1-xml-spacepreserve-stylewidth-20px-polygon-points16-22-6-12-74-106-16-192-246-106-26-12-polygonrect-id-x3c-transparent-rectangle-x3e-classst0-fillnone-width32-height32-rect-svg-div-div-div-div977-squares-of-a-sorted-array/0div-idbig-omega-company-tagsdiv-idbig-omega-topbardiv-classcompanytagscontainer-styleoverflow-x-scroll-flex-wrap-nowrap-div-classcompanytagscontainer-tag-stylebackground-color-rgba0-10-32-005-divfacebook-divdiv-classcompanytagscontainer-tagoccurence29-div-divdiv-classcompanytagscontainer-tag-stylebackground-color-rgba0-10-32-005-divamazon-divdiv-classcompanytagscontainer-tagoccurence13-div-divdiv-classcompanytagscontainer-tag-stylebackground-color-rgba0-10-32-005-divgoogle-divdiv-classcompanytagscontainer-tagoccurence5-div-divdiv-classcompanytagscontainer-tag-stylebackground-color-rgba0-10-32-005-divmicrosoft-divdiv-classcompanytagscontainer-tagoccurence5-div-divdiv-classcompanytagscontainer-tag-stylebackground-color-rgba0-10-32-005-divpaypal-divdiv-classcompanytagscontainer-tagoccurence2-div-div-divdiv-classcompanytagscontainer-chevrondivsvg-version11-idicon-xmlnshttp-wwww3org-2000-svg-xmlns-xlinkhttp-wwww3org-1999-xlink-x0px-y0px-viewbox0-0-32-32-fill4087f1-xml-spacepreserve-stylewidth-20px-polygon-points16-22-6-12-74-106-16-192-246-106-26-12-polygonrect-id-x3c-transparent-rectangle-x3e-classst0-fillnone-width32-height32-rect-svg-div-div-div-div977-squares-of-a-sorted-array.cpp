class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int>ans(nums.size());
        int start = 0;
        int end = nums.size()-1;
        
        for(int index = nums.size()-1; index >= 0; index--)
        {
            if(abs(nums[start]) > abs(nums[end]))
            {
                ans[index] = nums[start]*nums[start];
                start++;
            }
            else
            {
                ans[index] = nums[end]*nums[end];
                end--;
            }
        }
        return ans;
    }
};