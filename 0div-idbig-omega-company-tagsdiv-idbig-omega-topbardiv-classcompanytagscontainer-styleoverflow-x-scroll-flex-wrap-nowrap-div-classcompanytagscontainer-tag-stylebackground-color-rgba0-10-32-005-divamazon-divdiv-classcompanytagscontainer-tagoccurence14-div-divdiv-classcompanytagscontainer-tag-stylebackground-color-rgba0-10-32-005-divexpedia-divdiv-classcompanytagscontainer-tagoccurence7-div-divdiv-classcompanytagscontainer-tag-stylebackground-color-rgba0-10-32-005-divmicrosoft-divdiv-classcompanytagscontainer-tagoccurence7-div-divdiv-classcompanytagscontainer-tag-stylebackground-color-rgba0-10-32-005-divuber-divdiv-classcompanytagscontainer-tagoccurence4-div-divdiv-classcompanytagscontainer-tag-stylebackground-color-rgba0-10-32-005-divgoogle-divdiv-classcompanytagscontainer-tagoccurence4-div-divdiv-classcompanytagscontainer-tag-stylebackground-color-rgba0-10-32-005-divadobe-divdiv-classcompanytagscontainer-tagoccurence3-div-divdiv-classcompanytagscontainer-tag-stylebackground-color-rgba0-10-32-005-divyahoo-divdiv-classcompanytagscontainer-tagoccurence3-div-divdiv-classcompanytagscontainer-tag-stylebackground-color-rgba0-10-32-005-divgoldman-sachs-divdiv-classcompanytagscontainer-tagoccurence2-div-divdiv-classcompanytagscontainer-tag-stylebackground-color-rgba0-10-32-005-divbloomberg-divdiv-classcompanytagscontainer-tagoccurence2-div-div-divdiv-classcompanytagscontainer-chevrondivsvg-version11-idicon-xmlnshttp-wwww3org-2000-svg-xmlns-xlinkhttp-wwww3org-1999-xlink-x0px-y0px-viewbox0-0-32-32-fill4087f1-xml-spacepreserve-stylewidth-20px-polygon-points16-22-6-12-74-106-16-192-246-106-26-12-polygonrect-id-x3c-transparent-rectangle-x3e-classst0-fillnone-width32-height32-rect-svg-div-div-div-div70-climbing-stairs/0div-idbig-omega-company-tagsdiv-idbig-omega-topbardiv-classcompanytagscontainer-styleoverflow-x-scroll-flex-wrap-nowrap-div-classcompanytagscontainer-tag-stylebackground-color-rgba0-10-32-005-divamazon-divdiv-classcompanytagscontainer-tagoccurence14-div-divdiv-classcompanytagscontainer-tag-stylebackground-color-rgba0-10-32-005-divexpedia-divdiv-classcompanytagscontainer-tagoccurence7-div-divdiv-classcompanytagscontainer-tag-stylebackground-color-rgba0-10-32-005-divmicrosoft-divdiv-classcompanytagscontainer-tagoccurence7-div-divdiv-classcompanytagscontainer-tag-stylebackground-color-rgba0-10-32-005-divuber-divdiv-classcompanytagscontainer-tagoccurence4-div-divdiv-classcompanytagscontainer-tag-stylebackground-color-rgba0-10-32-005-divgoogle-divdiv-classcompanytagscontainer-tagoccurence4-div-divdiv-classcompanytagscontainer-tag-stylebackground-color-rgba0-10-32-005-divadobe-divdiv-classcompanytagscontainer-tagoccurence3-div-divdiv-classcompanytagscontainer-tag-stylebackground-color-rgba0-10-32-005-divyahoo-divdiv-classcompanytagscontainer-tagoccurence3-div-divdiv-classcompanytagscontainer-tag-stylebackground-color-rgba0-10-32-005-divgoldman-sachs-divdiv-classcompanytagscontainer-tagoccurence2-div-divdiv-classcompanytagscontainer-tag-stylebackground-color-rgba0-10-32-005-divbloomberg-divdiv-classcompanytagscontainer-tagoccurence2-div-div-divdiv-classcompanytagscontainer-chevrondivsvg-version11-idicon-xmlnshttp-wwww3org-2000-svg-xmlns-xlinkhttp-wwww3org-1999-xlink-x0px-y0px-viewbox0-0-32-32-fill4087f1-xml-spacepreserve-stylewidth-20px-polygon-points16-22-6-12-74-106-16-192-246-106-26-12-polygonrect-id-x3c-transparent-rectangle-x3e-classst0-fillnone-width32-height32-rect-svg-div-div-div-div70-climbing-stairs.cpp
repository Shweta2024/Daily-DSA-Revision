class Solution {
public:
    
    int totalWays(int currentIndex, int n, vector<int>&memo)
    {
        if(currentIndex == n) return 1;
        
        if(currentIndex > n) return 0;
        
        if(memo[currentIndex] != -1) return memo[currentIndex];
        
        int one = totalWays(currentIndex+1,n,memo);
        int two = totalWays(currentIndex+2,n,memo);
        
        memo[currentIndex] = one+two;
        return memo[currentIndex];
    }
    
    int climbStairs(int n) 
    {
        vector<int>memo(n+1,-1);
        return totalWays(0,n,memo);
    }
};