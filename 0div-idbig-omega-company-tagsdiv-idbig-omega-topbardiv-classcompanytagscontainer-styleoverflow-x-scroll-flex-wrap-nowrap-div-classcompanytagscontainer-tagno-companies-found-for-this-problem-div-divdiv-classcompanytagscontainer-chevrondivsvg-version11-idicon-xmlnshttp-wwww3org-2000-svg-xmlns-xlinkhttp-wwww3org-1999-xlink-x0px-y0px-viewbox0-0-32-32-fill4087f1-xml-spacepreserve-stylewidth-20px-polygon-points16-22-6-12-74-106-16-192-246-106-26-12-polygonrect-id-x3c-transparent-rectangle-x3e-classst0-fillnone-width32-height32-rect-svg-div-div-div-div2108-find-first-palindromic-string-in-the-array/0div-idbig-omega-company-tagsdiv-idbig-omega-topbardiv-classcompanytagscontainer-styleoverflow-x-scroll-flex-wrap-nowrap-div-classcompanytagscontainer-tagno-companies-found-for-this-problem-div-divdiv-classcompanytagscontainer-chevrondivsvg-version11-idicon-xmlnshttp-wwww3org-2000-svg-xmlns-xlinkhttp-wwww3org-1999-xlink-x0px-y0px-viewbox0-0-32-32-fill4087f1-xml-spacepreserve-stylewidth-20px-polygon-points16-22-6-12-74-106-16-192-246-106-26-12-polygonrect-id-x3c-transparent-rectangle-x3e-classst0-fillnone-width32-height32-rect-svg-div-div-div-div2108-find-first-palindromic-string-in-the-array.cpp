class Solution {
public:
    
    bool isPalindrome(string current)
    {
        int start = 0;
        int end = current.size()-1;
        while(start <= end)
        {
            if(current[start] != current[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    string firstPalindrome(vector<string>& words) 
    {
        for(auto currentWord : words)
        {
            if(isPalindrome(currentWord))
                return currentWord;
        }
        return "";
    }
};