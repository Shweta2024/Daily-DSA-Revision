class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) 
    {
        int ans = 0;
        int maxFreq = 0;
        unordered_map<int,int>memo;// element:freq
        for(int index = 0; index < nums.size(); index++)
        {
            memo[nums[index]]++;
            int currentFreq = memo[nums[index]];
            
            if(currentFreq > maxFreq)
            {
                maxFreq = currentFreq;
                ans = maxFreq;
            }
            
            else if(currentFreq == maxFreq)
                ans += currentFreq;
        }
        return ans;
    }
};