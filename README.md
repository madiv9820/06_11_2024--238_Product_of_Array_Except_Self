- ## Approach 1:- Using Nested Loops (Brute Force) 

    - ### Intuition:
        - The goal of this problem is to return an array where each element at index `i` is the product of all elements in the input array `nums` except `nums[i]`. The challenge is to solve it **without using division** and **optimally** in terms of time complexity.

    - ### Approach:
        We will solve this problem using the concept of **prefix** and **suffix** products.

        1. **Prefix Product**: This is the product of all elements before a given index `i`. For example, for index `i`, we need the product of all elements in `nums` from index `0` to `i-1`.

        2. **Suffix Product**: This is the product of all elements after a given index `i`. For index `i`, we need the product of all elements in `nums` from index `i+1` to the end.

        3. **Combination of Prefix and Suffix**: For each index `i`, we can compute the product of all elements except `nums[i]` by multiplying the prefix product (all elements before `i`) and the suffix product (all elements after `i`).

    - ### Steps:
        1. **Initialize** a result array `product_Except_Self` of the same length as `nums`.
        2. **First pass**: Calculate the prefix products and store them in `product_Except_Self`. For each index `i`, `product_Except_Self[i]` will store the product of all elements before `i`.
        3. **Second pass**: Calculate the suffix products while iterating backward and multiply it with the existing values in `product_Except_Self`. This gives the final product of all elements except the one at that index.

    - ### Example Walkthrough:
        Consider the array `nums = [1, 2, 3, 4]`:

        1. **First pass (prefix product)**:
            - We initialize `product_Except_Self` as `[1, 1, 1, 1]`.
            - At index `0`, `product_Except_Self[0] = 1` (no elements to the left of index `0`).
            - At index `1`, `product_Except_Self[1] = product_Except_Self[0] * nums[0] = 1 * 1 = 1`.
            - At index `2`, `product_Except_Self[2] = product_Except_Self[1] * nums[1] = 1 * 2 = 2`.
            - At index `3`, `product_Except_Self[3] = product_Except_Self[2] * nums[2] = 2 * 3 = 6`.
        
            After the first pass, `product_Except_Self = [1, 1, 2, 6]`.

        2. **Second pass (suffix product)**:
            - Start from the last element and multiply the suffix products:
            - Initialize `suffix = 1` (this is the product after the last index).
            - At index `3`, `product_Except_Self[3] *= suffix = 6 * 1 = 6`, then update `suffix = suffix * nums[3] = 1 * 4 = 4`.
            - At index `2`, `product_Except_Self[2] *= suffix = 2 * 4 = 8`, then update `suffix = suffix * nums[2] = 4 * 3 = 12`.
            - At index `1`, `product_Except_Self[1] *= suffix = 1 * 12 = 12`, then update `suffix = suffix * nums[1] = 12 * 2 = 24`.
            - At index `0`, `product_Except_Self[0] *= suffix = 1 * 24 = 24`, then update `suffix = suffix * nums[0] = 24 * 1 = 24`.

            After the second pass, the final result is `product_Except_Self = [24, 12, 8, 6]`.

    - ### Time Complexity:
        - **First pass**: We loop through the array once to calculate the prefix product, which takes **O(n)** time, where `n` is the length of the array.
        - **Second pass**: We loop through the array once more to calculate the suffix product, which also takes **O(n)** time.

        Thus, the **overall time complexity** is **O(n)**.

    - ### Space Complexity:
        - We use an additional array `product_Except_Self` to store the final result, which takes **O(n)** space.

        Thus, the **overall space complexity** is **O(n)**.

    - ### Code:
        - **Python Solution**

            ```python3 []
            class Solution:
                def productExceptSelf(self, nums: List[int]) -> List[int]:
                    # Get the length of the input list
                    n = len(nums)
                    
                    # Initialize the result list with zeros, having the same length as input
                    product_Except_Self = [0] * n

                    # Loop through each index in the input list
                    for index in range(n):
                        # Calculate the product of all elements to the left of the current index
                        left_Side_Prod = 1
                        for left_Ptr in range(0, index):  # Iterate from the start to the current index
                            left_Side_Prod *= nums[left_Ptr]  # Multiply the left-side elements

                        # Calculate the product of all elements to the right of the current index
                        right_Side_Prod = 1
                        for right_Ptr in range(index + 1, n):  # Iterate from the next index to the end
                            right_Side_Prod *= nums[right_Ptr]  # Multiply the right-side elements
                        
                        # Store the product of left and right products in the result list
                        product_Except_Self[index] = left_Side_Prod * right_Side_Prod

                    # Return the final result list
                    return product_Except_Self
            ```
            
        - **C++ Solution**

            ```C++ []
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
            ```