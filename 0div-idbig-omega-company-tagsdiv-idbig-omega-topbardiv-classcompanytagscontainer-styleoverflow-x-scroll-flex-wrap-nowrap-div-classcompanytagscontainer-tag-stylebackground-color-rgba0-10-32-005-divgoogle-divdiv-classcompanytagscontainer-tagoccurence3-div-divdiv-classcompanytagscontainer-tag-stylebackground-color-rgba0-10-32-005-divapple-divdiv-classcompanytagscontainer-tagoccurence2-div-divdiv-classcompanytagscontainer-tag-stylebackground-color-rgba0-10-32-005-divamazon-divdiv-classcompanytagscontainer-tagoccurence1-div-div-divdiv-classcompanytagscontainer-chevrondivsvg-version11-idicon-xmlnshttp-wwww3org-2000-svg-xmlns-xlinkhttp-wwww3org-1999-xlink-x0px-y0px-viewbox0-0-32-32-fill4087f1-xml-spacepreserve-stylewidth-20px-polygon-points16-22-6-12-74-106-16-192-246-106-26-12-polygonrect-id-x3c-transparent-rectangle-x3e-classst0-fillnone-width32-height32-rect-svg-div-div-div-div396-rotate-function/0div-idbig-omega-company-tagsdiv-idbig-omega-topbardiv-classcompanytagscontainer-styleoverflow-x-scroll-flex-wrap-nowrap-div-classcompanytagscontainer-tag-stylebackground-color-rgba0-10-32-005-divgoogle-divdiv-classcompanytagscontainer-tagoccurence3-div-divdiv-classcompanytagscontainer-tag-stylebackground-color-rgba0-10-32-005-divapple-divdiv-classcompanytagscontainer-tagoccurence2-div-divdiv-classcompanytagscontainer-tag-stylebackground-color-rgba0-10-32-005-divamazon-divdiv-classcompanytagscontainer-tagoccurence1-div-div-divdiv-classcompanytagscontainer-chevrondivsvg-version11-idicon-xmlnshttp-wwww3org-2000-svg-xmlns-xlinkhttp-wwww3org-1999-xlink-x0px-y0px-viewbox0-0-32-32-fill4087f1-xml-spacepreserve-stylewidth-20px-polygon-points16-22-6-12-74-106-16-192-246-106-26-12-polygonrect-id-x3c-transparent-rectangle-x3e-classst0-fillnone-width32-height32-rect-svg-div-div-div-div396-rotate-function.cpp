class Solution {
public:
    int maxRotateFunction(vector<int>& nums) 
    {
        int prev = 0;
        int n = nums.size();
        for(int index = 0; index < n; index++)
            prev += (index*nums[index]);
        
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        int ans = prev;
        int current = 0;
        for(int index = 1; index < n; index++)
        {
            current = prev + sum - n*(nums[n-index]);
            ans = max(ans,current);
            
            prev = current;
        }
        return ans;
    }
};