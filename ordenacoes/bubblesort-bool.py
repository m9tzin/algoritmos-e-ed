# Estrutura de Dados II
# Matheus Marinho
# Bubble Sort com boolean improvement 

def bubbleSortboolean(arr):
    for i in range(0, len(arr)-1):
        swap = False
        for j in range(0, len(arr)-1-i):
            if arr[j] > arr[j+1]:
                swap = True
                aux = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = aux

    return arr

arr = [5, 8, 2, 10, 15, 9, 25, 27, 23, 40]

print("Vetor original: ", arr)
print("")
print("Vetor ordenado: ", bubbleSortboolean(arr))
