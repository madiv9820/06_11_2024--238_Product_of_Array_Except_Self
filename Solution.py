from typing import List

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