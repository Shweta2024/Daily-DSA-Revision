class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) 
    {
        int maxLen = 0;
        int release = 0;
        unordered_map<int,int>memo;
        
        for(int current = 0; current < nums.size(); current++)
        {
            memo[nums[current]]++;
            
            while(release <= current && memo[nums[current]] > k)
            {
                memo[nums[release]]--;
                release++;
            }
            int currentLen = current-release+1;
            maxLen = max(maxLen,currentLen);
        }
        return maxLen;
    }
};