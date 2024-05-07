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
  // Pedir al usuario el numero
  printf("Ingrese el numero que desea calcular el factorial: ");
  scanf("%d", &num);

  // Verificar si la entrada es un numero entero positivo
  if (num < 0){
    printf("Error: El dato que ingreso no permite calcular su factorial, favor ingrese un numero valido.\n");
    return 1;

  }


 // Calcular el factorial y mostrar su resultado
  int fac = factorial(num);
  if (fac == 0);
     printf("EL numero es muy grande para calcularlo");
     return 0;
  if (fac > 0);
     printf("%d! = %d\n",num,fac);

    return 0;
}

