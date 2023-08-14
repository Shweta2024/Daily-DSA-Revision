class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int res = 1;
        int zeroCount = 0;
        int zeroIndex = 0;
        for(int index = 0; index < nums.size(); index++)
        {
            int current = nums[index];
            
            if(zeroCount > 1)
                break;
            
            if(current == 0)
            {
                zeroIndex = index;
                zeroCount++;
            }
            
            if(current == 0 && zeroCount == 1)
                continue;
            
            res *= (long long)current;
        }
        vector<int>ans(nums.size(),0);
        if(zeroCount > 1)
            return ans;
        
        if(zeroCount == 1)
        {
            ans[zeroIndex] = res;
            return ans;
        }
        for(int index = 0; index < nums.size(); index++)
            ans[index] = res/nums[index];
      
        return ans;
    }
};