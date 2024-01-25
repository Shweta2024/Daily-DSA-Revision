class Solution {
public:
    
//     int findLCS(int i, int j, string &s1, string &s2, vector<vector<int>>&memo)
//     {
//         if(i == s1.size() || j == s2.size()) return 0;
        
//         if(memo[i][j] != -1) return memo[i][j];
        
//         //take
//         if(s1[i] == s2[j])
//         {
//             memo[i][j] = 1 + findLCS(i+1,j+1,s1,s2,memo);
//             return memo[i][j];
//         }
        
//         //not take
//         // skip characters of s2
//         // skip characters of s1
//         return memo[i][j] = max(findLCS(i,j+1,s1,s2,memo),findLCS(i+1,j,s1,s2,memo));
//     }
    
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n+1, vector<int>(m+1,0));
        
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = m-1; j >= 0; j--)
            {
                if(text1[i] == text2[j])
                {
                    memo[i][j] = 1 + memo[i+1][j+1];
                }
                else
                {
                    memo[i][j] = max(memo[i+1][j],memo[i][j+1]);
                }
            }
        }
        return memo[0][0];
    }
};