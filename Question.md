# [238. Product of Array Except Self](https://leetcode.com/problems/product-of-array-except-self?envType=study-plan-v2&envId=top-interview-150)

__Type:__ Medium <br>
__Topics:__ Array, Prefix Sum <br>
__Companies:__ Amazon, Google, Meta, Microsoft, Uber, Bloomberg, Apple, Flipkart, Asana, TikTok, IBM, LinkedIn, Autodesk, Accenture, Yandex, Ripple, Turing, Wells Fargo, Adobe, Yahoo, Oracle, Intuit, Goldman Sachs, Warnermedia, Cisco, American Express, Docusign, Paytm
<hr>

Given an integer array `nums`, return an array `answer` such that `answer[i]` __is equal to the product of all the elements of _ `nums` _except_ `nums[i]`.

The product of any prefix or suffix of `nums` is __guaranteed__ to fit in a __32-bit__ integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.
<hr>

### Examples

- __Example 1:__ <br>
__Input:__ nums = [1,2,3,4] <br>
__Output:__ [24,12,8,6]

- __Example 2:__ <br>
__Input:__ nums = [-1,1,0,-3,3] <br>
__Output:__ [0,0,9,0,0]
<hr>

### Constraints

- <code>2 <= nums.length <= 10<sup>5</sup></code>
- `-30 <= nums[i] <= 30`
- The product of any prefix or suffix of `nums` is __guaranteed__ to fit in a __32-bit__ integer.
<hr>

### Hints
- Think how you can efficiently utilize prefix and suffix products to calculate the product of all elements except self for each index. Can you pre-compute the prefix and suffix products in linear time to avoid redundant calculations?
- Can you minimize additional space usage by reusing memory or modifying the input array to store intermediate results?