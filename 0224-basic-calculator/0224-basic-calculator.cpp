class Solution {
public:
    
    //checks if currentChar is digit or not
    bool isDigit(char current)
    {
        if('0' <= current && current <= '9')
            return true;
        return false;
    }
    
    int calculate(string s) 
    {
        int ans = 0;
        int sign = 1;
        stack<pair<int,int>>stk;
        
        int index = 0;
        
        for(int index = 0; index < s.size(); index++)
        {
            char currentChar = s[index];
            
            //case 1 : operator
            if(currentChar == '+')
                sign = 1;
            else if(currentChar == '-')
                sign = -1;
            
            //case 2 : digit
            else if(isDigit(currentChar))
            {
                int j = index;
                int currentNumber = 0;
                while(j < s.size() && isDigit(s[j]))
                {
                    currentNumber = (long long)currentNumber*10 + (s[j]-'0');
                    j++;
                }
                //got a number so add it to ans according to its sign
                ans = ans + (sign*currentNumber);
                index = j-1;
            }
            
            //case 3 : open bracket
            else if(currentChar == '(')
            {
                //store the current ans in stack, along with its sign 
                // and set ans to 0 and sign as 1
                stk.push({ans,sign});
                ans = 0;
                sign = 1;                
            }
            
            //case 4 : closing bracket
            else if(currentChar == ')')
            {
                //get the previous answer and add to to current ans according to the sign
                int prevAns = stk.top().first;
                int prevSign = stk.top().second;
                stk.pop();
                
                ans = (prevSign*ans) + prevAns;
            }
            //case 5 : space (simply ignore space)
        }
        return ans;
    }
};