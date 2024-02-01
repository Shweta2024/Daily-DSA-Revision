class Solution {
public:
    
/*
 [1,3,3,2,7,3], k = 3
1   2   3   3   3   7




*/
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int index =0;
        while(index < nums.size()-2)
        {
            if(nums[index+1] - nums[index] <= k 
              && nums[index+2] - nums[index] <= k
              && nums[index+2] - nums[index+1] <= k)
            {            
                vector<int>temp(3,0);
                temp[0] = nums[index];
                temp[1] = nums[index+1];
                temp[2] = nums[index+2];
                ans.push_back(temp);
                index += 3;
                continue;
            }
            else
                return {};
            index++;
        }
        return ans;
    }
};