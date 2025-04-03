# Estrutura de Dados II
# Matheus Marinho
# Quick Sort

def particaoVetor(left, right, i, j, arr):
    i = left
    j = right
    x = arr[(i+j)//2] # Escolha do pivô sendo o elemento central

    while True:
        # Buscando elementos maiores que o pivô (>)
        while arr[i] < x:
            i += 1 
        # Buscando elementos menores que o pivô (<)
        while arr[j] > x:
            j -= 1
        # Troca, se necessário:
        if i <= j:
            aux = arr[i]
            arr[i] = arr[j]
            arr[j] = aux
            i += 1
            j -= 1
        else:
            break 

    return i, j

def ordenaVetor(left, right, arr):
    if left < right:
        i, j = left, right
        i, j = particaoVetor(left, right, i, j, arr)
        ordenaVetor(left, j, arr) # Ordenaçao (<)
        ordenaVetor(i, right, arr) # Ordenacao (>)

def quickSort(arr):
    ordenaVetor(0, len(arr)-1, arr)
    return arr

# Input:    
arr = [50, 16, 23, 5, 7, 12, 10]

# Output:
# Array original:  [50, 16, 23, 5, 7, 12, 10]
# Array ordenado:  [5, 7, 10, 12, 16, 23, 50]

print("Array original: ", arr)
print("Array ordenado: ", quickSort(arr))
print("Menor valor: ", arr[0])
print("Maior valor: ", arr[len(arr)-1])