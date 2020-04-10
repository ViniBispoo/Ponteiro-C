#include <stdio.h>
#include <stdlib.h>

struct lista{
    int *itens;
    int quantidade, tamanho;
};

typedef struct lista Lista;

void criaLista(int tamanho,Lista *list){
    list->itens =(int*) malloc(tamanho*sizeof(int));
    list->quantidade = 0;
    list->tamanho=tamanho;
}

void mostra(Lista *list){
    for(int i = 0; i<list->quantidade; i++){
        printf("%d\n", list->itens[i]);
    }
}

int inserir(int val, Lista *l){

    if(l->quantidade ==0){
        l->itens[0] = val;
        l->quantidade++;
        return 0;
    }
    for(int i = 0; i<l->quantidade; i++){
        if(l->itens[i] == val){
            return 1;
        }

        if(l->itens[i]>val){
            for(int j = l->quantidade; j>i; j--){
                l->itens[j] = l->itens[j-1];
            }
            l->itens[i] = val;
            l->quantidade++;
            return 0;
        }
    }
    l->itens[l->quantidade] = val;
    l->quantidade++;
    return 0;
}

int deletar(int val, Lista *l){
    for(int i = 0; i<l->quantidade; i++){
        if(l->itens[i] == val){
            for(int j=i;j<l->quantidade-1;j++){
                l->itens[j]=l->itens[j+1];
            }
            l->quantidade --;
            return 0;
        }
    }
    return 1;

}

int main(void){
    Lista l;
    int tam,n;
    char oper;

    scanf("%d",&tam);
    if(tam > 30000 || tam <= 0){
        return 0;
    }
    criaLista(tam,&l);

    for(int i = 0 ; i < tam ; i++){
        scanf("\n%c %d",&oper,&n);
        if(oper =='I'){
            inserir(n,&l);
        }
        if(oper=='E'){
            deletar(n,&l);
        }
    }
    mostra(&l);
}
