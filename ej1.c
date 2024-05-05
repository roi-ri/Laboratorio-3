#include <stdio.h>

// Funcion para generar el numero triangular
int triangleNumber(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int n;
    printf("Los primeros 100 numeros triangulares son:\n");
    for (n = 0; n <= 100; n++) {
        printf("%d\n", triangleNumber(n));
    }
    return 0;
}
