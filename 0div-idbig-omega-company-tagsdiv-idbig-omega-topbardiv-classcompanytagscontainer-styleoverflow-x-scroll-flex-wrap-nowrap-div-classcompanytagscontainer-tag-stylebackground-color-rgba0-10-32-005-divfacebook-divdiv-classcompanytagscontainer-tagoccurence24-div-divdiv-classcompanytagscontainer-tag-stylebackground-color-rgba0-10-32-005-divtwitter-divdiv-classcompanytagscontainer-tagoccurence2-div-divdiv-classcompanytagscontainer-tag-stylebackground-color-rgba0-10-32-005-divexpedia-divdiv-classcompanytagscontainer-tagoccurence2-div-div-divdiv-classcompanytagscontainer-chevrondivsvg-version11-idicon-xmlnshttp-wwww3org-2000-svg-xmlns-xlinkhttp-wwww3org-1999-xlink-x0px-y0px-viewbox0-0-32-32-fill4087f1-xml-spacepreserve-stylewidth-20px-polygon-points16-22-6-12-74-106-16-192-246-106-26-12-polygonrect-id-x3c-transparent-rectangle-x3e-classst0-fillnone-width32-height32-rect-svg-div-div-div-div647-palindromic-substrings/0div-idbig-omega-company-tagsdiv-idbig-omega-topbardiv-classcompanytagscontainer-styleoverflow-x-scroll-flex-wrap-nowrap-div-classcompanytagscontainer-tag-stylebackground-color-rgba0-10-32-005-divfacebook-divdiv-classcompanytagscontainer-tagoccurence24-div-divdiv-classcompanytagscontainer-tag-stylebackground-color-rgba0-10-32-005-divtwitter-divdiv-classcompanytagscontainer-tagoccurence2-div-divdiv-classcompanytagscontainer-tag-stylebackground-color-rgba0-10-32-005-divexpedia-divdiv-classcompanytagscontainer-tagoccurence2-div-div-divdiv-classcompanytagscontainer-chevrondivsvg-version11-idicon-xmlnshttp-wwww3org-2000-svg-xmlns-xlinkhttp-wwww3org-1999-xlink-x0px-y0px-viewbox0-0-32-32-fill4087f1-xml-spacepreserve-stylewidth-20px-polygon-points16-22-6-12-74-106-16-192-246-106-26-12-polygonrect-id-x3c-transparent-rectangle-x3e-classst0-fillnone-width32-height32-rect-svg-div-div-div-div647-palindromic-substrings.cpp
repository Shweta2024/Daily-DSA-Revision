class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        int n = s.size();
        
        for(int index = 0; index < n; index++)
        {
            ans++;
            
            //even
            if(index != n-1 && s[index] == s[index+1])
            {
                int i = index;
                int j = index+1;
                while(i >= 0 && j < n && s[i] == s[j] )
                {
                    ans++;
                    i--;
                    j++;
                }
            }
            
            //odd
            if(index != 0 && s[index-1] == s[index+1])
            {
                int i = index-1;
                int j = index+1;
                while(i >= 0 && j < n && s[i] == s[j] )
                {
                    ans++;
                    i--;
                    j++;
                }
            }
        }
        return ans;
    }
};