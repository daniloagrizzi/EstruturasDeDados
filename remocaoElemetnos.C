
 #include <stdio.h>

void removerVariosValoresIguais(int vetor[], int *tamanho, int valorParaRemover){
    
    int i = 0;
    
     while (i < *tamanho){
         
        if (vetor[i] == valorParaRemover){
           for (int j = i; j <= *tamanho -1; j++){
               vetor[j] = vetor[j + 1];
           } 
       (*tamanho)--;
        printf("Valor %d removido com sucesso!\n", valorParaRemover);
        }
        
     else {
            i++;
        }
    }
    printf("Processo de remoção finalizado. Tamanho atual do vetor: %d\n", *tamanho);
}
    

int main() {
    int vetor[] = {0, 0, 1, 1, 1, 2, 2, 3, 0, 3};
    int valor = 1;
    int tamanho = 10;

    removerVariosValoresIguais(vetor, &tamanho, valor);
    

    return 0;
}
