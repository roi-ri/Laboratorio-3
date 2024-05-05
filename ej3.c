#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int findLargestSquare(int matrix[][MAX_SIZE], int size) {
    int maxSquareSize = 0;

    // Recorremos la matriz para encontrar el tamaño del cuadrado más grande
    for (int i = 0; i < size - maxSquareSize; i++) {
        for (int j = 0; j < size - maxSquareSize; j++) {
            int currentSquareSize = 0;
            while (i + currentSquareSize < size &&
                   j + currentSquareSize < size &&
                   matrix[i + currentSquareSize][j] &&
                   matrix[i][j + currentSquareSize]) {
                currentSquareSize++;
            }
            if (currentSquareSize > maxSquareSize) {
                maxSquareSize = currentSquareSize;
            }
        }
    }

    return maxSquareSize;
}

int main() {
    int size;
    printf("Ingrese el tamaño de la matriz (entre 1 y 10): ");
    scanf("%d", &size);

    // Validación del tamaño de la matriz
    if (size < 1 || size > MAX_SIZE) {
        printf("Tamaño no válido. Se usará el valor por defecto: %d\n", MAX_SIZE);
        size = MAX_SIZE;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    // Llenar la matriz de manera aleatoria con valores binarios (0 o 1)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 2; // Generar un número aleatorio entre 0 y 1
        }
    }

    printf("Matriz generada:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    int largestSquareSize = findLargestSquare(matrix, size);
    printf("El tamaño del cuadrado más grande de unos es: %dx%d\n", largestSquareSize,  largestSquareSize);

    return 0;
}
