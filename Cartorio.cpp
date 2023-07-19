#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��o de texto por regiao
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	 
	strcpy(arquivo, cpf); //Resposn�vel por copiar os valores das strings
	
	FILE *file;
	file = fopen(arquivo,"w");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);	
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
	
	
	//printf("Voc� escolheu o regitsro de nomes\n");
	//system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); 
	
	char cpf[40];
	char conteudo [200];
	
	printf("\nDigite o CPF a ser consultado: \n");
	scanf("%s" , cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o encontrado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)	
	{
		printf("\nEssas s�o as infroma��es encontradas: ");
		printf("%s", conteudo);
		printf("\n\n");	
		fclose (file);		
	}		
	
	system("pause");		
			
}	

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	{
		
		printf("O usu�rio n�o econtrado!\n");
		system("pause");
	}
	
}


int main()
{
	int opcao=0; //Definindo variaveis
	int laco=1;	
	
	for(laco=1;laco=1;)	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); 
	
		printf("\tBem-vindo!\n\n\n");
		printf("Escolha a op�ao desejada no menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("\tOp��o: ");
	
		scanf("%d", &opcao);
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)		
		
		{			
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigada por utilizar o sistema\n");
			return 0;
			break;
					
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;		
			
		}
	
	}
}
