class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        int n = nums.size();
        int totalProduct = 1;
        int zeroCount = 0;
        int zeroIndex = 0;
        vector<int>prefix(n,1);
        vector<int>sufix(n,1);
        vector<int>ans(n,0);
        
        //o(n)
        for(int index = 0; index < n; index++)
        {
            if(nums[index] == 0)
            {
                zeroCount++;
                zeroIndex = index;
                continue;
            }
            totalProduct = (long long)totalProduct * nums[index];
            
            if(index == 0)
                continue;
                
            prefix[index] = (long long)prefix[index-1]*nums[index-1];
            sufix[n-index-1] = (long long)sufix[n-index]*nums[n-index];
        }
        
        if(zeroCount > 1)
            return ans;
        
        if(zeroCount == 1)
        {
            ans[zeroIndex] = totalProduct;
            return ans;
        }
        
        for(int index = 0; index < n; index++)
            ans[index] = prefix[index] * sufix[index];
        return ans;
    }
};