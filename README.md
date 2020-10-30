# Influência da organização de memória no desempenho de um sistema.

A análise e execução desse experimento é uma
[avaliação](https://github.com/UellingtonDamasceno/DGEMM-memory-analysis/blob/main/info/description.pdf)
da disciplina arquitetura de compuadores (TEC402). 

Esse``README`` apresenta os passos e quais critérios foram 
considerados para a execução de um comparativo entre dois algoritmos de
multiplicação de [matrizes quadradas](https://github.com/UellingtonDamasceno/DGEMM-memory-analysis/tree/main/res)
povoadas com valores de ponto flutuante a fim de verificar os impactos
gerados pelo padrão de acesso a memória. 


## Sumário
- [Ambiente de desenvolvimento](#ambiente-de-desenvolvimento)
  - [Software](#software)
  - [Hardware](#hardware)
- [Experimentos](#experimentos)
  - [Códigos fonte](#códigos-fonte)
  - [Redução de ruído](#redução-de-ruído)
  - [Complexidade dos algoritmos](#complexidade-dos-algoritmos)
- [Resultados](#resultados)
- [Conclusão](#conclusão)

## Ambiente de desenvolvimento
Os experimentos foram executados em um ambiente de baseado em linux com as
seguintes configurações de ***software*** e ***hardware***:

### Software
  - **Distro:** Linux Mint 19.3 Tricia XFCE
  - **Base:** Ubuntu 18.04
  - **Compilador:** GCC 8.4.3 


### Hardware
O processador utilizado nos experimentos possui as seguintes configurações:

  - **Processador:** Intel Core i3-4005U
  - **Frequência:** 1.7 GHz
  - **Número de CPU cores:** 2
  - **Largura do dado:** 64 bits

O processador utilizado possui uma interface controladora de memória com 
uma capacidade máxima de gerenciamento de até 16 GB. capaz de ler ou escrever 
dados a uma taxa máxima de 25.6 GB/s. Para auxiliar o desempenho a memória está
organizada da seguinte maneira:

  - **Cache**
    - **L1i:** 32 KB de cache para instruções.
    - **L1d:** 32 KB de cache para dados.
    - **L2:** 2 blocos de 256 KB de cache associativos de 8 vias.
    - **L3:** Cache compartilhado associativo de 3 MB com 12 vias.
  - **Memória RAM**
    - **Tamanho:** 4 GB
    - **Tipo:** DDR3L
    - **Tecnologia:** DRAM
    - **Frequência:** 1600 MHz
    
O barramento utilizado para fazer a comunicação entre os componentes possui uma valocidade de 5 GT/s.

## Experimentos
Os experimentos foram feitos seguindo o seguinte protocolo de ações: Para 
cada algoritmo de multiplicação, sendo ele sem otimização, com otimização
de blocos de 32 e 64 de tamanho foram medidos 5 tempos de execução e, em
seguida foi removido o valor mais lento e rápido. Dessa forma foram 
executados um total de 20 testes e para automatizar esse processo foi 
desenvolvido um *script*. Para além disso processos não vitais e o 
ambiente gráfico foram removidos a fim de diminuir os efeitos de outrs 
processos em cima dos resultados.

### Códigos fonte
### Redução de ruído
Durante o experimento o nḿero de processos que estavam sendo executados foram
reduzidos consideravelmente para diminuir as interferências causadas pela mudança
de contexto. Par que isso fosse possível o ambiente gráfico e processos não 
vitais que inicializavam com o sistema foram removidos. Dessa forma foi possível executar
os experimentos em um ambiente com 77 *tasks* que consumiam um total de 133 MB de memória RAM.

### Complexidade dos algoritmos
Um algoritmo de multiplicação de matrizes sem otimização consiste em três *loops* 
"for" aninhados. Onde cada *loop* executa N vezes, sendo N o tamanho da matriz.
No *loop* mais interno, é feita uma operação de adição e outra de multiplicação. 
Por tanto é possível afirmar que a complexidade de execução desse algoritmo é O(n^3) 
operações de ponto flutuante.

O algoritmo abaixo equivale a uma implementação ingenua do algoritmo de multiplicação de 
matrizes. 

```c
for (int i = 0; i < n; ++i) {
  for(int j = 0; j < n; ++j) {
    double cij = 0;
    for (int k = 0; k < n; k++) {
      cij += A[i+k*n] * B[k+j*n]; /*cij += A[i][k]*B[k][j]*/
    }
    C[i+j*n] = cij; /* C[i][j] = cij*/
  }
}

```

Considerando o fato de que cda execução do laço mais interno duas 
operações são realizadas, é possível afirmar que a quantidade de operações 
de ponto flutuante necessária para multiplicar cada matriz é dada pela 
equção 2 * N^3. Dessa forma temos a seguinte tabela:

|Tamanho Matriz | FLOPS |
|---|---|
|64|524.288|
|192|14.155.776|
|512|268.435.456|
|1920|14.155.776.000|

## Resultados
A tabela abaixo expõe os resultados que foram gerados ao executar os 
experimentos seguinto o protocolo apresentado [anteriormente]
(#experimentos). Por questão de visualização, os algoritmos foram 
renomeados da seguite forma: **DGEMM** corresponde ao algoritmo de 
multiplicação sem otimização; **DGEMM B32** e **DGEMM B64** correspondem 
ao algoritmo com otimização de blocos de 32 e 64 de tamanho, 
respectivamente.


## Conclusão
