#include<stdio.h>


struct restaurantes{
    char nome[25];
    char endereco[25];
    char tipo[25];
    float precoMedio;
    
};typedef struct restaurantes Restaurantes;      

struct lista{
    Restaurantes info;
    struct lista *prox;
    
};typedef struct lista Lista;

void exibir(Lista *l){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        printf("\nNome: %s \n", p->info.nome);
        printf("Endereco: %s \n", p->info.endereco);
        printf("Tipo: %s \n", p->info.tipo);
        printf("Preco Medio: %.2f \n", p->info.precoMedio);
}
}
Restaurantes cadastrar(){
    Restaurantes  al ;
    
    printf("Digite o Nome:\n ");
    fflush(stdin);
    gets(al.nome);
    
    printf("Digite o Endereco:\n ");
    fflush(stdin);
    gets(al.endereco);
    
    printf("Digite o Preco Medio:\n ");
    scanf("%f",&al.precoMedio);
    
    printf("Digite o Tipo:\n ");
    fflush(stdin);
    gets(al.tipo);
    
 return al;       
}  
Lista *inserir(Lista *l, Restaurantes a){
    Lista *novo=(Lista *) malloc(sizeof(Lista));
    novo->info=a;
    novo->prox=l;
    return novo;
}
main() {
    int op;
    Restaurantes cad;
    Lista *l;
    l=NULL;
    do{
        puts("Menu:");
        puts("1 - Cadastrar:");
        puts("2 - Exibir todos os Cadastros:");
        puts("3 - Sair:");
        scanf("%i", &op);
        switch(op){
            case 1:
                cad=cadastrar();
                l=inserir(l, cad);
                break;
            case 2:
                if(l!=NULL){
                exibir (l);
                }else{
                    puts("Nao ha dados cadastrados!");
                }
                break;
            case 3:
                exit(1);
        }
        system("pause");
        system("cls");
    }while(1);
    
}
