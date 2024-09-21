import time
import csv

# Função Bubble Sort
def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

# Função para verificar se o vetor está ordenado
def is_sorted(arr):
    return all(arr[i] <= arr[i + 1] for i in range(len(arr) - 1))

# Tamanhos do vetor que serão testados
sizes = [100, 1000, 10000, 100000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000]

# Abrir o arquivo de resultados
with open('bubble_sort_results_python.csv', 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    writer.writerow(['N', 'Tempo_Alocacao', 'Tempo_Ordenacao', 'Tempo_Liberacao', 'Ordenado'])

    for n in sizes:
        print(f"Testando para N = {n}")

        # Medir tempo de alocação
        alloc_start = time.time()
        arr = [n - i for i in range(n)]
        alloc_end = time.time()
        alloc_time = alloc_end - alloc_start

        # Medir tempo de ordenação
        sort_start = time.time()
        bubble_sort(arr)
        sort_end = time.time()
        sort_time = sort_end - sort_start

        # Verificar se o vetor foi ordenado
        sorted_str = "true" if is_sorted(arr) else "false"

        if sorted_str == "true":
            print(f"Vetor de tamanho {n} ordenado corretamente.")
        else:
            print(f"Erro: o vetor de tamanho {n} não foi ordenado corretamente.")

        # Medir tempo de liberação
        free_start = time.time()
        del arr  # Libera a memória
        free_end = time.time()
        free_time = free_end - free_start

        # Escrever resultados no arquivo CSV
        writer.writerow([n, f"{alloc_time:.4f}", f"{sort_time:.4f}", f"{free_time:.4f}", sorted_str])
        csvfile.flush()

        # Imprimir resultados no console
        print(f"N = {n}, Tempo de Alocação = {alloc_time:.4f} s, Tempo de Ordenação = {sort_time:.4f} s, Tempo de Liberação = {free_time:.4f} s, Ordenado = {sorted_str}\n")

print("Testes concluídos e resultados salvos em bubble_sort_results_python.csv.")
