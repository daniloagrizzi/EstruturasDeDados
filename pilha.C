#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno
{ // Aqui estou criando a estrutura do aluno e renomeando
  // para poder chama-lo apenas como Aluno
  char nome[50];
  int idade;
  float nota;
  struct Aluno *proximo; // Este é um ponteiro para o próximo nó. Isso cria uma referência para outro nó.Cada nó contém um objeto do tipo Aluno e um ponteiro para o próximo nó da lista.
} Aluno;

// Todo ponteiro no nó aponta para para o nó que foi adicionado antes dele, ou seja, para o nó que está abaixo dele na pilha.

Aluno *top = NULL; // o topo e sempre apontado para uma posicao invalida do vetor, ou seja, NULL.

//  A pilha em si contém apenas um ponteiro para o topo da pilha, que aponta para o nó que está no topo.

// Push (inserir na pilha): Quando um novo elemento é adicionado à pilha, um novo nó é criado. Esse novo nó armazena os dados (informações do aluno) e seu ponteiro proximo passa a apontar para o nó que já estava no topo. O ponteiro da pilha que aponta para o topo é então atualizado para apontar para esse novo nó.

void push(Aluno aluno)
{
  printf("Inserindo aluno...\n");
  Aluno *novo = (Aluno *)malloc(sizeof(Aluno)); // Alocacao na memoria de um novo nó do tipo Aluno.
  strcpy(novo->nome, aluno.nome);
  novo->idade = aluno.idade;
  novo->nota = aluno.nota;
  novo->proximo = top; // agora o novo no aponta para o no que estava antes no topo da pilha.
  top = novo;          // agora o topo esta apontando para o novo no
}

void pop()
{
  if (top == NULL)
  {
    printf("A pilha está vazia\n");
  }
  else
  {
    Aluno *temp;        // criando uma celula temporaria
    temp = top;         // a celula temporaria aponta agora para onde o topo apontava
    top = top->proximo; // o topo agora aponta para o proximo elemento, ou seja, o elemento que estava abaixo do topo anterior
    printf("Removendo aluno\n");
    free(temp); // aqui a celula temporada e liberada da memoria usando o free
  }
}

void mostrarPilha()
{
  if (top == NULL)
  {
    printf("A pilha está vazia\n");
  }
  else
  {
    Aluno *temp = top;
    while (temp != NULL)
    {
      printf("Nome: %s\n", temp->nome);
      printf("Idade: %d\n", temp->idade);
      printf("Nota: %f\n", temp->nota);
      temp = temp->proximo; // aqui o ponteiro temp aponta para o proximo elemento da pilha, fazendo com que seu proximo loop imprima o elemento abaixo
    }
  }
}

void listTop()
{
  if (top == NULL)
  {
    printf("A pilha está vazia \n");
  }
  else
  {
    Aluno *temp = top;
    printf("Nome: %s\n", temp->nome);
    printf("Idade: %d\n", temp->idade);
    printf("Nota: %f\n", temp->nota);
  }
}

void inverterPilha()
{
  if (top == NULL)
  {
    printf("A pilha está vazia \n");
  }
  else
  {
    Aluno *tempStack = NULL;
    Aluno *temp = top;

    while (temp != NULL)
    {
      Aluno *novo = (Aluno *)malloc(sizeof(Aluno));
      strcpy(novo->nome, temp->nome);
      novo->idade = temp->idade;
      novo->nota = temp->nota;
      novo->proximo = tempStack;
      tempStack = novo;
      temp = temp->proximo;
    }

    top = tempStack;
  }
}

void exibirMenu()
{
  printf("\n1. Inserir aluno\n");
  printf("2. Remover aluno\n");
  printf("3. Mostrar alunos\n");
  printf("4. Mostrar primeiro aluno\n");
  printf("5. Inverter pilha\n");
  printf("6. Sair\n");
}

int main()
{
  int opcao;
  Aluno aluno;

  Aluno aluno1 = {"João", 20, 8.5};
  Aluno aluno2 = {"Maria", 22, 9.0};
  Aluno aluno3 = {"Pedro", 21, 7.5};

  push(aluno1);
  push(aluno2);
  push(aluno3);

  do
  {

    exibirMenu();
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);
    getchar();

    if (opcao == 1)
    {
      printf("Nome: ");
      fgets(aluno.nome, sizeof(aluno.nome), stdin);
      aluno.nome[strcspn(aluno.nome, "\n")];
      printf("Idade: ");
      scanf("%d", &aluno.idade);
      printf("Nota: ");
      scanf("%f", &aluno.nota);
      push(aluno);
    }
    else if (opcao == 2)
    {
      pop();
    }
    else if (opcao == 3)
    {
      mostrarPilha();
    }
    else if (opcao == 4)
    {
      listTop();
    }
    else if (opcao == 5)
    {
      inverterPilha();
    }
    else if (opcao != 6)
    {
      printf("Opção invalida\n");
    }
  } while (opcao != 6);

  printf("Saindo.\n");
  return 0;
}
