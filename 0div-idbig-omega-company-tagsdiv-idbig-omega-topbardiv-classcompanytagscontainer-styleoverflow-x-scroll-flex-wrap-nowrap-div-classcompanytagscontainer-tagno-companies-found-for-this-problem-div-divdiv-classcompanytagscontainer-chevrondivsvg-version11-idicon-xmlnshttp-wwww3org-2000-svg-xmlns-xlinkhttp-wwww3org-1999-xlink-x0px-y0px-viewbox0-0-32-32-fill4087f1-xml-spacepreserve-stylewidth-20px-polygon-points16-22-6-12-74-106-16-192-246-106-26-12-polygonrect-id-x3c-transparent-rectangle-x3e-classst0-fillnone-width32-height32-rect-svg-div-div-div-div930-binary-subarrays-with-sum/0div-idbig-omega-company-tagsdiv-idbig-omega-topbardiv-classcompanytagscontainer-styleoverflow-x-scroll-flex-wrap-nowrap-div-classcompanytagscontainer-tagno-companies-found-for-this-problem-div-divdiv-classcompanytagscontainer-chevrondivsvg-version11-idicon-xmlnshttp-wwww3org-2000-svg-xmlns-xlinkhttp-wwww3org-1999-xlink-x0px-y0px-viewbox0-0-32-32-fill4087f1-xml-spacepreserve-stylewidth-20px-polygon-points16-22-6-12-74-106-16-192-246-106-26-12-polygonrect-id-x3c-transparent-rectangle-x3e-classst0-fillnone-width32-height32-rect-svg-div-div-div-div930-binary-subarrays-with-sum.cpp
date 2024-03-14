class Solution {
public:
    
    // total number of subarrays with a sum of k
    int totalSubarraysAtmostK(vector<int>&nums, int k)
    {
        int ans = 0;
        int sum = 0;
        int release = 0;
        
        for(int current = 0; current < nums.size(); current++)
        {
            sum += nums[current];
            
            // invalid window
            while(release <= current && sum > k)
            {
                sum -= nums[release];
                release++;
            }
            
            ans += (current-release+1); 
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return totalSubarraysAtmostK(nums,goal) - totalSubarraysAtmostK(nums,goal-1);
    }
};