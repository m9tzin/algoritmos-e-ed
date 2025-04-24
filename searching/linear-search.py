# Linear Search
# 24/04/2025
# Matheus Marinho

def linearSearch(arr, target):
    for i in range(len(arr)):
        if arr[i] == target:
            return i
    return -1
        
# Output:
if __name__ == "__main__":
    arr = [1, 20, 6, 9, 23, 10, 12, 59]
    target = 9
    t = linearSearch(arr, target)
    if t != -1:
        print("Found it!")
        print(f"Index for target: [{t}]")
    else:
        print("Not found your target")