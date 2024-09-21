#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>

using namespace std;

// Protótipos das funções
void bubbleSort(vector<int>& arr);
bool isSorted(const vector<int>& arr);

int main() {
    // Tamanhos do vetor que serão testados
    vector<int> sizes = {100, 1000, 10000, 100000, 1000000, 2000000, 3000000, 4000000, 5000000, 6000000, 7000000, 8000000, 9000000, 10000000};
    
    // Abre o arquivo de resultados
    ofstream file("bubble_sort_results_cpp.dat");
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo!\n";
        return 1;
    }

    // Escreve o cabeçalho no arquivo
    file << "N,Tempo_Alocacao,Tempo_Ordenacao,Tempo_Liberacao,Ordenado\n";

    for (int n : sizes) {
        cout << "Testando para N = " << n << endl;

        // Medir tempo de alocação de memória
        clock_t alloc_start = clock();
        vector<int> arr(n);
        clock_t alloc_end = clock();
        double alloc_time = double(alloc_end - alloc_start) / CLOCKS_PER_SEC;

        // Inicializa o vetor em ordem inversa
        for (int i = 0; i < n; ++i) {
            arr[i] = n - i;
        }

        // Medir tempo de ordenação
        clock_t sort_start = clock();
        bubbleSort(arr);
        clock_t sort_end = clock();
        double sort_time = double(sort_end - sort_start) / CLOCKS_PER_SEC;

        // Verificar se o vetor foi ordenado corretamente
        bool sorted = isSorted(arr);
        string sorted_str = sorted ? "true" : "false";

        if (sorted) {
            cout << "Vetor de tamanho " << n << " ordenado corretamente.\n";
        } else {
            cout << "Erro: o vetor de tamanho " << n << " não foi ordenado corretamente.\n";
        }

        // Medir tempo de liberação de memória
        clock_t free_start = clock();
        arr.clear();  // Libera a memória alocada pelo vetor
        clock_t free_end = clock();
        double free_time = double(free_end - free_start) / CLOCKS_PER_SEC;

        // Escrever resultados no arquivo
        file << n << "," << alloc_time << "," << sort_time << "," << free_time << "," << sorted_str << "\n";
        file.flush();

        // Imprimir resultados no console
        cout << "N = " << n << ", Tempo de Alocação = " << alloc_time << " s, Tempo de Ordenação = " << sort_time 
             << " s, Tempo de Liberação = " << free_time << " s, Ordenado = " << sorted_str << "\n\n";
    }

    // Fecha o arquivo
    file.close();
    cout << "Testes concluídos e resultados salvos em bubble_sort_results_cpp.dat.\n";
    
    return 0;
}

// Função Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Função para verificar se o vetor está ordenado
bool isSorted(const vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}
