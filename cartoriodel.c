#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��es de texto por regi�o
#include <string.h> //Biblioteca da string

int registro()  //fun��o de registrar nomes 
{	
    setlocale(LC_ALL, "Portuguese");   //Lingua definida como portugu�s
    
    //vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser a ser cadastrado: ");
	scanf("%s", cpf); //"%s" para strings
	
	FILE *verifica;                   //fun��o verifica: verifica se existe algum cpf igual
    verifica = fopen(cpf, "r");
    
    if (verifica != NULL) 
	{
        printf("CPF: %s j� cadastrado, tente novamente.\n", cpf);
        fclose(verifica); // Fecha o arquivo
        system("pause");
        return; //retorna para o main
    }
    
    fclose(verifica); // Fecha o arquivo
	
	strcpy(arquivo, cpf); //copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //"w" para arquivo novo, abrindo o arquivo
	fprintf(file,cpf); //integrar o valor do cpf ao aquivo
	fclose(file); //fechar o arquivo
	
	file = fopen(arquivo, "a"); //"a" para atualizar o aqrquivo
	fprintf(file, ","); //adicionar "," no fim
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo , "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause"); //"}"
	
}

int consulta()  //fun��o consulta
{
	setlocale(LC_ALL, "Portuguese");   //Lingua definida como portugu�s
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" para ler
	
	if(file == NULL) //se n�o tiver o n�mero exato sera nulo
	{
		printf("N�o foi possivel encontrar um usu�rio com esse cpf.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto as informa��es dadas a pasta conteudo (com limite de 200 caract�res), que est�o dentro do arquivo forem diferente de nulo
	{
		printf("\nEssas s�o as informa��es do usu�rio:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar() //fun��o deletar
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file != NULL)  //caso o CPF exista
	{
		fclose(file);
		remove(cpf);
		printf("Usu�rio com CPF: %s foi excluido com sucesso!\n", cpf);	
	}	
	
	else  //caso ele n�o exista
	{
		printf("Usu�rio de CPF: %s n�o se encontra no sistema.\n", cpf);
	}
	remove(cpf);
	system("pause");
}

int main()
{
	int ctz=0;
	int opcao=0;    //variaveis
	int x=1;
	
	for(x=1;x=1;)  //reiniciar
	{
		system("cls");
	
        setlocale(LC_ALL, "Portuguese");   //Lingua definida como portugu�s
	    printf("\t---Cart�rio EBAC---\n\n");   //T�tulo
	    printf("Escolha a op��o desejada do menu\n\n"); //Op��es para usu�rio escolher
	    printf("\t1-Registar nomes\n"); //op1
	    printf("\t2-Consultar nomes\n"); //op2
	    printf("\t3-Excluir nomes\n\n"); //op3
	    printf("\t4-Sair do sistema\n\n\n");
	
	    printf("op��o: ");
	
	    scanf("%d", &opcao); //"input"
	
	    system("cls"); //limpar
	    
	    switch(opcao)  //respostas
	    {
	    	case 1:
				registro(); //chamar a fun��o registro
				break;
				
			case 2:
				consulta(); //chamar a fun��o consulta
		    	break;
		    	
		    case 3:
		    	deletar(); //chamar a fun��o deletar
		    	break;
		    	
		    case 4:
		    	printf("\tObrigado por ultilizar o sistema\n");
		    	return 0;
		   		break;

		    default: // caso n�o seja nenhum dos 3
		    	printf("Essa op��o n�o est� disponivel\n");
		    	system("pause");
		    	break;
	    		
		}

    } 
	
}
