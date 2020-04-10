#include <stdio.h>
#include <stdlib.h>

struct Node{
    int numero;
    struct Node*prox;
};

typedef struct Node node;

void deleta(node **Node,int val){
    node *no = *Node;
    node *passado = malloc(sizeof(node));
    if(no->numero == val){
        no=no->prox;
        return;
    }
    while (no->numero != val){
        if(no->prox==NULL){
            printf("Nao existe esse numero\n");
            return;
        }
        passado = no;
        no = no->prox;
    }
    passado->prox = no -> prox;

}

void insert(node **Node,int val){
    node *temp = malloc(sizeof(node));
    node *passado = malloc(sizeof(node));
    temp->numero = val;
    node *lastnode =*Node;
    if(lastnode==NULL){
        temp->prox= NULL;
        *Node=temp;
        return;
    }
    if(lastnode->numero > val){
        temp->prox = lastnode;
        *Node=temp;
        return;
    }
    while(lastnode!= NULL && lastnode->numero <val){
        passado = lastnode;
        lastnode = lastnode->prox;
    }
    passado->prox = temp;
    temp->prox = lastnode;
    free(val);
}

void print(node *Node){
    while(Node!=NULL){
        printf("%d",Node->numero);
        printf("->");
        Node=Node->prox;
    }
    printf("NULL\n");

}


int main(void)
{
    node *no1 = NULL;
    char oper;
    int val;
    while(scanf("\n%c",&oper)!= EOF ){
        if(oper == 'A'){
            scanf("%d",&val);
            insert(&no1,val);
        }
        if(oper=='M'){
            print(no1);
        }
        if(oper=='D'){
            scanf("%d",&val);
            deleta(&no1,val);
        }
    }

    return 0;
}
