#include<stdio.h>
#include<stdbool.h>
#define MAX 500

struct aluno{
	int matricula;
    char nome[25];
    int serie;
    char turma;
    char sexo;
    int anoNascimento;
    char naturalidade[25];
    float media;
    bool aprovado;
};
typedef struct aluno Aluno;

Aluno cadastrar();
void exibir(Aluno vet[],int qtde);
void porcentagem(Aluno vet[],int qtde);
void porcentagem_sexo(Aluno vet[],int qtde);
void exibirIdade(Aluno vet[],int qtde);


int main (){
	
	Aluno a[MAX];
	int i=0,op;
	
	do{
		printf("============== MENU ==============\n");
		printf("1 - Cadastrar: \n");
		printf("2 - Exibir todos Cadastros:\n");
		printf("3 - Porcentagem Aprovados/Reprovados:\n");
		printf("4 - Porcentagem Masculino/Feminino:\n");
		printf("5 - Media das idades dos alunos:\n");
		printf("6 - Sair\n");
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
				porcentagem(a,i);
				else
				printf("Nao ha dados armazenados!\n");
				break;
			case 4:
				if(i!=0)
				porcentagem_sexo(a,i);
				else
				printf("Nao ha dados armazenados!\n");
				break;
			case 5:
				if(i!=0)
				exibirIdade(a,i);
				else
				printf("Nao ha dados armazenados!\n");
				break;
			case 6:
				exit(1);
				break;
		}
		system("pause");
        system("cls");
	}while(1);
	
	return 0;
}

Aluno cadastrar(){
	Aluno al;
	
	printf("Digite a matricula do aluno: \n");
	scanf("%i", &al.matricula);
	
	printf("Digite o nome do aluno:\n");
	fflush(stdin);
	gets(al.nome);
	
	printf("Digite a serie do aluno:\n");
	scanf("%i", &al.serie);
	
	printf("Digite  a turma do aluno:\n");
	al.turma = getche();
	
	printf("\nDigite o sexo do aluno:\n");
	al.sexo = getche();
	
	printf("\nDigite o ano de nascimento do aluno:\n");
	scanf("%i", &al.anoNascimento);
	
	printf("Digite a naturalidade do aluno:\n");
	fflush(stdin);
	gets(al.naturalidade);
	
	printf("Digite a media do aluno:\n");
	scanf("%f",&al.media);
	if(al.media >= 6.0){
		al.aprovado = true;
	}else{
		al.aprovado = false;
	}
	return al;	
	 
}

void exibir(Aluno vet[],int qtde){
	int i;
	for(i=0;i<qtde;i++){
		printf("\n\nMatricula: %i\n",vet[i].matricula);
		printf("Nome: %s\n",vet[i].nome);
		printf("Serie: %i\n",vet[i].serie);
		printf("Turma: %c\n",vet[i].turma);
		if((vet[i].sexo == 'M')||(vet[i].sexo == 'm'))
            printf("Sexo Masculino\n");
        else
            if((vet[i].sexo == 'F')||(vet[i].sexo == 'f'))
            printf("Sexo Feiminino\n");
            else
            printf("Sexo Inválido\n");
		printf("Ano de Nascimento: %i\n",vet[i].anoNascimento);
		printf("Naturalidade: %s\n",vet[i].naturalidade);
		printf("Media: %.2f\n",vet[i].media);
		if(vet[i].aprovado == true)
            printf("Aluno Aprovado\n");
        else
            printf("Aluno Reprovado\n\n");
        
	}
}

void porcentagem(Aluno vet[],int qtde){
	char turma;
	int serie;
	float porcAp,porcRp;
	int i, contAp=0,contRp=0,contTotal=0;
	
	printf("\nDigite a serie que deseja verificar:\n");
	scanf("%i",&serie);
	
	printf("Digite a turma que deseja verificar:\n");
	turma = getche();
	
	
	for(i=0;i<qtde;i++){
		if(vet[i].turma == turma && vet[i].serie == serie){
			if(vet[i].aprovado == true){
				contAp++;
			}else{
				contRp++;
			}
		}
	}
	contTotal = contAp+contRp;
	porcAp = (100.0 * contAp)/contTotal;
	porcRp = (100.0 * contRp)/contTotal;
	
	printf("\nPorcentagem de Aprovado: %.2f%%\n",porcAp);
	printf("Porcentagem de Aprovado: %.2f%%\n",porcRp);
	
}
void porcentagem_sexo(Aluno vet[],int qtde){
	char turma;
	int serie;
	float porcmasc,porcfem;
	int i, contmasc=0,contfem=0,contTotal=0;
	
	printf("\nDigite a serie que deseja verificar:\n");
	scanf("%i",&serie);
	
	printf("Digite a turma que deseja verificar:\n");
	turma = getche();
	
	
	for(i=0;i<qtde;i++){
		if(vet[i].turma == turma && vet[i].serie == serie){
			if(vet[i].sexo == 'M' || vet[i].sexo == 'm' ){
				contmasc++;
			}else
				if(vet[i].sexo == 'F' || vet[i].sexo == 'f' ){
				contfem++;
			}
		}
	}
	contTotal = contmasc+contfem;
	porcmasc = (100.0 * contmasc)/contTotal;
	porcfem = (100.0 * contfem)/contTotal;
	
	printf("Porcentagem de Aluno Sexo Masculino: %.2f%%\n",porcmasc);
	printf("Porcentagem de Aluno Sexo Feminino: %.2f%%\n",porcfem);
	
}
void exibirIdade(Aluno vet[],int qtde){
	int i,idade[MAX];
	float totalIdade;
	for(i=0;i<qtde;i++){
		printf("Ano de Nascimento: %i\n",vet[i].anoNascimento);
		idade[i] = 2022 - vet[i].anoNascimento ;  
		printf("Idade: %i\n", idade[i]);
		totalIdade = totalIdade + idade[i];
	}
	totalIdade = totalIdade / i;
	printf("Media das Idades dos Alunos e: %.1f\n",totalIdade);
	

}
