#include <stdio.h>
#include <stdlib.h>

struct lista{
    char *itens;
    int quantidade, tamanho;
};

typedef struct lista Lista;

int main(void){
    int tam;
    Lista l;
    char oper,n;

    scanf("%d",&tam);

    criaLista(&l,tam);

    while(scanf("\n%c %c",&oper,&n)!=EOF){
        if(oper == 'I'){
            insere(&l,n);
        }
        if(oper =='M'){
            mostra(&l);
        }
    }
}

void criaLista(Lista *list, char n){
    list->tamanho = n;
    list->itens = (int*) malloc(n * sizeof(int));
    list->quantidade = 0;
}

void insere(Lista *list, char val){
    if(list->quantidade == 0){
        list->itens[0] == val;
    }

    for(int i=0; i<list->quantidade; i++){
        if(val>list->itens[i]){
            for(int j = list->quantidade; j<i ; j--){
                list->itens[j] = list->itens[j-1];
            }
            list->itens[i] = val;
            list->quantidade++;
            return ;
        }
    }
}

void mostra(Lista *list){
    for(int i = 0; i< list->tamanho; i++ ){
        printf("%c ",list->itens[i]);
    }
}
