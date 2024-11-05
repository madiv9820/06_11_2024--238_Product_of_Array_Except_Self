#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            // Get the size of the input vector
            int n = nums.size();
            
            // Initialize the result vector with zeros, having the same size as the input vector
            vector<int> product_Except_Self(n, 0);

            // Loop through each index in the input vector
            for(int index = 0; index < n; ++index) {
                // Calculate the product of all elements to the left of the current index
                int left_Side_Prod = 1;
                for(int left_Ptr = 0; left_Ptr < index; ++left_Ptr)
                    left_Side_Prod *= nums[left_Ptr];  // Multiply the left-side elements

                // Calculate the product of all elements to the right of the current index
                int right_Side_Prod = 1;
                for(int right_Ptr = index+1; right_Ptr < n; ++right_Ptr)
                    right_Side_Prod *= nums[right_Ptr];  // Multiply the right-side elements

                // Store the product of left and right products in the result vector
                product_Except_Self[index] = left_Side_Prod * right_Side_Prod;
            }

            // Return the final result vector
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