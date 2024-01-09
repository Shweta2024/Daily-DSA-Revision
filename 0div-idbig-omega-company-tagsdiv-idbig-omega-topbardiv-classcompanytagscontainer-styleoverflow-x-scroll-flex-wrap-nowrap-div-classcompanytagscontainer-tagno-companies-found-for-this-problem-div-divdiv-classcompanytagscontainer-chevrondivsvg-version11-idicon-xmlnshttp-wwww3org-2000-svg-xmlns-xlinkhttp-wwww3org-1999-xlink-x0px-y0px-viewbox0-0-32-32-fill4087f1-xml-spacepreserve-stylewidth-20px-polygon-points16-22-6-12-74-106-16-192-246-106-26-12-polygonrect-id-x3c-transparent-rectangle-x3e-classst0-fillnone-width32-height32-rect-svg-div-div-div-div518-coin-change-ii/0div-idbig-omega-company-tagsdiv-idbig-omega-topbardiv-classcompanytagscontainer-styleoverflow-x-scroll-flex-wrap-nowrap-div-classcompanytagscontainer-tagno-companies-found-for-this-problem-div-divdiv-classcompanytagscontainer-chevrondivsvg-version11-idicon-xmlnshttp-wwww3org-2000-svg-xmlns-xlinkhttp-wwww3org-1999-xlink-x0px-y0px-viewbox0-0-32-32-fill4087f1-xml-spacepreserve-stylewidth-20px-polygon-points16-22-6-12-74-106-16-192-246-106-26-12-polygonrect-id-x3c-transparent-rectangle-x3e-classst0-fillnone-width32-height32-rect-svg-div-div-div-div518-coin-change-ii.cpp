class Solution {
public:
        int totalWays(int currentIndex, int amount, vector<int>&coins, vector<vector<int>>&memo)
    {
        if(amount == 0) return 1;
        if(currentIndex == coins.size()) return 0;
        if(memo[currentIndex][amount] != -1) return memo[currentIndex][amount];
        
        int take = 0;
        if(coins[currentIndex] <= amount)
            take =totalWays(currentIndex,amount-coins[currentIndex],coins,memo);
        int notTake = totalWays(currentIndex+1,amount,coins,memo);
        
        memo[currentIndex][amount] = (take+notTake);
        return memo[currentIndex][amount];
    }
    int change(int amount, vector<int>& coins) {
                vector<vector<int>>memo(coins.size(),vector<int>(amount+1,-1));
        int ans = totalWays(0,amount,coins,memo);
        return ans;
    }
};