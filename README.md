# Product of Array Except Self (All Approaches)

- ## Approach 1:- Brute Force (Time Limit Exceeded)

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