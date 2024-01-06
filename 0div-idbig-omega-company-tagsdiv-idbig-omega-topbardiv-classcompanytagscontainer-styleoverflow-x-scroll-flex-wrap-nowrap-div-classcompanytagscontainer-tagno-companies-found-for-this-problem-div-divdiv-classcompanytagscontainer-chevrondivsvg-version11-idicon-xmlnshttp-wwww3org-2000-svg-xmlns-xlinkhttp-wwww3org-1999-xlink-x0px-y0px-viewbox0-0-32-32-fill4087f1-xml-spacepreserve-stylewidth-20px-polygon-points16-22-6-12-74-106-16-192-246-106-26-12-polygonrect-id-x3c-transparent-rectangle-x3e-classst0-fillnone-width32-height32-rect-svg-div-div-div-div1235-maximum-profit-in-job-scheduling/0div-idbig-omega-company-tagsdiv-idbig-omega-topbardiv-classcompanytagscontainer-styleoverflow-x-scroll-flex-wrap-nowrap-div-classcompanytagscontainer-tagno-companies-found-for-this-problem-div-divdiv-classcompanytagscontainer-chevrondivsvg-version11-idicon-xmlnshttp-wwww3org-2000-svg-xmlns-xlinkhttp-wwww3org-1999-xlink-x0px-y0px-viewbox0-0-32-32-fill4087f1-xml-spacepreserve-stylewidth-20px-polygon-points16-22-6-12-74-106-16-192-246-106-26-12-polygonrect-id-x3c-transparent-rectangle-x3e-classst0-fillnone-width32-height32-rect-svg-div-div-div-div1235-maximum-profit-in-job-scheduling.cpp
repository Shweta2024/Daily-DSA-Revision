class Solution {
public:
    
    int maxProfit(int currentIndex, vector<vector<int>>&jobs, vector<int>&start, vector<int>&memo)
    {
        if(currentIndex == jobs.size()) return 0;
        
        if(memo[currentIndex] != -1) return memo[currentIndex];
        
        int nextIndex = lower_bound(start.begin(),start.end(),jobs[currentIndex][1]) - start.begin();
        
        //take
        int take = jobs[currentIndex][2] + maxProfit(nextIndex,jobs,start,memo);
        
        //not take
        int notTake = maxProfit(currentIndex+1,jobs,start,memo);
        
        memo[currentIndex] = max(take,notTake);
        return memo[currentIndex];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
    {
        vector<int>memo(startTime.size(),-1);
        vector<vector<int>>jobs;
        for(int index = 0; index < startTime.size(); index++)
            jobs.push_back({startTime[index],endTime[index],profit[index]});
        
        sort(jobs.begin(),jobs.end());
        sort(startTime.begin(),startTime.end());
        
        return maxProfit(0,jobs,startTime,memo); 
    }
};