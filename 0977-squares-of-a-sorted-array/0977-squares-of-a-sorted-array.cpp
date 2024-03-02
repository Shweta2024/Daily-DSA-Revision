class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n);
        int start = 0;
        int end = n-1;
        
        for(int index = n-1; index >= 0; index--)
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