#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int n = nums.size();
            
            // Initialize the result array with the size of `n`, with the first element set to 1
            // Each element in `product_Except_Self` will store the product of all elements except itself
            vector<int> product_Except_Self(n, 1);

            // Step 1: Calculate left-side products for each element
            // Each element at index i in `product_Except_Self` will store the product of all elements to the left of i
            for (int index = 1; index < n; ++index) {
                // Multiply the product up to the previous element by `nums[index - 1]`
                product_Except_Self[index] = product_Except_Self[index - 1] * nums[index - 1];
            }

            // Initialize a variable to keep track of the product of all elements to the right of each index
            int right_Side_Prod = 1;

            // Step 2: Multiply each element by the product of all elements to its right
            for (int index = n - 1; index >= 0; --index) {
                // Multiply the current value in `product_Except_Self` by the right-side product
                product_Except_Self[index] *= right_Side_Prod;
                // Update `right_Side_Prod` to include `nums[index]` for the next iteration
                right_Side_Prod *= nums[index];
            }

            // Return the final result array, where each element is the product of all elements except itself
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