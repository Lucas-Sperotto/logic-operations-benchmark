#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções
void bubbleSort(int arr[], int n);
int isSorted(int arr[], int n);

int main() {
    // Tamanhos do vetor que serão testados
    int sizes[] = {100, 1000, 10000, 100000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000};
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);

    // Abre o arquivo .dat para gravar os resultados
    FILE *fp = fopen("bubble_sort_results.dat", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    // Escreve o cabeçalho no arquivo
    fprintf(fp, "N,Tempo_Alocacao,Tempo_Ordenacao,Tempo_Liberacao,Ordenado\n");
    fflush(fp);  // Garante que o cabeçalho seja gravado no arquivo imediatamente

    // Loop para cada tamanho de vetor
    for (int t = 0; t < num_tests; t++) {
        int n = sizes[t];  // Tamanho atual do vetor
        printf("Testando para N = %d\n", n);

        // Medir tempo de alocação de memória
        clock_t alloc_start = clock();
        int *arr = (int *)malloc(n * sizeof(int));  // Aloca memória para o vetor
        if (arr == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }
        clock_t alloc_end = clock();
        double alloc_time = ((double)(alloc_end - alloc_start)) / CLOCKS_PER_SEC;

        // Inicializa o vetor em ordem inversa (ex.: n, n-1, n-2, ..., 1)
        for (int i = 0; i < n; i++) {
            arr[i] = n - i;
        }

        // Medir tempo de execução do Bubble Sort
        clock_t sort_start = clock();
        bubbleSort(arr, n);
        clock_t sort_end = clock();
        double sort_time = ((double)(sort_end - sort_start)) / CLOCKS_PER_SEC;

        // Verificar se o vetor foi ordenado corretamente
        int sorted = isSorted(arr, n);  // Função que verifica se o vetor está ordenado
        const char *sorted_str = sorted ? "true" : "false";  // Converte para string "true" ou "false"

        if (sorted) {
            printf("Vetor de tamanho %d ordenado corretamente.\n", n);
        } else {
            printf("Erro: o vetor de tamanho %d não foi ordenado corretamente.\n", n);
        }

        // Medir tempo de liberação de memória
        clock_t free_start = clock();
        free(arr);  // Libera a memória alocada
        clock_t free_end = clock();
        double free_time = ((double)(free_end - free_start)) / CLOCKS_PER_SEC;

        // Salvar resultados no arquivo .dat no formato CSV (valores separados por vírgula)
        fprintf(fp, "%d,%.4f,%.4f,%.4f,%s\n", n, alloc_time, sort_time, free_time, sorted_str);
        fflush(fp);  // Força a gravação no arquivo a cada iteração

        // Imprimir os resultados na tela
        printf("N = %d, Tempo de Alocação = %.4f s, Tempo de Ordenação = %.4f s, Tempo de Liberação = %.4f s, Ordenado = %s\n\n",
               n, alloc_time, sort_time, free_time, sorted_str);
    }

    // Fecha o arquivo
    fclose(fp);
    printf("Testes concluídos e resultados salvos em bubble_sort_results.dat.\n");

    return 0;
}

// Função Bubble Sort: ordena o array em ordem crescente
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos adjacentes
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para verificar se o array está ordenado
int isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;  // Não está ordenado
        }
    }
    return 1;  // Está ordenado
}
