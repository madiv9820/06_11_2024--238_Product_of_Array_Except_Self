from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([1,2,3,4], [24,12,8,6]), 2: ([-1,1,0,-3,3], [0,0,9,0,0])}
        self.__obj = Solution()
        return super().setUp()

    def __is_Same(self, result, output):
        if len(result) != len(output): return False
        
        for i in range(len(result)):
            if result[i] != output[i]: return False

        return True

    @timeout(0.5)
    def test_Case1(self):
        nums, output = self.__testCases[1]
        result = self.__obj.productExceptSelf(nums = nums)
        self.assertIsInstance(result, list)
        self.assertTrue(self.__is_Same(result, output))

    @timeout(0.5)
    def test_Case2(self):
        nums, output = self.__testCases[2]
        result = self.__obj.productExceptSelf(nums = nums)
        self.assertIsInstance(result, list)
        self.assertTrue(self.__is_Same(result, output))

if __name__ == '__main__': unittest.main()