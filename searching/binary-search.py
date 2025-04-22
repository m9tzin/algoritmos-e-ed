# Estrutura de Dados II
# Matheus Marinho
# Binary Search

"It is used for a sorted array. It mainly compares the array's middle element first and if the middle element is same as input, then it returns. Otherwise it searches in either left half or right half based on comparison result."

from typing import List

def binarySearch(nums, target):
    left, right = 0, len(nums)-1
    while (left <= right):
        mid = (left + right) // 2
        if nums[mid] < target:
            left = mid + 1
        elif nums[mid] > target: 
            right = mid - 1
        else:
            return mid

nums = [1, 2, 3, 4, 5, 6, 7, 8]
target = 7
x = binarySearch(nums, target)
print("nums: ", nums)
print(f"index of target: {x}")