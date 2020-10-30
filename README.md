# Influência da organização de memória no desempenho de um sistema.

A análise e execução desse experimento é uma [avaliação](https://github.com/UellingtonDamasceno/DGEMM-memory-analysis/blob/main/info/description.pdf) da disciplina arquitetura de compuadores (TEC402). 

Esse``README`` apresenta os passos e quais critérios foram 
considerados para a execução de um comparativo entre dois algoritmos de
multiplicação de matrizes quadradas povoadas com valores de ponto flutuante
a fim de verificar os impactos gerados pelo padrão de acesso a memória. 


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
seguintes configurações de "software" e "hardware":

### Software
  - **Distro:** Linux Mint 19.3 Tricia
  - **Base:** Ubuntu 18.04
  - **Compilador:** GCC 8.4.3 


### Hardware

O processador utilizado nos experimentos possui as seguintes configurações:

  - **Processador:** Intel Core i3-4005U
  - **Frequência:** 1.7 GHz
  - **Número de CPU cores:** 2
  - **Largura do dado:** 64 bits

O processador utilizado possui uma interface controladora de memória com 
uma capacidade máxima de gerenciamento de até 16 GB. capaz de ler ou escrever dados a uma taxa máxima de 25.6 GB/s. Para auxiliar o desempenho a memória está organizada da seguinte maneira:

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
### Códigos fonte
### Redução de ruído
### Complexidade dos algoritmos
## Resultados
## Conclusão
