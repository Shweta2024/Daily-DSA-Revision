class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) 
    {
        vector<unordered_map<long long,int>>memo(nums.size()); // diff : freq
        int ans = 0;
        
        for(int currentIndex = 1; currentIndex < nums.size(); currentIndex++)
        {
            for(int prev = 0; prev < currentIndex; prev++)
            {
                long long difference = (long long)nums[currentIndex] - (long long)nums[prev];

                ans += memo[prev][difference];
                memo[currentIndex][difference] += memo[prev][difference]+1;

            }
        }
        return ans;
    }
};