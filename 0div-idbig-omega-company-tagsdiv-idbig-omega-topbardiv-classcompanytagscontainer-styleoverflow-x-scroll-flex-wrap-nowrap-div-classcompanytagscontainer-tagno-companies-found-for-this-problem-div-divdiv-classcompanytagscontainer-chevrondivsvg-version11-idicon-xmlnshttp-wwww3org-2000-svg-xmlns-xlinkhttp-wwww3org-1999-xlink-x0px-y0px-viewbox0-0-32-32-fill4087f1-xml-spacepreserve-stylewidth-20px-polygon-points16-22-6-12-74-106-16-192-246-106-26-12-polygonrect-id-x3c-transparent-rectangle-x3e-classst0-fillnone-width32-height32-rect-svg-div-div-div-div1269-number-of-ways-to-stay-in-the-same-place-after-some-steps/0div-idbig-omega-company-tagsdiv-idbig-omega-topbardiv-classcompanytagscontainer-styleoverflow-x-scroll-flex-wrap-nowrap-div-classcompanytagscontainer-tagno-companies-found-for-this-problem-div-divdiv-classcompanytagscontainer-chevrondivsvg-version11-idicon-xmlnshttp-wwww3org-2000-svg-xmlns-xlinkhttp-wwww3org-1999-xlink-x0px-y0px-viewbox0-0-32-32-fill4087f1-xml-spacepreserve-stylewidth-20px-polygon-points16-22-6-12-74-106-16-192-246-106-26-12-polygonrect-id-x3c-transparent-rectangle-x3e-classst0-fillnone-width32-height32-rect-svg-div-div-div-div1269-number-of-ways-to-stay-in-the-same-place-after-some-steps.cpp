class Solution {
public:
    
    int mod = 1e9+7;
    int totalWays(int currentIndex, int n, int steps, vector<vector<int>>& memo)
    {
        // valid
        if(steps == 0 && currentIndex == 0)
            return 1;
        
        // invalid
        if(steps == 0 || currentIndex < 0 || currentIndex == n || currentIndex > 250)
            return 0;
        
        if(memo[currentIndex][steps] != -1)
            return memo[currentIndex][steps];
        
        // possibilities
        int left = totalWays(currentIndex-1,n,steps-1,memo)%mod;
        int right = totalWays(currentIndex+1,n,steps-1,memo)%mod;
        int stay = totalWays(currentIndex,n,steps-1,memo)%mod;
        
        memo[currentIndex][steps] = ((left+right)%mod + stay)%mod;
        return memo[currentIndex][steps];
    }
    
    int numWays(int steps, int arrLen) 
    {
        vector<vector<int>>memo(251, vector<int>(steps+1,-1));
        return totalWays(0,arrLen,steps,memo);
    }
};