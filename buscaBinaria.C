
#include <stdio.h>

int main() {
    int vetor[10] = {5, 9, 10, 12, 25, 44, 45, 76, 89, 96}; 
    int valorProcurado = 10;
    int final = sizeof(vetor) / sizeof(vetor[0]) - 1;  // Último índice do vetor
    int inicio = 0;
    int centro;
    int i = 0;  
    
    do {
        centro = (inicio + final) / 2;
        i++; 
        
        if (vetor[centro] > valorProcurado) {
            final = centro - 1;
        } 
        else if (vetor[centro] < valorProcurado) {
            inicio = centro + 1;
        } 
        else {
            printf("O valor %d foi encontrado após %d iterações\n", valorProcurado, i);
            break;
        }
        
    } while (inicio <= final);
    
    if (inicio > final) {
        printf("O valor %d não foi encontrado no vetor\n", valorProcurado);
    }

    return 0;
}