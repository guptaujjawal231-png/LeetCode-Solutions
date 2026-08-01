class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n==1:
            return nums[0]
        def linear(nums):
            memo={}
            def f(i):
                if i>=len(nums):
                    return 0
                if i in memo:
                    return memo[i]
                rob=nums[i]+f(i+2)
                skip=f(i+1)
                memo[i]=max(rob,skip)
                return memo[i]
            return f(0)   
        return max(linear(nums[:n-1]),linear(nums[1:]) )                    

        