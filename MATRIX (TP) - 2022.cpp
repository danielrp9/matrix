/*O objetivo deste trabalho é colocar em prática a concepção trabalhada por
Schelling sobre os fundamentos de seu modelo de segregação aplicando-o na
construção de um algoritmo com características dimensionais (matriz) que buscam se
aproximar, de forma dinâmica e autônoma, considerando a lógica de aleatoriedades
por definições de características determinadas pela regra de Limite ou Tolerância do
que foi proposto por ele, satisfazendo a necessidade espacial das pessoas dentro da
situação de segregação social.*/

#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 20; // tamanho da matriz
const int num_iterations = 100; // número de iterações
const int num_races = 3; // número de raças



// função para gerar valores aleatórios
int rand_int(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}

// função para imprimir a matriz
void print_matrix(int matrix[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  // inicializar gerador de números aleatórios
  std::srand(std::time(0));

  // criar matriz
  int matrix[N][N];
  
  // preencher a matriz com valores aleatórios                   
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      matrix[i][j] = rand_int(1, num_races-1 );
    }
  }

// Insere 10% dos valores como 0
for (int i = 0; i < N; i++)
{
    for (int j = 0; j < N; j++)
    {
        if (rand() % 6 == 0)
        {
            matrix[i][j] = 0;
        }
    }
}
  // imprimir matriz inicial
  std::cout << "Matriz inicial:\n";
  print_matrix(matrix);

  // loop pelo número de iterações
  for (int it = 0; it < num_iterations; it++) {
    // loop pelos elementos da matriz
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        // calcular quantos vizinhos são iguais ao elemento atual
        int num_neighbors = 0;
        if (i > 0 && matrix[i - 1][j] == matrix[i][j]) num_neighbors++;
        if (i < N - 1 && matrix[i + 1][j] == matrix[i][j]) num_neighbors++;
        if (j > 0 && matrix[i][j - 1] == matrix[i][j]) num_neighbors++;
        if (j < N - 1 && matrix[i][j + 1] == matrix[i][j]) num_neighbors++;

        if (i > 0 && matrix[i - 1][j] == matrix[i][j]) num_neighbors++;
        if (i < N - 1 && matrix[i + 1][j] == matrix[i][j]) num_neighbors++;
        if (i > 0 && matrix[i - 1][j] == matrix[i][j]) num_neighbors++;
        if (i < N - 1 && matrix[i + 1][j] == matrix[i][j]) num_neighbors++;


        if (i > 0 && matrix[i - 1][j] == matrix[i][j]) num_neighbors++;
        if (i < N - 1 && matrix[i + 1][j] == matrix[i][j]) num_neighbors++;

        // se o elemento tiver menos de 5 vizinhos iguais, escolher novo valor aleatório para ele
        if (num_neighbors < 5) matrix[i][j] = rand_int( 0, num_races-1 );
      }
    }
  }


  // imprimir matriz final
  std::cout << "\nMatriz final:\n";
  print_matrix(matrix);

std::cout << std::endl;
    
  system("PAUSE");
 return EXIT_SUCCESS;
}
