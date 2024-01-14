class Solution {
public:
    bool closeStrings(string word1, string word2) 
    {
        // case1: check for different length
        if(word1.size() != word2.size())
            return false;
        
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(int index = 0; index < word1.size(); index++)
        {
            freq1[word1[index]-'a']++;
            freq2[word2[index]-'a']++;
        }
        
        // check for different characters
        for(int current = 0; current < 26; current++)
        {
            if((freq1[current] == 0 && freq2[current] != 0) ||
                (freq1[current] != 0 && freq2[current] == 0))
                return false;
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        for(int current = 0; current < 26; current++)
        {
            if(freq1[current] != freq2[current])
                return false;
        }
        return true;
    }
};