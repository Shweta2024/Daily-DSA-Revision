class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int,int>memo;
        for(auto current : nums1)
            memo[current] = 1;
        
        for(auto current : nums2)
        {
            if(memo[current])
                return current;
        }
        return -1;
    }
};