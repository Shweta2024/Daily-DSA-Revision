class Solution {
public:
    
    void findAllCombinations(int open, int close, string currentComb, int n, vector<string>&ans)
    {
        if(open == n && close == n)
        {
            //got a comb.
            ans.push_back(currentComb);
            return ;
        }
        
        //can add opening brackets
        if(open < n)
            findAllCombinations(open+1,close,currentComb+"(",n,ans);
        
        if(close < open && close < n)
            findAllCombinations(open,close+1,currentComb+")",n,ans);
    }
    
    vector<string> generateParenthesis(int n) 
    {
        vector<string>ans;
        
        findAllCombinations(0,0,"",n,ans);
        
        return ans;
    }
};