#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>//biblioteca de aloca��o de texto por regi�o
#include <string.h>//biblioteca responsavel por cuidar das string

int registro()//fun��o responsavel por cadastra os usuarios no sistema
{
	//inicio criacao de variavel
	char arquivo [40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de craicao de variavel
	
	printf("Digite o CPF: ");
	scanf("%s", cpf);//$s responsavel por salvar uma string
	
	strcpy(arquivo,cpf); //responsavel por copiar os valores das strings
	
	FILE *file;//cria o arquivo
	file = fopen(arquivo,"w");//cria o arquivo
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza com uma virgula
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza com o nome 
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");	
	
}
int consulta()
{
	setlocale (LC_ALL, "Portuguese"); //definindo idioma
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf ("n�o foi possivel abrir o arquivo");
	}

	while (fgets(conteudo,200, file)!= NULL)
	{
		printf ("\nEssas s�o as informa��es do usu�rio: ");
		printf ("%s", conteudo);
		printf("\n\n");
	}
	system ("pause");
}
int deletar()
{
	char cpf[40];
	
	printf("Digitar o CPF a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("O usuario n�o se encontra no sistema! \n");
		system("pause");
	}
		
}
		
		
		

int main()
{
 	int opcao=0;//definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n ");
	printf("Login Administrador\n\nDigite a sua senha:  ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada,"admin");
	
	if(comparacao == 0)
	{
	
		for(laco=1;laco=1;)
		{
			system("cls");
		
			setlocale (LC_ALL, "Portuguese"); //definindo idioma
	
			printf("### Cart�rio da EBAC ###\n\n ");//tela inicial
			printf("Escolha a op��o desejada\n\n");//tela inicial
			printf("\t1 - Registrar Nomes\n");//tela inicial
			printf("\t2 - Consultar Nomes\n");//tela inicial
			printf("\t3 - Deletar Nomes\n");//tela inicial
			printf("\t4 - Sair do programa\n");//tela inicial
	
			scanf("%d",&opcao);//entrada do usuario
	
			system("cls;");//limpa tela
		
			switch(opcao)//testagem switch case
			{
				case 1:
				registro();
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigador por utilizar o sistema.\n");
				exit(0);
				break;
			
				default:
				printf("Essa op��o n�o est� disponivel!\n");
				system("pause");
				break;		
			}
		} 
	}
	else	
	 	printf("Senha incorreta\n");		
	} 

 
