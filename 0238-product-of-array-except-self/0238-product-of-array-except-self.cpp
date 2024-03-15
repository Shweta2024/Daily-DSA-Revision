class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>ans(n,1);
        
        // store prefix product in ans
        for(int index = 1; index < n; index++)
            ans[index] = ans[index-1] * nums[index-1];
        
        int suffix  = 1;
        for(int index = n-1; index >= 0; index--)
        {
            ans[index] = ans[index] * suffix;
            suffix *= nums[index];
        }
        
        return ans;
    }
};
