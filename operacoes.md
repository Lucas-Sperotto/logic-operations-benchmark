## Operações do Algoritmo Bubble Sort

Este documento detalha a quantidade de operações de **leitura**, **comparação** e **escrita** realizadas pelo algoritmo Bubble Sort para uma entrada de tamanho \( N \).

### 1. Operações de Leitura

**Leitura** refere-se ao ato de acessar um valor no vetor para realizar uma operação, seja para compará-lo ou trocá-lo.

- O **Bubble Sort** percorre o vetor várias vezes para realizar as comparações entre os elementos adjacentes. Em cada iteração do algoritmo, dois elementos são lidos para realizar uma comparação.
  
- No pior caso, quando o vetor está em ordem inversa, o algoritmo precisa realizar um total de \( \frac{N(N-1)}{2} \) comparações (já que o número de comparações diminui em uma unidade a cada iteração).
  
#### Fórmula para o número de operações de leitura:
Cada comparação requer a leitura de dois elementos, portanto o número de leituras totais é:

\[ \text{Total de leituras} = 2 \times \frac{N(N-1)}{2} = N(N-1) \]

### 2. Operações de Comparação

**Comparação** é o ato de verificar se um elemento é maior ou menor que outro. No Bubble Sort, duas comparações acontecem por iteração: uma entre dois elementos adjacentes, e outra para determinar se devemos realizar uma troca.

- O número de comparações realizadas pelo algoritmo é igual ao número de pares de elementos adjacentes comparados. Como o algoritmo faz \( N-1 \) comparações na primeira iteração, \( N-2 \) na segunda, e assim por diante, até a última comparação, o total de comparações será:

#### Fórmula para o número de operações de comparação:
\[ \text{Total de comparações} = \frac{N(N-1)}{2} \]

### 3. Operações de Escrita

**Escrita** refere-se ao ato de modificar um valor no vetor. Em cada troca de elementos, duas operações de escrita são realizadas.

- No pior caso, quando o vetor está completamente invertido, o Bubble Sort precisa realizar uma troca a cada vez que uma comparação resulta em uma ordem incorreta. Para cada troca, dois elementos são escritos. Assim, o número de trocas é igual ao número de comparações no pior caso.

#### Fórmula para o número de operações de escrita:
Cada troca envolve duas escritas, então o número total de escritas no pior caso será:

\[ \text{Total de escritas} = 2 \times \frac{N(N-1)}{2} = N(N-1) \]

### Resumo das Operações para uma Entrada de Tamanho \( N \):

- **Leituras**: \( N(N-1) \)
- **Comparações**: \( \frac{N(N-1)}{2} \)
- **Escritas**: \( N(N-1) \) (no pior caso)

### Exemplo para \( N = 100 \)

Para um vetor de tamanho \( N = 100 \):

- **Leituras**: \( 100 \times 99 = 9900 \)
- **Comparações**: \( \frac{100 \times 99}{2} = 4950 \)
- **Escritas**: \( 100 \times 99 = 9900 \) (no pior caso)
