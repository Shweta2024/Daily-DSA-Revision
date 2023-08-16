class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int release = 0;
        int window = 0;
        vector<int>ans;
        vector<int>memo(n,0);
        priority_queue<pair<int,int>>pq;
        
        for(int acquire = 0; acquire < n; acquire++)
        {
            memo[acquire]++;
            pq.push({nums[acquire],acquire});
            window++;
            
            if(window == k)
            {
                //get the max val & discard element at release pointer
                while(memo[pq.top().second] == 0)
                    pq.pop();
                ans.push_back(pq.top().first);
                memo[release]--;
                release++;
                window--;
            }
        }
        return ans;
    }
};