class Solution {
public:
    
    void findMaxLen(string &s, int &start, int &maxLen, int i, int j, int &n)
    {
        while(i >= 0 && j < n && s[i] == s[j] )
                {
                    int len = j-i+1;
                    if(len > maxLen)
                    {
                        maxLen = len;
                        start = i;
                    }
                    i--;
                    j++;
                }
        
    }
    
    string longestPalindrome(string s) 
    {
        int start = 0;
        int maxLen = 1;
        int n = s.size();
        
        for(int index = 0; index < n-1; index++)
        {
            //even
            if(s[index] == s[index+1])
            {
                int i = index;
                int j = index+1;
                findMaxLen(s,start,maxLen,i,j,n);
            }
            
            //odd
            if(index != 0 && s[index-1] == s[index+1])
            {
                int i = index-1;
                int j = index+1;
                findMaxLen(s,start,maxLen,i,j,n);
            }
        }
        string ans = s.substr(start,maxLen);
        return ans;
    }
};