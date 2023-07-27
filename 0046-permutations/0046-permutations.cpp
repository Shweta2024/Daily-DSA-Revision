class Solution {
public:
    
    void findAllPermutations(int currentIndex, vector<int>&nums, vector<vector<int>>&ans)
    {
        if(currentIndex == nums.size())
        {
            //got a permutation
            ans.push_back(nums);
            return;
        }
        
        for(int index = currentIndex; index < nums.size(); index++)
        {
            swap(nums[currentIndex],nums[index]);
            
            findAllPermutations(currentIndex+1,nums,ans);
            
            swap(nums[currentIndex],nums[index]);
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        
        findAllPermutations(0,nums,ans);
        
        return ans;
    }
};