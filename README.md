- ## Approach 1:- Using Nested Loops (Brute Force) 

    - ### Problem Intuition:
        - Given an array `nums`, we are tasked with returning an array where each element at index `i` is the product of all elements in the array except `nums[i]`. The challenge is to do this without using division and while optimizing for time complexity.

    - ### Approach:
        - We will solve this problem using a **brute-force** approach, which directly computes the product of all elements except the one at the current index by using nested loops.

    - ### Detailed Steps:
        1. **Initialize** an empty result array `product_Except_Self` of the same length as the input array `nums`.
        2. For each element in the array at index `i`, calculate the **left product** (product of all elements before `i`) and **right product** (product of all elements after `i`).
        3. The final result for each index `i` is computed as the product of the left product and right product for that index.

    - ### Code Explanation:
        1. **Outer Loop**: Iterates through each element in the array `nums`.
        2. **Inner Loops**:
            - The first inner loop calculates the product of all elements to the left of the current index `i`.
            - The second inner loop calculates the product of all elements to the right of the current index `i`.
        3. **Final Computation**: The product of the left and right products is stored in the result array for each index `i`.

    - ### Example Walkthrough:
        Consider the array `nums = [1, 2, 3, 4]`:

        1. **For index 0**:
            - Left product: No elements to the left → `1`.
            - Right product: `2 * 3 * 4 = 24`.
            - Result at index 0 = `1 * 24 = 24`.

        2. **For index 1**:
            - Left product: `1`.
            - Right product: `3 * 4 = 12`.
            - Result at index 1 = `1 * 12 = 12`.

        3. **For index 2**:
            - Left product: `1 * 2 = 2`.
            - Right product: `4`.
            - Result at index 2 = `2 * 4 = 8`.

        4. **For index 3**:
            - Left product: `1 * 2 * 3 = 6`.
            - Right product: No elements to the right → `1`.
            - Result at index 3 = `6 * 1 = 6`.

        Thus, the final result is `[24, 12, 8, 6]`.

    - ### Time Complexity:
        - **First inner loop**: For each index `i`, we loop through all the elements before it, which takes **O(i)** time.
        - **Second inner loop**: For each index `i`, we loop through all the elements after it, which takes **O(n - i - 1)** time.
  
        Since both loops are nested inside the outer loop, the overall **time complexity** is **O(n<sup>2</sup>)**.

    - ### Space Complexity:
        - The space complexity is **O(n)** because we are using an additional array `product_Except_Self` to store the results, which has the same size as the input array `nums`.

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