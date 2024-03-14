class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int,int>freq; // prefixSum : frequency
        
        for(auto current : nums)
        {
            prefixSum += current;
            
            if(prefixSum == goal)
                ans++;
            
            if(freq[prefixSum-goal])
                ans += freq[prefixSum-goal];
            
            freq[prefixSum]++;
        }
        return ans;
    }
};