class Solution {
public:

    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        int totalApples = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(), greater<int>());
        
        for(int index = 0; index < capacity.size(); index++)
        {
            totalApples -= capacity[index];
            
            if(totalApples <= 0)
                return index+1;
        }
        return -1;
    }
};