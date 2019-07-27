#include <stdio.h>
#include <stdlib.h>

struct lista
{
    int valor;
    struct lista* proximo;
};
typedef struct lista Lista;

Lista* cria_lista()
{
    return NULL;
}

int lista_vazia(Lista* l)
{
    return(l==NULL);
}

Lista* insere_inicio(Lista* l, int v)
{
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = v;
    novo->proximo = l;
    return novo;
}

Lista* insere_ordenado(Lista*l, int v)
{
    Lista* aux;
    Lista* ant = NULL;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->valor = v;
    for(aux=l; aux!=NULL && aux->valor<v; aux= aux->proximo)
    {
        ant=aux;
    }
    if(ant == NULL)
    {
        novo->proximo = l;
        l=novo;
    }
    else
    {
        novo->proximo = ant->proximo;
        ant->proximo = novo;
    }
    return l;
}

Lista* remove_lista(Lista* l, int v)
{
    if(lista_vazia(l))
    {
        printf("LISTA VAZIA\n");
        return l;
    }
    Lista* aux;
    Lista* ant = NULL;
    for(aux=l; aux!=NULL && aux->valor!=v; aux= aux->proximo)
    {
        ant=aux;
    }
    if(aux == NULL)
    {
        return l;
    }
    if(ant == NULL)
    {
        l->proximo = aux->proximo;
    }
    else
    {
        ant->proximo = aux->proximo;
    }
    free(aux);
    return l;
}

void imprime_lista(Lista* l)
{
    printf("\n");
    if(lista_vazia(l))
    {
        printf("LISTA VAZIA\n");
    }
    else
    {
        Lista* aux;


        for(aux=l; aux!=NULL; aux=aux->proximo)
        {
            printf("|%d|", aux->valor);
        }
        printf("\n");
    }
}

void imprime_menu()
{
    printf("____________MENU________________\n");
    printf("1 - Imprimir Lista\n");
    printf("2 - Inserir no inicio da lista\n");
    printf("3 - Inserir ordenado na lista\n");
    printf("4 - Remover da lista\n");
    printf("5 - Sair do programa\n");
    printf("_________________________________\n");
    printf("Informe a opcao desejada: ");
}


int main()
{
    Lista* l;
    l=cria_lista();
    int v = 0;
    int opcao = 0;
    while(opcao!=5)
    {
        imprime_menu();
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            imprime_lista(l);
            break;
        case 2:
            printf("Informe valor a ser inserido: ");
            scanf("%d", &v);
            l=insere_inicio(l,v);
            break;
        case 3:
            printf("Informe valor a ser inserido: ");
            scanf("%d", &v);
            l=insere_ordenado(l,v);
            break;
        case 4:
            printf("Informe valor a ser retirado: ");
            scanf("%d", &v);
            l=remove_lista(l,v);
            break;
        case 5:
            return 0;
            break;
        }
    }
}
