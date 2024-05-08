#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int min(int a, int b, int c) {
    int min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

int findLargestSquare(int matrix[][MAX_SIZE], int size) {
    int maxSquareSize = 0;
    int dp[MAX_SIZE][MAX_SIZE] = {0}; // Matriz de programación dinámica para almacenar los tamaños de los cuadrados

    // Rellenar la primera fila y la primera columna de la matriz dp
    for (int i = 0; i < size; i++) {
        dp[i][0] = matrix[i][0];
        dp[0][i] = matrix[0][i];
        if (matrix[i][0] == 1) maxSquareSize = 1;
        if (matrix[0][i] == 1) maxSquareSize = 1;
    }

    // Calcular el tamaño de los cuadrados en las posiciones restantes
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                if (dp[i][j] > maxSquareSize) maxSquareSize = dp[i][j];
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
    printf("El tamaño del cuadrado más grande de unos es: %dx%d\n", largestSquareSize, largestSquareSize);

    return 0;
}
