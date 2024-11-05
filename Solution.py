from typing import List

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