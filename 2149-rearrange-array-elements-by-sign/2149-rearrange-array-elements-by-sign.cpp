class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums)
    {
        vector<int>ans;
        vector<int>positive;
        vector<int>negative;
        
        for(auto current : nums)
        {
            if(current < 0)
                negative.push_back(current);
            else
                positive.push_back(current);
        }
        for(int index = 0; index < nums.size()/2; index++)
        {
            ans.push_back(positive[index]);
            ans.push_back(negative[index]);
        }
        return ans;
    }
};