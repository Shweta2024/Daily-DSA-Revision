class Solution {
public:
    
    string reverse(string current)
    {
        int start = 0;
        int end = current.size()-1;
        while(start <= end)
        {
            swap(current[start],current[end]);
            start++;
            end--;
        }
        return current;
    }
    
    string reverseWords(string s)
    {
        int currentIndex = 0;
        int n = s.size()-1;
        string word = "";
        string ans = "";
        
        while(currentIndex <= n)
        {
            if(s[currentIndex] == ' ')
            {
                ans += reverse(word) + " ";
                word = "";
            }
            else
                word += string(1,s[currentIndex]);
            currentIndex++;
        }
        ans += reverse(word);
        return ans;
    }
};