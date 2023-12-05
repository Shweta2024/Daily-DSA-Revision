class Solution {
public:
    
    void totalMatches(int teams, int &ans)
    {
        if(teams == 1) return ;
        
        //even
        if(teams%2 == 0)
        {
            ans += teams/2;
            totalMatches(teams/2,ans);
        }       
        
        //odd
        else
        {   
            ans += (teams-1)/2;
            totalMatches(((teams-1)/2)+1,ans);
        }
        return ;
    }
    
    
    int numberOfMatches(int n) 
    {
        int ans = 0;
        totalMatches(n,ans);
        return ans;   
    }
};