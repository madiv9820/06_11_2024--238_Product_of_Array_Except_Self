- ## Approach 2:- Prefix and Suffix Product

    - ### Intuition
        - The task is to create an output array such that each element at index `i` is the product of all numbers in the input array `nums` except `nums[i]`. The challenge is to achieve this without using division and to do it efficiently.

    - ### Approach
        We can efficiently solve this problem using the concept of **prefix** and **suffix** products. The key idea is to use two auxiliary arrays:

        1. **Prefix Product Array**: This array will store the product of all elements to the left of each index. For an element at index `i`, this means multiplying all elements from index `0` to index `i-1`.

        2. **Suffix Product Array**: This array will store the product of all elements to the right of each index. For an element at index `i`, this means multiplying all elements from index `i+1` to the last index.

    - ### Detailed Steps:
        1. **Initialization**: Create three arrays:
            - `product_Except_Self` for the final result.
            - `prefix_Prod` initialized to `1`, where each index will hold the cumulative product of elements to the left.
            - `suffix_Prod` initialized to `1`, where each index will hold the cumulative product of elements to the right.

        2. **Fill the `prefix_Prod` array**:
            - Iterate from index `1` to `n-1`. Each `prefix_Prod[i]` is computed by multiplying `prefix_Prod[i-1]` with `nums[i-1]`.

        3. **Fill the `suffix_Prod` array**:
            - Iterate from index `n-2` down to `0`. Each `suffix_Prod[i]` is computed by multiplying `suffix_Prod[i+1]` with `nums[i+1]`.

        4. **Construct the `product_Except_Self` array**:
            - The first element is assigned the value of `suffix_Prod[0]`.
            - The last element is assigned the value of `prefix_Prod[n-1]`.
            - For indices `1` to `n-2`, each element is computed by multiplying the corresponding values from `prefix_Prod` and `suffix_Prod`.

    - ### Example Walkthrough:
        Consider the input array `nums = [1, 2, 3, 4]`:

        1. **Step 1 - Initialization**:
            - `n = 4`
            - `product_Except_Self = [0, 0, 0, 0]`
            - `prefix_Prod = [1, 1, 1, 1]`
            - `suffix_Prod = [1, 1, 1, 1]`

        2. **Step 2 - Fill `prefix_Prod`**:
            - For `index = 1`: `prefix_Prod[1] = prefix_Prod[0] * nums[0] = 1 * 1 = 1`
            - For `index = 2`: `prefix_Prod[2] = prefix_Prod[1] * nums[1] = 1 * 2 = 2`
            - For `index = 3`: `prefix_Prod[3] = prefix_Prod[2] * nums[2] = 2 * 3 = 6`
            - After this step, `prefix_Prod = [1, 1, 2, 6]`.

        3. **Step 3 - Fill `suffix_Prod`**:
            - For `index = 2`: `suffix_Prod[2] = suffix_Prod[3] * nums[3] = 1 * 4 = 4`
            - For `index = 1`: `suffix_Prod[1] = suffix_Prod[2] * nums[2] = 4 * 3 = 12`
            - For `index = 0`: `suffix_Prod[0] = suffix_Prod[1] * nums[1] = 12 * 2 = 24`
            - After this step, `suffix_Prod = [24, 12, 4, 1]`.

        4. **Step 4 - Construct `product_Except_Self`**:
            - `product_Except_Self[0] = suffix_Prod[0] = 24`
            - `product_Except_Self[3] = prefix_Prod[3] = 6`
            - For `index = 1`: `product_Except_Self[1] = prefix_Prod[1] * suffix_Prod[1] = 1 * 12 = 12`
            - For `index = 2`: `product_Except_Self[2] = prefix_Prod[2] * suffix_Prod[2] = 2 * 4 = 8`
            - Final result: `product_Except_Self = [24, 12, 8, 6]`.

    - ### Time Complexity
        - **Filling the `prefix_Prod` array**: O(n)
        - **Filling the `suffix_Prod` array**: O(n)
        - **Constructing the `product_Except_Self` array**: O(n)

        Thus, the overall **time complexity** is **O(n)**.

    - ### Space Complexity
        - We use three arrays (`product_Except_Self`, `prefix_Prod`, and `suffix_Prod`), each of size `n`.
        - Therefore, the **space complexity** is **O(n)**.

    - ### Code
        - **Python Solution**

            ```python3
            class Solution:
                def productExceptSelf(self, nums: List[int]) -> List[int]:
                    # Step 1: Initialize the length of the input list and arrays for the result, prefix products, and suffix products
                    n = len(nums)
                    product_Except_Self = [0] * n  # To store the result
                    prefix_prod = [1] * n          # To store the product of elements to the left of each index
                    suffix_prod = [1] * n          # To store the product of elements to the right of each index

                    # Step 2: Fill the prefix_prod array
                    # prefix_prod[i] will store the product of all elements before index i
                    for index in range(1, n):
                        prefix_prod[index] = prefix_prod[index-1] * nums[index-1]

                    # Step 3: Fill the suffix_prod array
                    # suffix_prod[i] will store the product of all elements after index i
                    for index in range(n-2, -1, -1):
                        suffix_prod[index] = suffix_prod[index+1] * nums[index+1]

                    # Step 4: The first element in the result is the suffix product at index 0
                    # The last element in the result is the prefix product at index n-1
                    product_Except_Self[0] = suffix_prod[0]
                    product_Except_Self[n-1] = prefix_prod[n-1]

                    # Step 5: For the remaining elements, multiply the corresponding prefix and suffix products
                    for index in range(1, n-1):
                        product_Except_Self[index] = suffix_prod[index] * prefix_prod[index]

                    # Step 6: Return the final result
                    return product_Except_Self
            ```

        - **C++ Solution**

            ```C++ []
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
            ```