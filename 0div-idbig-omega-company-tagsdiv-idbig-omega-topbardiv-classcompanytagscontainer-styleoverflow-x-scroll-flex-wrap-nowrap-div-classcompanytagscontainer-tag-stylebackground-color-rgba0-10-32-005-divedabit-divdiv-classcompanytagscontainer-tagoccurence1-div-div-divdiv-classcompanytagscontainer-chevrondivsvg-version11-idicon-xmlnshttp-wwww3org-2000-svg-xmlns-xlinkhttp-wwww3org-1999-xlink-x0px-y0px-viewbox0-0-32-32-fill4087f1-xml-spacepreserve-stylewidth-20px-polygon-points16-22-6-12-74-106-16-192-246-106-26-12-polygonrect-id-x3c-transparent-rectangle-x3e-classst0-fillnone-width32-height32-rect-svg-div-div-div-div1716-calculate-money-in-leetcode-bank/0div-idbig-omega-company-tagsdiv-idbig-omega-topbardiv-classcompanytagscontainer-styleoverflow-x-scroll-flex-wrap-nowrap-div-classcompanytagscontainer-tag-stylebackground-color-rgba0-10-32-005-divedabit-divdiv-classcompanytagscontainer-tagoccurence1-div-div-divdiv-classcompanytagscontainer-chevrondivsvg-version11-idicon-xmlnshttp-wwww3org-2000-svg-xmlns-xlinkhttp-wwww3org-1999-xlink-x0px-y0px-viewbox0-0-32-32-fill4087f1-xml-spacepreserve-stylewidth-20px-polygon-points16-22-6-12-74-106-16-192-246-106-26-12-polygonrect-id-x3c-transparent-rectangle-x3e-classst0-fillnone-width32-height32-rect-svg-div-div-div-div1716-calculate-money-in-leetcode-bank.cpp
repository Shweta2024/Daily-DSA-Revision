class Solution {
public:
    
    void bankBalance(int currentIndex, int n, int &sum, vector<int>&amount)
    {
        if(currentIndex > n) return ;
        
        if(currentIndex%7 == 1)  amount[currentIndex%7] += 1;
        
        else    
        {
            if(currentIndex%7 == 0)
                amount[0] = amount[6] + 1;
            else
                amount[currentIndex%7] = amount[(currentIndex%7)-1] + 1;
        }
        sum += amount[currentIndex%7];
        bankBalance(currentIndex+1,n,sum,amount);
    }
    
    int totalMoney(int n) 
    {
        int sum = 0;
        vector<int>amount(n+1,0);
        bankBalance(1,n,sum,amount);
        return sum;
    }
};