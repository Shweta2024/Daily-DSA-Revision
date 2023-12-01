class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2)
    {
        string str1 = "";
        string str2 = "";
        
        for(int currentIndex = 0; currentIndex < max(word1.size(),word2.size()); currentIndex++)
        {
            if(currentIndex < word1.size())
                str1 += word1[currentIndex];
            
            if(currentIndex < word2.size())
                str2 += word2[currentIndex];
        }
        return str1 == str2;
    }
};