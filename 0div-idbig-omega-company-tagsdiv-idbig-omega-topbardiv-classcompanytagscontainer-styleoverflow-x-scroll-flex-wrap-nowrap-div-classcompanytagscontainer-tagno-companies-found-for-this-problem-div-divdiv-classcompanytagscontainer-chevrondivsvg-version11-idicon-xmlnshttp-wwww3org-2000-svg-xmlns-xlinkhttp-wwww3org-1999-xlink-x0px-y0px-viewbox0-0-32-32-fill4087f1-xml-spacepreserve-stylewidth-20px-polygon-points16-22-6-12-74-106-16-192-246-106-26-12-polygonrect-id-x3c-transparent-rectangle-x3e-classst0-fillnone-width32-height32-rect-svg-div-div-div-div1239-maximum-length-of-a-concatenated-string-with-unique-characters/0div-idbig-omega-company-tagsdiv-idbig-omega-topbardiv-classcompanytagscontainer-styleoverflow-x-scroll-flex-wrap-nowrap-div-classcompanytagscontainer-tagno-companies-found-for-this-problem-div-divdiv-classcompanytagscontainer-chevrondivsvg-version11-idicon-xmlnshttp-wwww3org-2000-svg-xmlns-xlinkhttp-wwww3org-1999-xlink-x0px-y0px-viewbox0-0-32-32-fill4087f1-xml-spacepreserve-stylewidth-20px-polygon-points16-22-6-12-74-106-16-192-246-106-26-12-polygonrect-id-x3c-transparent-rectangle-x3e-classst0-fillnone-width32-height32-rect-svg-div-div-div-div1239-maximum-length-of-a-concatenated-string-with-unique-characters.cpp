class Solution {
public:
    
    bool isValid(string &currentString, unordered_map<char,int>&memo)
    {
        unordered_map<char,int>temp;
        for(auto currentChar : currentString)
        {
            temp[currentChar]++;
            if(memo[currentChar] == 1 || temp[currentChar] > 1)
                return false;
        }
        // cout<<"string: "<<currentString<<endl;
        // for(auto c : temp)
        //     cout<<c.first<<" : "<<c.second<<endl;
        // cout<<"*****";
        return true;
    }
    
    void findMaxLen(int currentIndex, string &current, int &ans, unordered_map<char,int>&memo, vector<string>&arr)
    {
        int len = current.size();
        ans = max(ans,len);
        
        if(currentIndex >= arr.size())
            return;
        
        
        for(int index = currentIndex; index < arr.size(); index++)
        {
            // cout<<currentIndex<<endl;
            string currentString = arr[index];
            if(isValid(currentString,memo))
            {
                // cout<<currentString<<endl;
                int i = 0;
                while(i < currentString.size())
                {
                    current.push_back(currentString[i]);
                    memo[currentString[i]]++;
                    i++;
                }
                cout<<current<<endl;
                findMaxLen(index+1,current,ans,memo,arr);
                
                i = currentString.size();
                while(i--)
                {
                    current.pop_back();
                    memo[currentString[i]]--;
                }
            }
        }
        return;
    }
    
    int maxLength(vector<string>& arr) 
    {
        int ans = 0;
        string current = "";
        unordered_map<char,int>memo;
        
        findMaxLen(0,current,ans,memo,arr);
        
        return ans;
    }
};