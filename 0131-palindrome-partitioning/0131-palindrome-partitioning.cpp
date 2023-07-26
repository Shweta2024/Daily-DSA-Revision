class Solution {
public:
    
    bool isPalindrome(int start, int end, string current)
    {
        while(start <= end)
        {
            if(current[start] != current[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void findAllPalindromes(int currentIndex, vector<string>&currentAns, string s, 
                            vector<vector<string>>&ans)
    {
        if(currentIndex >= s.size())
        {
            ans.push_back(currentAns);
            return ;
        }
        
        for(int index = currentIndex; index < s.size(); index++)
        {
            if(isPalindrome(currentIndex,index,s))
            {
                currentAns.push_back(s.substr(currentIndex,index-currentIndex+1));
                findAllPalindromes(index+1,currentAns,s,ans);
                
                //undo
                currentAns.pop_back();
            }
        }
        return;
    }
    
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>ans;
        vector<string>currentAns;
        
        findAllPalindromes(0,currentAns,s,ans);
        
        return ans;
    }
};