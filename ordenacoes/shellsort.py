# 
# Estrutura de Dados II
# Matheus Marinho
# Shell Sort
#

def shellSort(arr):
    h = 1
    while h < len(arr):
        h = 3*h + 1
    while h > 1:
        h = h//3
        for i in range(h, len(arr)):
            chave = arr[i]
            j = i - h
            while j >= 0 and chave < arr[j]:
                arr[j + h] = arr[j]
                j = j - h
            arr[j + h] = chave
        print(f"Vetor apos h={h}: {arr}") #fstring
    
    return arr

# Input:    
arr = [50, 16, 23, 5, 7, 12, 10]

# Output:
# Array original:  [50, 16, 23, 5, 7, 12, 10]
# Array ordenado:  [5, 7, 10, 12, 16, 23, 50

print("Array original: ", arr)
arr = shellSort(arr)
print("Array ordenado: ", arr)
print("Menor valor: ", arr[0])
print("Maior valor: ", arr[len(arr)-1])