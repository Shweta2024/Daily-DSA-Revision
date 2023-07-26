class Solution {
public:
    
    void findAllCombinations(int currentIndex, string currentComb, string digits, vector<string>&ans,
                            unordered_map<char,string>&memo)
    {
        // got a comb.
        if(currentIndex == digits.size())
        {
            if(currentComb.size() != 0) // to handle this case : [] size -> 0 , currentCob -> ""
                ans.push_back(currentComb);
            return ;
        }
        
        //iterate over the letter set of current digit
        for(auto letter : memo[digits[currentIndex]])
        {
            string currentLetter = string(1,letter);
            //take the current letter in the combination 
            //and move to another digit and similarly iterate over its letter set 
            //to take its letter in the combination
            findAllCombinations(currentIndex+1,currentComb+currentLetter,digits,ans,memo);
            
            //don't need to undo -> it will happen on its own, cuzz we are using string without ref.
        }
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string>memo = {
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"},
        };
        
        vector<string>ans;
        
        findAllCombinations(0,"",digits,ans,memo);
        
        return ans;
    }
};