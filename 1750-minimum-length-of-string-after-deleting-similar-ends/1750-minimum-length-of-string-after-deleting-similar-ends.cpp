class Solution {
public:
    int minimumLength(string s)
    {
        int start = 0;
        int end = s.size()-1;
        
        while(start < end && s[start] == s[end])
        {
            char currentChar = s[start];
            
            while(start <= end && s[start] == currentChar)
                start++;
            while(end > start && s[end] == currentChar)
                end--;
        }
        return end-start+1;
    }
};