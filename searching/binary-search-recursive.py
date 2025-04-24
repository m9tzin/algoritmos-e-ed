# Recursive Binary Search
# 24/04/2025
# Matheus Marinho

def binarySearchRecursive(arr, target, left, right):
    mid = (left + right) // 2
    if arr[mid] == target:
        return mid
    elif arr[mid] > target:
        return binarySearchRecursive(arr, target, left, mid - 1)
    else:
        return binarySearchRecursive(arr, target, mid + 1, right)


if __name__ == "__main__":
    arr = [1,2,3,4,5,6,7,8,9,10]
    target = 8
    r = binarySearchRecursive(arr, target, 0, len(arr)-1)
    print(f"Index of target: {r}")