class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) 
    {
        long long ans = 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        int release = 0;

        for (int current = 0; current < nums.size(); current++) 
        {
            if (nums[current] == maxVal) 
                k--;
            
            while (!k) 
            {
                if (nums[release] == maxVal) 
                    k++;
                release++;
            }
            ans += release;
        }
        return ans;
    }
};