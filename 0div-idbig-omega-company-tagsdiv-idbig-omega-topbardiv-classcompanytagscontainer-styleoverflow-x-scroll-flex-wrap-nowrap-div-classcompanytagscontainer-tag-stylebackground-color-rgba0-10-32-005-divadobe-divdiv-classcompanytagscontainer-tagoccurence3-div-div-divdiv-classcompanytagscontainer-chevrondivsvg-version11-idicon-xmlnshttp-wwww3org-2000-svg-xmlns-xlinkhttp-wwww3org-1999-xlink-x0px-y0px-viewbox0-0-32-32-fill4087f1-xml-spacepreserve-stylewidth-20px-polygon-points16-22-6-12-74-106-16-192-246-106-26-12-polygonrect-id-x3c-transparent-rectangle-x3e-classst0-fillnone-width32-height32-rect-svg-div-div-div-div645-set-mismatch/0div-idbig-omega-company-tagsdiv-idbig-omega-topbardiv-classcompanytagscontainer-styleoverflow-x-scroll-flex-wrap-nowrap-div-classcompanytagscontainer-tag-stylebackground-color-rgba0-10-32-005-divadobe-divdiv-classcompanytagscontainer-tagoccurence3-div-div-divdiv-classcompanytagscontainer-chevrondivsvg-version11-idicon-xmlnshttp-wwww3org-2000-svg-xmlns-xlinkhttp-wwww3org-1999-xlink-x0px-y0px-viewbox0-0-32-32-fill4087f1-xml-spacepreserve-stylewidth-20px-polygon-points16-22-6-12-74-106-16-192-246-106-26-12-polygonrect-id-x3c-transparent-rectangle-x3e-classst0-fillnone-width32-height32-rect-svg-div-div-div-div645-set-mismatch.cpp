class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
        int duplicate = -1;
        int missing = -1;
        vector<int>freq(nums.size()+1,0);
        
        for(int index = 0; index < nums.size(); index++)
            freq[nums[index]]++;
        
        for(int index = 1; index <= nums.size(); index++)
        {
            if(freq[index] == 0)
                missing = index;
            
            else if(freq[index] == 2)
                duplicate = index;
        }
        return {duplicate,missing};
    }
};