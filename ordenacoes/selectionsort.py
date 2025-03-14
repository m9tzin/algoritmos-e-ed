# Estrutura de Dados II
# Matheus Marinho
# Selection Sort

def selectionSort(arr):
    for i in range(len(arr)):
        menor = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[menor]:
                menor = j
        if menor != i:
            aux = arr[i]
            arr[i] = arr[menor]
            arr[menor] = aux
    return arr

# Input:    
arr = [50, 16, 23, 5, 7, 12, 10]

# Output:
# Array original:  [50, 16, 23, 5, 7, 12, 10]
# Array ordenado:  [7, 5, 10, 12, 23, 16, 50]

print("Array original: ", arr)
print("Array ordenado: ", selectionSort(arr))
