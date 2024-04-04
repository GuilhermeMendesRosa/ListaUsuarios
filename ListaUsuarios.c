#include <stdio.h>
#include <stdlib.h>

// Funções Auxiliares

void quebraLinha() {
  printf("-------------------------------------\n");
}

void mostraDesejaContinuar() {    
  quebraLinha();
  printf("Deseja continuar?\n");
  printf("1 - Sim\n");
  printf("2 - Não\n");
  printf("Opção:");
}

void mostraMenu() {    
  quebraLinha();
  printf("1 - Consultar\n");
  printf("2 - Editar\n");
  printf("3 - Listar \n");
  printf("4 - Finalizar Programa\n");
  printf("Opção:");
}

// Bloco Main

int main() {
  int opcaoMenu = -1;
  int posicao;
  int desejaContinuar;
  char nomes[100][30];
  int quantidadeNomes;

  printf("Digite até 100 nome:\n");

  for (int i = 0; i < 100; i++) {
    quebraLinha();
    printf("Nome: ");
    scanf("%s", nomes[i]);

    if (i < 99) {
      mostraDesejaContinuar();
      scanf("%d", &desejaContinuar);
    }

    quantidadeNomes = i + 1;

    if (desejaContinuar != 1) {
      break;
    }    
  }

  while(opcaoMenu != 4) {
    mostraMenu();

    scanf("%d", &opcaoMenu);

    switch(opcaoMenu) {
      case 1:
        posicao = 1;
        quebraLinha();

        printf("Qual posição deseja consultar? (1-%d)\n", quantidadeNomes);
        scanf( "%d", &posicao);

        if (posicao > quantidadeNomes) {
          printf("Posição inválida!\n");
        }

        printf("Nome: %s\n", nomes[posicao - 1]);

        break;
      case 2:
        posicao = 1;
        quebraLinha();

        printf("Qual posição deseja editar? (1-%d)\n", quantidadeNomes);
        scanf("%d", &posicao);

        if (posicao > quantidadeNomes) {
          printf("Posição inválida!\n");
        }

        printf("Nome Antigo: %s\n", nomes[posicao - 1]);
        printf("Nome Novo: ");
        scanf("%s", nomes[posicao - 1]);

        break;
      case 3:
        quebraLinha();
        for (int i = 0; i < quantidadeNomes; i++) {
          printf( "Nome %d: %s\n", i + 1, nomes[i]);
        }

        break;
    }
  }

  quebraLinha();
  printf("Programa Finalizado\n");  
  quebraLinha();

  return 1;
}
