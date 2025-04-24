#include <stdio.h>

int metodo(int x) {
    for (int i = 0; i < 100; i++) {
        if (x == i) {
            return x;
        }
    }
    return -1;
}

int main() {
    int resultado = metodo(42);
    printf("Resultado: %d\n", resultado);
    return 0;
}