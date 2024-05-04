#include <stdio.h>


// Funcion para crear el factorial

int factorial(int n) {
    int i = 1;
    while (n > 1) {
        i *= n;
        n--;
    }
    return i;
}




int main() {
  int num;
  printf("Ingrese el numero que desea calcular el factorial: ");
  scanf("%d", &num);

  int fac = factorial(num);
  printf("%d! = %d\n",num,fac);

    return 0;
}
