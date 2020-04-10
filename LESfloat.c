#include <stdio.h>
#include <stdlib.h>

struct lista{
    float *itens;
    int quantidade, tamanho;
};

typedef struct lista Lista;


void criaLista(Lista *list, int tamanho){
    list->itens =(int*) malloc(tamanho*sizeof(int));
    list->quantidade = 0;
    list->tamanho = tamanho;
}

void adiciona(Lista *l,float n){
    if(l->quantidade == 0){
        l->itens[0]=n;
        l->quantidade++;
        return;
    }

    for(int i = 0; i<l->quantidade; i++){
        if(n<l->itens[i]){
            for(int j = l->quantidade; j>i;j--){
                l->itens[j] = l->itens[j-1];
            }
            l->itens[i] = n;
            l->quantidade ++;
            return;
        }
    }
    l->itens[l->quantidade] = n;
    l->quantidade ++;
}

void remover(Lista *list, float num){
    for(int i = 0; i<list->quantidade; i++){
        if(list->itens[i] == num){
            for(int j = i; j < list-> quantidade; j++){
                list->itens[j] = list->itens[j+1];
            }
            list->quantidade --;
        }
    }
}

void mostra(Lista *l){
    for(int i = 0 ; i<l->quantidade; i++){
        printf("%.1f ",l->itens[i]);
    }
    printf("\n");
}

void busca(Lista *l,float n){
    for(int i = 0 ; i<l->quantidade; i++){
        if(n == l->itens[i]){
            printf("SIM\n");
            return;
        }
    }
    printf("NAO\n");
}

int main(void){
    Lista l;
    float n;
    char oper;
    int tam;

    scanf("%d", &tam);

    if(tam > 30000 || tam <= 0){
        return 0;
    }

    criaLista(&l,tam);

    while(tam == tam){
        scanf("\n%c",&oper);
        if(oper =='I'){
            scanf("%f",&n);
            adiciona(&l,n);
        }

        if(oper=='R'){
            scanf("%f",&n);
            remover(&l,n);
        }

        if(oper=='M'){
            mostra(&l);
        }

        if(oper=='B'){
            scanf("%f",&n);
            busca(&l,n);
        }

    }
}

