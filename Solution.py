from typing import List

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