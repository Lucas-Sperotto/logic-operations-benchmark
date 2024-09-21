## Logic Operations Benchmark

### Descrição

Este repositório contém benchmarks para medir o desempenho de algoritmos de ordenação (Bubble Sort) aplicados a operações lógicas em diferentes linguagens de programação. O objetivo é comparar o tempo de execução para alocação, ordenação e liberação de memória para vetores de tamanhos variados.

As linguagens implementadas neste projeto incluem:
- C
- C++
- Python
- Java
- Rust
- Elixir

### Linguagens e Arquivos

Cada implementação cria um arquivo de resultados em formato CSV contendo:
- O tamanho do vetor (`N`)
- Tempo de alocação de memória
- Tempo de execução do Bubble Sort
- Tempo de liberação de memória
- Um indicador de se o vetor foi corretamente ordenado (`true` ou `false`)

Os arquivos de código estão divididos conforme a linguagem:
- `bubble_sort_benchmark.c` (C)
- `bubble_sort_benchmark.cpp` (C++)
- `bubble_sort_benchmark.py` (Python)
- `BubbleSortBenchmark.java` (Java)
- `bubble_sort_benchmark.rs` (Rust)
- `bubble_sort_benchmark.exs` (Elixir)

Os arquivos de resultados gerados terão nomes que indicam a linguagem:
- `bubble_sort_results_c.dat`
- `bubble_sort_results_cpp.dat`
- `bubble_sort_results_python.csv`
- `bubble_sort_results_java.csv`
- `bubble_sort_results_rust.csv`
- `bubble_sort_results_elixir.csv`

### Como Executar

#### C
1. Compile o código:
   ```bash
   gcc bubble_sort_benchmark.c -o bubble_sort_benchmark
   ```
2. Execute o programa:
   ```bash
   ./bubble_sort_benchmark
   ```

#### C++
1. Compile o código:
   ```bash
   g++ bubble_sort_benchmark.cpp -o bubble_sort_benchmark
   ```
2. Execute o programa:
   ```bash
   ./bubble_sort_benchmark
   ```

#### Python
1. Execute o código diretamente:
   ```bash
   python bubble_sort_benchmark.py
   ```

#### Java
1. Compile o código:
   ```bash
   javac BubbleSortBenchmark.java
   ```
2. Execute o programa:
   ```bash
   java BubbleSortBenchmark
   ```

#### Rust
1. Compile o código:
   ```bash
   rustc bubble_sort_benchmark.rs
   ```
2. Execute o programa:
   ```bash
   ./bubble_sort_benchmark
   ```

#### Elixir
1. Execute o código diretamente:
   ```bash
   elixir bubble_sort_benchmark.exs
   ```

### Tamanhos de Vetores Testados

Os benchmarks são executados com os seguintes tamanhos de vetores:
- 100
- 1.000
- 10.000
- 100.000
- 1.000.000
- 2.000.000
- 3.000.000
- 4.000.000
- 5.000.000
- 6.000.000
- 7.000.000
- 8.000.000
- 9.000.000
- 10.000.000

### Resultados

Cada implementação gera um arquivo de resultados em formato CSV ou DAT, onde são registrados os tempos de alocação, ordenação e liberação de memória, além de um indicador se o vetor foi ordenado corretamente. Esses arquivos podem ser utilizados para análise de desempenho e visualização dos dados em gráficos.

### Contribuindo

Se desejar contribuir com melhorias ou novas linguagens, siga estes passos:
1. Fork o repositório.
2. Crie uma branch para a sua contribuição.
3. Adicione suas mudanças e faça o commit.
4. Crie um pull request com a sua contribuição.

### Licença

Este projeto é licenciado sob a licença MIT. Veja o arquivo `LICENSE` para mais detalhes.
