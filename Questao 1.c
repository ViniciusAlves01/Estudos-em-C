#include<stdio.h>
struct produto{
	int codigo;
	char nomeProduto[25];
	int baixa[4][6];
	float preco;
};
typedef struct produto Prod;

struct lista{
	Prod info;
	struct lista *prox;
};
typedef struct lista Lista;

Prod cadastrar(){
	Prod x;
	int i, j;
	printf("Codigo:\n");
	scanf("%d", &x.codigo);
	printf("Nome produto:\n");
	fflush(stdin);
	gets(x.nomeProduto);
	printf("Valor: \n");
	scanf("%f", &x.preco);
	printf("Baixas do produto:\n");
	for(i=0;i<4;i++){
		printf("Semana: %d\n", i+1);
		for(j=0;j<6;j++){
			printf("Dia: %d\n", j+1);
			scanf("%d", &x.baixa[i][j]);
		}
	}
	return x;
}

Lista *inserir(Lista *l, Prod a){
	Lista *novo;
	novo = (Lista *)malloc(sizeof(Lista));
	novo->info = a;
	novo->prox = l;
	return novo;
}

void exibir(Lista *l){
	Lista *i;
	int x, y;
	for(i=l;i!=NULL;i = i->prox){
		printf("Codigo: %i\n", i->info.codigo);
		printf("Nome: %s\n", i->info.nomeProduto);
		printf("Preco: %.2f\n", i->info.preco);
		printf("Baixas: \n");
		for(x=0;x<4;x++){
			printf("\n");
			for(y=0;y<6;y++){
				printf("%3d ",i->info.baixa[x][y]);
			}
		}
		printf("\n");
	}
}


int baixasTotal(Lista *l){
	Lista *i;
	int x, y, total=0;
	for(i=l;i!=NULL;i = i->prox){
		printf("Nome: %s\n", i->info.nomeProduto);
		for(x=0;x<4;x++){
			total = total + i->info.baixa[x];
				for(y=0;y<6;y++){
					total = total + i->info.baixa[y];
					printf("Baixa total: %3d \n", total);
				}
	}
	return total;
}


main(){
	Lista *l;
	l=NULL;
	int op;
	do{
		puts("Escolha uma opcao:\n\n");
		puts("1 - Cadastrar");
		puts("2 - Exibir");
		scanf("%i", &op);
		switch(op){
			case 1:
				l = inserir(l,cadastrar());
				break;
			case 2:
				if(l!=NULL){
					exibir(l);
				}
				break;
		}
	}while(1);
}
