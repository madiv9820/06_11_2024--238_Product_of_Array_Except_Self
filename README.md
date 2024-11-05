- ## Approach 4:- Space Optimization

    - ### Intuition
        - The goal is to calculate the product of all elements in the array except the current one, without using division. This can be done by creating two passes over the array: one for accumulating the product of all elements to the left of each position and another for the right side. By combining these two products, we get the desired result for each position.

    - ### Approach
        1. **Initialize Result Array**: Start with an array where each element is initialized to hold the product of elements except itself.
        
        2. **Left Pass**:
            - Traverse the array from left to right.
            - For each element at index `i`, store the cumulative product of all elements to its left in the result array.
            - By the end of this pass, each index holds the product of elements to its left.

        3. **Right Pass**:
            - Initialize a variable `right_Side_Prod` to 1, which will store the cumulative product of elements from the right side.
            - Traverse the array from right to left, multiplying each element in the result array with `right_Side_Prod` (the product of all elements to the right).
            - Update `right_Side_Prod` with the current element to include it in future iterations.

        4. **Return the Result Array**: Each position in the array now contains the product of all elements except itself.

    - ### Complexity Analysis
        - **Time Complexity**: __O(n)__
            - The solution involves two passes over the array (one left pass and one right pass), both of which take \(O(n)\) time.

        - **Space Complexity**: __O(1)__ (ignoring output array)
            - We use only constant extra space for `right_Side_Prod` and the result array `product_Except_Self` is used as output, so we do not count it in the auxiliary space complexity.

    - ### Code
        - **Python Solution**

            ```python3 []
            class Solution:
                def productExceptSelf(self, nums: List[int]) -> List[int]:
                    # Get the length of the input list
                    n = len(nums)
                    
                    # Initialize the result list where each element will be the product of all elements except itself
                    # Start by setting the first element to 1, as there are no elements to the left of the first element
                    product_Except_Self = [0] * n
                    product_Except_Self[0] = 1

                    # Pass 1: Calculate left-side products for each element
                    # Each element at index i in product_Except_Self will store the product of all elements to the left of i
                    for index in range(1, n):
                        # Multiply the product up to the previous element by nums[index-1]
                        product_Except_Self[index] = product_Except_Self[index - 1] * nums[index - 1]

                    # Initialize right-side product as 1
                    right_Side_Prod = 1

                    # Pass 2: Multiply each element by the product of all elements to its right
                    for index in range(n - 1, -1, -1):
                        # Multiply the current value in product_Except_Self by the right-side product
                        product_Except_Self[index] *= right_Side_Prod
                        # Update right_Side_Prod to include the current element in nums
                        right_Side_Prod *= nums[index] 
                    
                    # Return the final result list, where each element is the product of all elements except itself
                    return product_Except_Self
            ```
        
        - **C++ Solution**
            
            ```C++ []
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
            ```