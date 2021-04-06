#include <stdio.h>
#include <stdlib.h>

struct lista {
int info;
struct lista* prox;
};
typedef struct lista Lista;

Lista* lst_insere (Lista* l, int i) {
   Lista* novo = (Lista*) malloc(sizeof(Lista));
   novo->info = i;
   novo->prox = l;
   return novo;
}

Lista* retira_rec(Lista* L, int v)
 {
 if(L!=NULL){
   
   if(L->info==v){
      Lista* t=L;
      L=L->prox;
      free(t);
    }
  else{
    L->prox=retira_rec(L->prox,v);
  }
 }

return L;
}

//IMPRIMIR RECURSIVAMENTE
void lst_imprime (Lista* L)
{
  if(L!= NULL){
     printf("%d\n",L->info);
     lst_imprime(L->prox);
 }
}

//Função de busca
Lista* busca_rec (Lista* L, int v)
{
 Lista* p;
 for (p=L; p!=NULL; p = p->prox) {
 if (p->info == v)
 return p;
 }
 return NULL; // não achou o elemento 
}

Lista* ins_ultimo_cond (Lista* L, int v)
{
  Lista* p = L;
  Lista* novo = (Lista*)malloc(sizeof(Lista));
  //alocando os dados no novo elemento
  novo->info = v;
  novo->prox = NULL;
  //Se a lista estiver vazia
  if (p==NULL) return novo;
  //procurando a posição do elemento
  while (p->prox!=NULL){
    if(p->info == v || p->prox->info ==v) {
      return L;
    }
    p = p->prox;
  }
  p->prox = novo;
  return L;
}

Lista* lst_libera (Lista* l) {
   Lista* p = l;
   while (p != NULL) {
       Lista* t = p->prox; //guarda referencia para proximo elemento
       free(p); //libera a memória apontada por p 
       p = t;   
   }
   return NULL;
}

int main (void)
{
Lista* l; /* declara uma lista não iniciada */
l = NULL; /* inicia lista vazia */

/* vai inserir no início da lista */
l = lst_insere(l, 23); /* insere na lista o elemento 23 */
l = lst_insere(l, 45); /* insere na lista o elemento 45 */
l = lst_insere(l, 56); /* insere na lista o elemento 56 */
l = lst_insere(l, 78); /* insere na lista o elemento 78 */

//Função que imprime recursivamente as informações da lista
lst_imprime(l); /* imprimirá: 78 56 45 23 */
printf("\n");
printf("\n");

/*vai buscar, recursivamente, um ponteiro para o nó com a informação 45*/
Lista* k = busca_rec(l,45);
if(k!=NULL)printf("info = %d\n", k->info); //imprimirá info = 45
printf("\n");
printf("\n");

/*vai retirar, recursivamente, o elemento 78 */
l = retira_rec(l,78);
lst_imprime(l); /* imprimirá: 56 45 23 */
printf("\n");
printf("\n");


/*vai inserir, iterativamente, o elemento no final da lista de forma condicional.
 Caso ele ainda não exista, insere, no final, um nó com a informação enviada;
 caso já exista em algum nó da lista, simplesmente não insere e retorna o ponteiro inicial*/
l = ins_ultimo_cond(l,82);
printf("\n");
printf("\n");
lst_imprime(l); /* imprimirá: 56 45 23 82 */

l = ins_ultimo_cond(l,45);
printf("\n");
printf("\n");
lst_imprime(l); /* imprimirá: 56 45 23 82 */


/*vai liberar a lista l */ 
l = lst_libera(l);

return 0;
}
