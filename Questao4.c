#include<stdio.h>

struct NomeDieta{
    char nomeComida[25];
    float pecoPorcao;
    float calorias;
    
    
};typedef struct NomeDieta Dieta;        

struct lista{
    Dieta info;
    struct lista *prox;
    
};typedef struct lista Lista;

void exibir(Lista *l){
    Lista *p;
    for(p=l;p!=NULL;p=p->prox){
        printf("\nNome da Comida: %s \n", p->info.nomeComida);
        printf("Peso da Porcao: %.2f gramas \n", p->info.pecoPorcao);
        printf("Quantidade de calorias: %.2f cal\n", p->info.calorias);
	}
}
Dieta cadastrar(){
    Dieta  al ;
    
    printf("Digite o Nome da Comida:\n ");
    fflush(stdin);
    gets(al.nomeComida);
    
    printf("Digite o Peco da Porcao:\n ");
    scanf("%f",&al.pecoPorcao);
    
    printf("Digite a quantidade de calorias:\n ");
    scanf("%f",&al.calorias);
    
 return al;       
}  
Lista *inserir(Lista *l, Dieta a){
    Lista *novo=(Lista *) malloc(sizeof(Lista));
    novo->info=a;
    novo->prox=l;
    return novo;
}
main() {
    int op;
    Dieta cad;
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
