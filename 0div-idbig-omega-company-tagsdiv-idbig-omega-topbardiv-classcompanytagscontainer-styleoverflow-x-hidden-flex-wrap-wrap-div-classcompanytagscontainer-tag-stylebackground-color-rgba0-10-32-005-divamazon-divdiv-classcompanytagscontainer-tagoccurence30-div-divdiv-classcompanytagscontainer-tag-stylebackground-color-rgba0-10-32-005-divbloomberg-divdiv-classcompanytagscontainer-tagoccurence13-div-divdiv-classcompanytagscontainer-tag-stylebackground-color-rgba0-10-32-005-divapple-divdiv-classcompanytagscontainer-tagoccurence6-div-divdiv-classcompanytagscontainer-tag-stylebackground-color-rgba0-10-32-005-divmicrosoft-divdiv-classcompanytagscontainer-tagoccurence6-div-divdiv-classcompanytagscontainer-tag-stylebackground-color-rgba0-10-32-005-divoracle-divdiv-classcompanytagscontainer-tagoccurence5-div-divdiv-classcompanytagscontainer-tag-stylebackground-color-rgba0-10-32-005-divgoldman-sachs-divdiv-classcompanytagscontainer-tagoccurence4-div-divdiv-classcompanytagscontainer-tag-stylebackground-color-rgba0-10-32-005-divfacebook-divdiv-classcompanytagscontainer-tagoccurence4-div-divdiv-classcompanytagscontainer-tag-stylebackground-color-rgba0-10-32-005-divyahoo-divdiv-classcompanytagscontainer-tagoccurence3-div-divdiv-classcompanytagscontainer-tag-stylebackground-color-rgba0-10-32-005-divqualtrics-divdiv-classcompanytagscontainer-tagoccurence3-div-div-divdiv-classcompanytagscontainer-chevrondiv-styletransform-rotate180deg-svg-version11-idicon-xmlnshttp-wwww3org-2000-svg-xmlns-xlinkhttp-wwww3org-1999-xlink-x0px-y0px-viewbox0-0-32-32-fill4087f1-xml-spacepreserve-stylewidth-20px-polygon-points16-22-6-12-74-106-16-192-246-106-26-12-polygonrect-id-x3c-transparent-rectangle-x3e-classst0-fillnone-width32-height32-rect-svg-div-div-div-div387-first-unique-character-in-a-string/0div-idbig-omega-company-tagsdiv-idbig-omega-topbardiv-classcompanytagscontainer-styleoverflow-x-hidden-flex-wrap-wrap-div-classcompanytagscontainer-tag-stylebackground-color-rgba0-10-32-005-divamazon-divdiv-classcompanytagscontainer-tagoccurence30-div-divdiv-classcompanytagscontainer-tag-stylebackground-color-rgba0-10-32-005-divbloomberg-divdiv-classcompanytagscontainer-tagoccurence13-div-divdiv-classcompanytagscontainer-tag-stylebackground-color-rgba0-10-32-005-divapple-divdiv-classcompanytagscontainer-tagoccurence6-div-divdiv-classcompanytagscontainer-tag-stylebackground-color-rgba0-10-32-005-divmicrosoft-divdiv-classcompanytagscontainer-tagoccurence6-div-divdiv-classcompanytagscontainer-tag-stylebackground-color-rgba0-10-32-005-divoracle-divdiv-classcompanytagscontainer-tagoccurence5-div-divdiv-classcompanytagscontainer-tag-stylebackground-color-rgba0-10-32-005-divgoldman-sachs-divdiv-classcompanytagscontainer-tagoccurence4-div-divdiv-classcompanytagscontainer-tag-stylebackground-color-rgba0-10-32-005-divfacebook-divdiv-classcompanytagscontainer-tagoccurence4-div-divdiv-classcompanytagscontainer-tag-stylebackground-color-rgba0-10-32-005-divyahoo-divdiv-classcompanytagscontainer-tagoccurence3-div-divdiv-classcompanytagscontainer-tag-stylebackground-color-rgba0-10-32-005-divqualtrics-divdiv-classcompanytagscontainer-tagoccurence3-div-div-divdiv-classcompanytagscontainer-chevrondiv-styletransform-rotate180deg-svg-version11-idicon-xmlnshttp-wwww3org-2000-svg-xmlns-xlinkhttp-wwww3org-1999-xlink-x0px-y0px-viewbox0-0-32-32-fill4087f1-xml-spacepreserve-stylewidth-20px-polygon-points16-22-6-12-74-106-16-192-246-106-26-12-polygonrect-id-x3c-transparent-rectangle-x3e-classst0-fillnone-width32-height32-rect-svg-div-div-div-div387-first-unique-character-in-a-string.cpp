class Solution {
public:
    int firstUniqChar(string s) 
    {
        vector<int>freq(26,0);
        for(auto current : s)
            freq[current-'a']++;
        
        for(int index = 0; index < s.size(); index++)
        {
            if(freq[s[index]-'a'] == 1)
                return index;
        }
        return -1;
    }
};