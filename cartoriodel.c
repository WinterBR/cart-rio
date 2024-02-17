#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca da string

int registro()  //função de registrar nomes 
{	
    setlocale(LC_ALL, "Portuguese");   //Lingua definida como português
    
    //variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser a ser cadastrado: ");
	scanf("%s", cpf); //"%s" para strings
	
	FILE *verifica;                   //função verifica: verifica se existe algum cpf igual
    verifica = fopen(cpf, "r");
    
    if (verifica != NULL) 
	{
        printf("CPF: %s já cadastrado, tente novamente.\n", cpf);
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

int consulta()  //função consulta
{
	setlocale(LC_ALL, "Portuguese");   //Lingua definida como português
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); //"r" para ler
	
	if(file == NULL) //se não tiver o número exato sera nulo
	{
		printf("Não foi possivel encontrar um usuário com esse cpf.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto as informações dadas a pasta conteudo (com limite de 200 caractéres), que estão dentro do arquivo forem diferente de nulo
	{
		printf("\nEssas são as informações do usuário:\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");

}

int deletar() //função deletar
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
		printf("Usuário com CPF: %s foi excluido com sucesso!\n", cpf);	
	}	
	
	else  //caso ele não exista
	{
		printf("Usuário de CPF: %s não se encontra no sistema.\n", cpf);
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
	
        setlocale(LC_ALL, "Portuguese");   //Lingua definida como português
	    printf("\t---Cartório EBAC---\n\n");   //Título
	    printf("Escolha a opção desejada do menu\n\n"); //Opções para usuário escolher
	    printf("\t1-Registar nomes\n"); //op1
	    printf("\t2-Consultar nomes\n"); //op2
	    printf("\t3-Excluir nomes\n\n"); //op3
	    printf("\t4-Sair do sistema\n\n\n");
	
	    printf("opção: ");
	
	    scanf("%d", &opcao); //"input"
	
	    system("cls"); //limpar
	    
	    switch(opcao)  //respostas
	    {
	    	case 1:
				registro(); //chamar a função registro
				break;
				
			case 2:
				consulta(); //chamar a função consulta
		    	break;
		    	
		    case 3:
		    	deletar(); //chamar a função deletar
		    	break;
		    	
		    case 4:
		    	printf("\tObrigado por ultilizar o sistema\n");
		    	return 0;
		   		break;

		    default: // caso não seja nenhum dos 3
		    	printf("Essa opção não está disponivel\n");
		    	system("pause");
		    	break;
	    		
		}

    } 
	
}
