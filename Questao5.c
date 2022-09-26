#include<stdio.h>
#define MAX 5000

struct Secretaria_de_Transportes{
    char proprietario[25];
    int combustivel;
    char modelo[25];
    char cor[25];
	char chassi[25];
	int ano;
	char placa[18];	
  
};
typedef struct Secretaria_de_Transportes Veiculos;

Veiculos cadastrar();
void exibir(Veiculos vet[],int qtde);
void Proprietario(Veiculos vet[],int qtde);
void Placa(Veiculos vet[],int qtde);



int main (){
	
	Veiculos a[MAX];
	int i=0,op;
	
	do{
		printf("============== MENU ==============\n");
		printf("1 - Cadastrar: \n");
		printf("2 - Exibir todos Cadastros:\n");
		printf("3 - Exibir proprietarios carros a Diesel:\n");
		printf("4 - Exibir Placa:\n");
		printf("5 - Sair\n");
		scanf("%i",&op);
		
		switch(op){
			case 1:
					if(i<MAX){
						a[i] = cadastrar();
						i++;
					}else
						printf("Nao ha Mais espaco!\n");
					break;
			case 2:
				if(i!=0)
					exibir(a,i); //A = vetor i= Quatidade de elementos armazenados
				else
					printf("Nao ha dados armazenados!\n");
				break;
			case 3:
				if(i!=0)
					Proprietario(a,i); //A = vetor i= Quatidade de elementos armazenados
				else
					printf("Nao ha dados armazenados!\n");
				break;
			case 4:
				if(i!=0)
					Placa(a,i); //A = vetor i= Quatidade de elementos armazenados
				else
					printf("Nao ha dados armazenados!\n");
				break;
			case 5:
				exit(1);
				break;
		}
		system("pause");
        system("cls");
	}while(1);
	
	return 0;
}

Veiculos cadastrar(){
	Veiculos al;
	printf("Digite o Nome do Proprietario:\n");
	fflush(stdin);
	gets(al.proprietario);
	printf("Digite o Tipo de Combustivel [1] = Alcool [2] = Diesel [3] = Gasolina:\n");
	scanf("%i",&al.combustivel);
	printf("Digite o Modelo do Veiculo:\n");
	fflush(stdin);
	gets(al.modelo);
	printf("Digite o Cor do Veiculo:\n");
	fflush(stdin);
	gets(al.cor);
	printf("Digite o Numero do Chassi do Veiculo:\n");
	fflush(stdin);
	gets(al.chassi);
	printf("Digite o Ano do Veiculo:\n");
	scanf("%i",&al.ano);
	printf("Digite a Placa do Veiculo:\n");
	fflush(stdin);
	gets(al.placa);
	
	return al;	
	 
}

void exibir(Veiculos vet[],int qtde){
	int i;
	for(i=0;i<qtde;i++){
		printf("Nome do Proprietario: %s\n",vet[i].proprietario);
		if(vet[i].combustivel == 1)
            printf("Combustivel: Alcool\n");
        else if(vet[i].combustivel == 2)
            printf("Combustivel: Diesel\n");
            else if(vet[i].combustivel == 3)
			printf("Combustivel: Gasolina\n");
			else
            printf("Combustivel Invalido\n");
		printf("Modelo do Veiculo: %s\n",vet[i].modelo);
		printf("Cor do Veiculo: %s\n",vet[i].cor);
		printf("Numero do Chassi: %s\n",vet[i].chassi);
		printf("Ano do Veiculo: %i\n",vet[i].ano);
		printf("Placa do Veiculo: %s\n\n",vet[i].placa);
		
	}
}
void Proprietario(Veiculos vet[],int qtde){
	int i;
	for(i=0;i<qtde;i++){
		if(vet[i].combustivel == 2 && vet[i].ano >= 2010)
            printf("Nome: %s\n",vet[i].proprietario);	
	}
}
