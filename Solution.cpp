#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            // Get the length of the input array
            int n = nums.size();
            
            // Initialize the result array with zeros, same length as input
            vector<int> product_Except_Self(n, 0);
            
            // Variables to count the number of zeros and store the product of all non-zero elements
            int count_Zeros = 0, total_Product = 1;

            // First pass: calculate the product of all non-zero elements and count the zeros
            for (int value : nums) {
                if (value == 0) count_Zeros++; // If the element is zero, increment the zero counter
                else total_Product *= value; // Otherwise, multiply it into total_Product   
            }

            // Second pass: determine the result based on the number of zeros found
            if (count_Zeros == 1) {
                // If there is exactly one zero, only the index with the zero should have a non-zero product
                // This will be the product of all non-zero elements
                for (int index = 0; index < n; ++index)
                    if(nums[index] == 0) product_Except_Self[index] = total_Product;
                    
            } else if (count_Zeros == 0) {
                // If there are no zeros, divide the total_Product by each element in nums
                // This gives the product of all elements except the current one at each index
                for (int index = 0; index < n; ++index)
                    product_Except_Self[index] = total_Product / nums[index];
            }
            // If count_Zeros > 1, `product_Except_Self` remains all zeros as initialized,
            // since any product with multiple zeros results in zero

            // Return the final result array
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