
#include <stdio.h>

int main()
{
   int vetor[10] = {44, 25, 96, 12, 45, 76, 9, 89, 10, 5}; 
   int valorProcurado = 10;
   
   for (int i = 0; i < sizeof(vetor); i++)
       if(vetor[i] == valorProcurado){
           printf("O valor %d está na posição %d\n", valorProcurado, i);
           break;
       }
       else{
           printf("Valor não encontrado no vetor\n");
           break;
       }
}