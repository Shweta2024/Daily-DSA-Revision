class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        unordered_map<int,int>memo; // elements : freq.
        int ans = 0;
        
        for(auto current : nums)
            memo[current]++;
        
        for(auto current : memo)
        {
            int freq = current.second;
            
            if(freq == 1)
                return -1;
            
            ans += ceil((double)freq/3);
        }
        return ans;
    }
    
};