class Solution {
public:
    
    int findWays(int currentIndex, int target, vector<int>&coins, vector<vector<int>>&memo)
    {
        //got a valid way
        if(target == 0)
            return 1;
        
        //invalid
        if(currentIndex >= coins.size())
            return 0;
        
        if(memo[currentIndex][target] != -1)
            return memo[currentIndex][target];
        
        //take
        int take = 0;
        if(coins[currentIndex] <= target)
            take += findWays(currentIndex,target-coins[currentIndex],coins,memo);
        
        //not take
        int notTake = 0;
        notTake += findWays(currentIndex+1,target,coins,memo);
        
        memo[currentIndex][target] = take+notTake;
        return memo[currentIndex][target];
    }
    
    int change(int amount, vector<int>& coins) 
    {
        int ans = 0;
        
        vector<vector<int>>memo(coins.size(),vector<int>(amount+1,-1));
        ans = findWays(0,amount,coins,memo);
        
        return ans;
    }
};