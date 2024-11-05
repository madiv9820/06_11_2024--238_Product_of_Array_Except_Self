from typing import List

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