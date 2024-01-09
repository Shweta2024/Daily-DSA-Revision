class Solution {
public:
    int maxProduct(vector<int>& nums)
    {
        int product = 1;
        int maxProduct = INT_MIN;
        for(int index = 0; index < nums.size(); index++)
        {
            product *= nums[index];
            maxProduct = max(maxProduct,product);
            if(product == 0)
                product = 1;
        }
        product = 1;
        for(int index = nums.size()-1; index >= 0; index--)
        {
            product *= nums[index];
            maxProduct = max(maxProduct,product);
            if(product == 0)
                product = 1;
        }
        return maxProduct;
    }
};