class Solution {
public:
    
    bool canForm(string currentWord, unordered_map<char,int>memo)
    {
        for(auto currentChar : currentWord)
        {
            if(memo[currentChar] == 0) return false;
            memo[currentChar]--;
        }
        return true;
    }
    
    int countCharacters(vector<string>& words, string chars) 
    {
        int count = 0;
        unordered_map<char,int>memo;
        for(auto current : chars)
            memo[current]++;
        
        for(auto currentWord : words)
        {
            if(canForm(currentWord,memo))
                count += currentWord.size();
        }
        return count;
    }
};