- ## Approach 3:- Optimized Brute Force

    - ### Intuition
        - We need to create an output array where each element at index `i` is the product of all elements in the input array except the element at `i`, without using division. Handling zeros in the array adds a layer of complexity since they affect the product outcome.

    - ### Approach
        1. **Count Zeros and Compute Product**:
            - First, we calculate the total product of all non-zero elements and keep track of the number of zeros in the input array.
            - This zero count is crucial:
                - If there are **no zeros**, each element in the output can be computed as the total product divided by the element at that index.
                - If there is **exactly one zero**, the output array will contain zeroes everywhere except at the index of that zero, which will be equal to the product of all non-zero elements.
                - If there are **more than one zero**, all elements in the output array will be zero.

        2. **Construct the Output Array**:
            - Based on the count of zeros:
                - **No Zeros**: For each index, the output value is calculated as `total_Product / nums[i]`.
                - **One Zero**: Set the output at the zero's index to `total_Product` (since this position can have a non-zero product), while all other indices remain zero.
                - **More than One Zero**: Keep all elements in the output as zero, as any product with more than one zero will result in zero.

    - ### Example Walkthrough
        Consider the input array `nums = [1, 2, 3, 4]`:

        1. **Count Zeros and Product Calculation**:
            - `total_Product = 1 * 2 * 3 * 4 = 24`
            - `count_Zeros = 0` (no zero elements)

        2. **Build Output Array**:
            - For each element in `nums`, divide `total_Product` by that element:
                - `output[0] = 24 / 1 = 24`
                - `output[1] = 24 / 2 = 12`
                - `output[2] = 24 / 3 = 8`
                - `output[3] = 24 / 4 = 6`
            - Final output: `[24, 12, 8, 6]`

            Now, for an example with one zero:
            - `nums = [1, 2, 0, 4]`
                - `total_Product = 1 * 2 * 4 = 8` (ignoring zero)
                - `count_Zeros = 1`
            - Set `output[2]` (index of the zero) to `total_Product`, while all other elements remain zero.
            - Final output: `[0, 0, 8, 0]`

    - ### Time Complexity
        - **Counting zeros and calculating total product**: O(n)
        - **Constructing the output**: O(n)

        Overall **time complexity** is **O(n)**.

    - ### Space Complexity
        - We use a single output array of size `n`, so the **space complexity** is **O(n)**.

    - ### Code
        - **Python Solution**

            ```python3 []
            class Solution:
                def productExceptSelf(self, nums: List[int]) -> List[int]:
                    # Get the length of the input list
                    n = len(nums)
                    
                    # Initialize the result list with zeros, having the same length as input
                    # `product_Except_Self` will hold the final output where each element is the product of all elements except itself
                    product_Except_Self = [0] * n
                    
                    # Initialize variables to count the number of zeros and to store the product of all non-zero elements
                    count_Zeros, total_Product = 0, 1

                    # First pass: calculate the total product of all non-zero elements and count the zeros
                    for value in nums:
                        if value == 0:
                            # If the element is zero, increment the zero counter
                            count_Zeros += 1
                        else:
                            # Otherwise, multiply it into `total_Product`
                            total_Product *= value

                    # Second pass: determine the result based on the number of zeros found
                    if count_Zeros == 1:
                        # If there is exactly one zero, only the index where the zero occurs should have a non-zero product
                        # This will be the product of all non-zero elements
                        index = nums.index(0)  # Find the index of the zero in the list
                        product_Except_Self[index] = total_Product
                    elif count_Zeros == 0:
                        # If there are no zeros, divide the `total_Product` by each element in `nums`
                        # This gives the product of all elements except the current one at each index
                        for index in range(n):
                            product_Except_Self[index] = total_Product // nums[index]

                    # If there are more than one zero, `product_Except_Self` remains all zeros since the product of all elements except any one will be zero

                    # Return the final result list
                    return product_Except_Self
            ```

        - **C++ Solution**

            ```C++ []
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
            ```