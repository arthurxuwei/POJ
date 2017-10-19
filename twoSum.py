
nums = [2, 7, 11, 15]
target = 9

def twoSum(nums, target):
    if target in nums:
        return [nums.index(target)]
    
    i = 0
    while nums:
        t = nums.pop(0)
        r = target - t
        print target, t, r
        if r in nums:
            return [i, nums.index(r) + i + 1]
        else:
            i += 1

print twoSum(nums, target)
