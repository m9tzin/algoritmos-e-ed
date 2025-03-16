# Estrutura de Dados II
# Matheus Marinho
# Bubble Sort

def bubbleSort(arr):
    for i in range(0, len(arr)-1):
        for j in range (1, len(arr)-i):
            if arr[j-1] > arr[j]:
                aux = arr[j-1]
                arr[j-1] = arr[j]
                arr[j] = aux
    return arr

# Input:    
arr = [50, 16, 23, 5, 7, 12, 10]

# Output:
# Array original:  [50, 16, 23, 5, 7, 12, 10]
# Array ordenado:  [5, 7, 10, 12, 16, 23, 50]

print("Array original: ", arr)
print("Array ordenado: ", bubbleSort(arr))
print("Menor valor: ", arr[0])
print("Maior valor: ", arr[len(arr)-1])