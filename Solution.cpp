#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            // Step 1: Get the size of the input array
            int n = nums.size();
            
            // Initialize the result array, prefix product array, and suffix product array
            vector<int> product_Except_Self(n, 0); // To store the final result
            vector<int> prefix_Prod(n, 1);          // To store products of elements to the left of each index
            vector<int> suffix_Prod(n, 1);          // To store products of elements to the right of each index

            // Step 2: Fill the prefix_Prod array
            // prefix_Prod[i] will store the product of all elements before index i
            for(int index = 1; index < n; ++index)
                prefix_Prod[index] = prefix_Prod[index-1] * nums[index-1];

            // Step 3: Fill the suffix_Prod array
            // suffix_Prod[i] will store the product of all elements after index i
            for(int index = n-2; index >= 0; --index)
                suffix_Prod[index] = suffix_Prod[index+1] * nums[index+1];

            // Step 4: Set the first element of product_Except_Self to the suffix product at index 0
            // Set the last element of product_Except_Self to the prefix product at index n-1
            product_Except_Self[0] = suffix_Prod[0];
            product_Except_Self[n-1] = prefix_Prod[n-1];

            // Step 5: Calculate the product for the remaining indices
            // Multiply the corresponding prefix and suffix products for each index
            for(int index = 1; index < n-1; ++index)
                product_Except_Self[index] = prefix_Prod[index] * suffix_Prod[index];

            // Step 6: Return the final result array
            return product_Except_Self;
        }
};

int main() {
    vector<int> nums; int input; Solution sol;
    cin >> input;
    
    while(input != -1) {
        nums.emplace_back(input);
        cin >> input;
    }

    vector<int> products = sol.productExceptSelf(nums = nums);
    for(const int& product: products)
        cout << product << " ";

    cout << endl;
}