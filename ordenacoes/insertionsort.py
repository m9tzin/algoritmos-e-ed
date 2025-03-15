# Estrutura de Dados II
# Matheus Marinho
# Insertion Sort

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        aux = i
        while j >= 0 and key < arr[j]:
            arr[aux] = arr[j]
            arr[j] = key
            j = j - 1
            aux = aux - 1
    return arr

# Input:    
arr = [50, 16, 23, 5, 7, 12, 10]

# Output:
# Array original:  [50, 16, 23, 5, 7, 12, 10]
# Array ordenado:  [5, 7, 10, 12, 16, 23, 50]

print("Array original: ", arr)
print("Array ordenado: ", insertionSort(arr))
print("Menor valor: ", arr[0])
print("Maior valor: ", arr[len(arr)-1])