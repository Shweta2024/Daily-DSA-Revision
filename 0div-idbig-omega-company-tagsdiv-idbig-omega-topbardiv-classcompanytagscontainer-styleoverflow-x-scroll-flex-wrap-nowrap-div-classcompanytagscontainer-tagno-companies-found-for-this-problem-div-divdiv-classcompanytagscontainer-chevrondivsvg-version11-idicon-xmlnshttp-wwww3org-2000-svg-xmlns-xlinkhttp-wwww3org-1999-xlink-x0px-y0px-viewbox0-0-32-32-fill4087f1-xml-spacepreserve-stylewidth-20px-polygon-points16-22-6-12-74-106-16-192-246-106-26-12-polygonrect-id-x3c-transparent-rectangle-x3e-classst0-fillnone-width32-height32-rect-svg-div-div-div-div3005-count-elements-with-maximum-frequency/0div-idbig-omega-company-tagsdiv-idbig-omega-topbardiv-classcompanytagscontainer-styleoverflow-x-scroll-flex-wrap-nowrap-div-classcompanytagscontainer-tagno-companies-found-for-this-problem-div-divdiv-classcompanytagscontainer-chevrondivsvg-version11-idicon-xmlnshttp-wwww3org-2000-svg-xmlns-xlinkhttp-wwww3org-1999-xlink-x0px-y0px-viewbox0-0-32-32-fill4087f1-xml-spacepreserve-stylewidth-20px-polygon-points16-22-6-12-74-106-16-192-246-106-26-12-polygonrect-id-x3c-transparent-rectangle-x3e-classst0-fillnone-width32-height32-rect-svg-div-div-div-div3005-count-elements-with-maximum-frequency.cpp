class Solution {
public:
    int maxFrequencyElements(vector<int>& nums)
    {
        int ans = 0;
        int maxFrequency = 0;
        unordered_map<int,int>memo;
        
        for(int index = 0; index < nums.size(); index++)
        {
            memo[nums[index]]++;
            int currentFrequency = memo[nums[index]];
            
            // if currentFrequency is greater than maxFrequency then update maxFrequency and ans
            if(currentFrequency > maxFrequency)
            {
                maxFrequency = currentFrequency;
                ans = currentFrequency;
            }
            
            // otherwise, if currentFrequency is equal to maxFrequency, then simply add it to ans
            else if( currentFrequency == maxFrequency)
                ans += currentFrequency;
        }
        return ans;
    }
};