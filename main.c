#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// CHAMANDO FUNÇÕES //
int genPass();
int interac();
int callNext();
int seeAll(short x);
short calcFunc(short x);
short ordFunc(short y);
short listDisplay(short z);
//======================//


// ESTRUTURAS //
struct person {
  char nome[80];
  int prior;
};
struct person*pessoas = NULL;
int qtd=0;
//===========================//


// VARIAVEIS GLOBAIS //
/*short x=0;
short y=0;*/
//===================//


// FUNÇÕES DE ORDERNAÇÃO //

/* Ordenar menor */
short ordFunc(short y)
{
  short var=y;
  if(y<qtd-1)
  {
    strcpy(pessoas[qtd-1].nome, pessoas[y].nome);
    pessoas[qtd-1].prior=pessoas[y].prior;
    strcpy(pessoas[y].nome, pessoas[y+1].nome);
    pessoas[y].prior=pessoas[y+1].prior;
    return ordFunc(y+1);
  }
  else
{
    return calcFunc(0);
  }
}

/* Ordernar maior */
short calcFunc(short x)
{
  short var=0;
  if(x<qtd-1)
  {
    if (pessoas[0].prior == pessoas[x].prior)
    {
      if(pessoas[x].prior == 1)
      {
        return calcFunc(x+1);
      }else{
       return ordFunc(0);
      }
    }
      return seeAll(x);
  }else {
    return seeAll(x);
  }
}

/* Mostrar Fila */ 
short listDisplay(short z)
{
  if(z<qtd)
  {
    if(z==0)
    {
      puts("Fila");
      printf("# => ");
    }
    printf("%s, ", pessoas[z].nome);
    z++;
    return listDisplay(z+1);
  }else
{
    return interac();
  }
}
//=======================================//


// FUNÇÕES DE AÇÕES //

/* Mostra Fila */
int seeAll(short x)
{
  short z=0;
  if(x!=0)
  {
    return listDisplay(z);
  }else return calcFunc(0);
  return 0;
}

/* Chama o Proximo */
int callNext()
{
}

/* Gera Senha */
int genPass()
{
  char nome[80]; 
  int prior;
  printf("Nome:");
  scanf("%79s",nome);
  printf("Prioridade:");
  scanf("%d",&prior);
  qtd++;
  pessoas = realloc(pessoas, qtd * sizeof(struct person));
  strcpy(pessoas[qtd-1].nome, nome);
  pessoas[qtd-1].prior=prior;

  printf("%s\n", pessoas[qtd-1].nome);
  interac();
}

/* Menu Interativo*/
int interac()
{
  short option;

  puts("\n1: Gerar Senha\n2: Chamar Proximo\n3: Ver Fila\n4:Sair\n");
  scanf("%hi",&option);

  switch (option) {
    case 1:
      genPass();
      break;
    case 2:
      callNext();
      break;
    case 3:
      seeAll(0);
      break;
    case 4:
      return 2;
    default:
      interac();
  }

}
//============================================//


// MAIN //
int main()
{
  interac();
  return 0;
}
//==========//
// FIM //
