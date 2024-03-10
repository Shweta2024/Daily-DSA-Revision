class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int>ans;
        unordered_map<int,bool>memo; // element : isPresent
        for(auto current : nums1)
            memo[current] = true;
        
        for(auto current : nums2)
        {
            if(memo[current])
            {
                ans.push_back(current);
                memo[current] = false;
            }
        }
        return ans;
    }
};