class Solution {
public:
    long long largestPerimeter(vector<int>& nums) 
    {
        int n = nums.size();
        long long perimeter = -1;
        vector<long long>prefixSum(n,0);
        
        sort(nums.begin(), nums.end());
        
        for(int index = 1; index < n; index++)
        {
            prefixSum[index] = prefixSum[index-1] + nums[index-1];
            
            if(index >= 2 && prefixSum[index] > nums[index])
            {
                long long currentPerimeter = prefixSum[index] + nums[index];
                perimeter = max(perimeter,currentPerimeter);
        
            }
        }
        return perimeter;
    }
};