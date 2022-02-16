#include <stdio.h>
#include <stdlib.h>

struct no
{
	int numero;
	struct no *direita;
	struct no *esquerda; 
};
typedef struct no NO;

NO* criar(int numero)
{
	NO *raiz = (NO*)malloc(sizeof(NO));
	raiz->numero = numero;
	raiz->esquerda = NULL;
	raiz->direita = NULL;
	return raiz;
} 

void adicionar(NO *raiz, int valor)
{
	if(valor < raiz->numero)
	{
		if(raiz->esquerda == NULL)
			raiz->esquerda = criar(valor);
		else
			adicionar(raiz->esquerda, valor);
	}
	else
	{
		if(raiz->direita == NULL)
			raiz->direita = criar(valor);
		else
			adicionar(raiz->direita, valor);
	}
}

void imprimir(NO *raiz)
 {
	 if(raiz != NULL)
	 {
		 imprimir(raiz->esquerda);
		 printf("%d", raiz->numero);
		 imprimir(raiz->direita);
	 }
 }

 int alturaArvore(NO *raiz)
 {
     if(raiz == NULL)
	 {
		 return -1;
	 }
	 else
	 {
		 int esquerda = alturaArvore(raiz->esquerda);
		 int direita = alturaArvore(raiz->direita);
         if(esquerda > direita)
		    return esquerda + 1;
		else
		    return direita + 1;
	 }
 }

 int numeroDeNos(NO *raiz)
 {
	 if(raiz == NULL)
	 {
		 return 0;
	 }
	 else
	 {
		 return 1 + numeroDeNos(raiz->esquerda) + numeroDeNos(raiz->direita); 
	 }
 }

 int maiorNumero(NO *raiz)
 {
	 if(raiz->direita != NULL)
	 {
		maiorNumero(raiz->direita);
	 }
	 else if(raiz->direita == NULL)
	 {
		return raiz->numero;
	 }
 }

int main() {
    
	NO *raiz = NULL;
	
	raiz = criar(50);
  adicionar(raiz, 60);
  adicionar(raiz, 80);
  adicionar(raiz, 90);
  adicionar(raiz, 30);
  adicionar(raiz, 40);
  

  imprimir(raiz);

  printf("\nAltura da Arvore: %d", alturaArvore(raiz));

  printf("\nNumero de Nos da Arvore: %d", numeroDeNos(raiz));

  printf("\nMaior Numero da Arvore: %d", maiorNumero(raiz));

  return 0;
}