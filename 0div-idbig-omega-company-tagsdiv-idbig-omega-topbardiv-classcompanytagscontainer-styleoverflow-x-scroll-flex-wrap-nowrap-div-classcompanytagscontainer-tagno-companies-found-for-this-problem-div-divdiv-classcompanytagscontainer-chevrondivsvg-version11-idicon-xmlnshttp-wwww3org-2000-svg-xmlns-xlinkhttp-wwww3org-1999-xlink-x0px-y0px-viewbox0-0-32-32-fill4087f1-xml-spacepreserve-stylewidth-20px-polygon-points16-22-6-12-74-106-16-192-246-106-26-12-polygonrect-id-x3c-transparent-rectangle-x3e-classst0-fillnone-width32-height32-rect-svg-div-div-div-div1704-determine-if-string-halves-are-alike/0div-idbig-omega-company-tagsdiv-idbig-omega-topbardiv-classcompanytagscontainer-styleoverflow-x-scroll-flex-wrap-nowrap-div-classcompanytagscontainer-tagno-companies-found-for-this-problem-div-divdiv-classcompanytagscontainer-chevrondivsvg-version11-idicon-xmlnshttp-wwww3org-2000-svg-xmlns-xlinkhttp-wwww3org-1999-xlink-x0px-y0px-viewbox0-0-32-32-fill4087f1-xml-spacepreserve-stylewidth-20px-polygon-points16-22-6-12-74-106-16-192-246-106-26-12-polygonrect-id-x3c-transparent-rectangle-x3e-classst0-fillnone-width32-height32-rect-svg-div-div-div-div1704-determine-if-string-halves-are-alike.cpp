class Solution {
public:
    
    bool isVowel(char current)
    {
        if(current == 'a' || current == 'e' || current == 'i' || current == 'o' || current == 'u' || 
          current == 'A' || current == 'E' || current == 'I' || current == 'O' || current == 'U'  )
            return true;
        return false;
    }
    
    bool halvesAreAlike(string s) 
    {
        int n = s.size();
        int vowelsLeftHalf = 0;
        int vowelsRightHalf = 0;
        for(int index = 0; index < n/2; index++)
        {
            // for left half
            if(isVowel(s[index]))
                vowelsLeftHalf++;
            
            
            // for right half
            if(isVowel(s[n/2+index]))
                vowelsRightHalf++;
        }
        return vowelsLeftHalf == vowelsRightHalf;
    }
};