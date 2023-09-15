#include <iostream>
#include <cstdlib>
#include <ctime>

const int N = 20; // tamanho da matriz
const int num_iterations = 100; // n�mero de itera��es
const int num_races = 3; // n�mero de ra�as



// fun��o para gerar valores aleat�rios
int rand_int(int min, int max) {
  return min + (std::rand() % (max - min + 1));
}

// fun��o para imprimir a matriz
void print_matrix(int matrix[N][N]) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << matrix[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  // inicializar gerador de n�meros aleat�rios
  std::srand(std::time(0));

  // criar matriz
  int matrix[N][N];
  
  // preencher a matriz com valores aleat�rios                   
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

  // loop pelo n�mero de itera��es
  for (int it = 0; it < num_iterations; it++) {
    // loop pelos elementos da matriz
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        // calcular quantos vizinhos s�o iguais ao elemento atual
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

        // se o elemento tiver menos de 5 vizinhos iguais, escolher novo valor aleat�rio para ele
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
