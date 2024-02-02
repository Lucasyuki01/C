//Lucas Mendes Musssato Fernandes RA: 211022195
//Lucas Yuki Nishimoto 			  RA: 211024678

#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>


struct cliente
{
	char nome[50]; //nome do cliente
	char cpf[13]; //cpf do cliente
	char telefone[13]; //etc...
	char cep[10];
	char email[50];
};

void arrowHere (int realPosition, int arrowPosition);

int menu () //funcao utilizada para introduzir um menu de opcoes. 
{
    //Criacao de um menu de "flechas".
	system("cls");
	int position = 1;
	int keyPressed = 0;
	
	#define MAX 5
	#define MIN 1
	
    //o getchar capta quando clicamos em uma das setas, caso cliquemos na de "cima" ele, subtrai da variavel posicao, quando clicamos na de "baixo", ele soma a varivel posicao.
    //a variavel position eh a resposavel pela posicao da flecha sendo que essa posicao varia de 1 a 3.
	while (keyPressed != 13)
	{
		system("cls");
		
		printf("Como posso te ajudar?\n\n");
	
		arrowHere(1, position); printf("|1| Cadastro\n\n");
		arrowHere(2, position); printf("|2| Consulta\n\n");
		arrowHere(3, position); printf("|3| Alterar dados\n\n");
		arrowHere(4, position); printf("|4| Excluir\n\n");
		arrowHere(5, position); printf("|5| SAIR\n");
		
		keyPressed = getch();
		fflush(stdin);
	
		if(keyPressed == 80 && position != MAX)
		{
			position++;
		}
	
		else if(keyPressed == 72 && position != MIN)
		{
			position--;
		}
	
		else
		{
			position = position;
		}
	}
    //retorna o valor da "position" que sera utilizado na main.
	return position;	
}

void arrowHere (int realPosition, int arrowPosition) //funcao utilizada para imprimir a "flecha" no menu.
{
    //funcao da flecha que utilizamos no menu.
	if(realPosition == arrowPosition)
	{
		printf(" --->>> - ");
	}
	
	else
	{
		printf("          ");
	}
}

//funcao que cadastra os novos usuarios
int cadastro ()
{
	int ret_fclose; //armazena o retorno da fclose
	system("cls");
	FILE *arq;
	struct cliente c; //declaracao da struct dentro da funcao
	
	arq = fopen("cliente","a+"); //abre o arquivo na funcao de criar/escrever/adcionar
	
	if(arq == NULL) 
	{
		//caso de algum erro...
		printf("\nErro na abertura do arquivo\n");
	}
	
	else
	{	
		//se conseguir abrir certo, recolhe os dados da struct
		printf("Nome completo: ");
		fflush(stdin);
		fgets(c.nome, 50, stdin);
		c.nome[strcspn(c.nome, "\n")] = '\0';
		
		printf("CPF: ");
		fflush(stdin);
		fgets(c.cpf, 13, stdin);
		c.cpf[strcspn(c.cpf, "\n")] = '\0';
	 
		printf("Email: ");
		fflush(stdin);
		fgets(c.email, 50, stdin);
		c.email[strcspn(c.email, "\n")] = '\0';
		
		printf("Telefone: ");
		fflush(stdin);
		fgets(c.telefone, 13, stdin);
		c.telefone[strcspn(c.telefone, "\n")] = '\0';
		
		printf("CEP: ");
		fflush(stdin);
		fgets(c.cep, 10, stdin);
		c.cep[strcspn(c.cep, "\n")] = '\0';
		
		//anota no arquivo os dados recolhidos acima
		fwrite(&c, sizeof(struct cliente), 1, arq);
		
		if(ferror(arq))
		{
			//caso de rro na hora de escrever no arquivo
			system("cls");
			printf("\nErro na gravacao\n");
			system("pause");
		}
		
		else
		{
			//se conseguir escrever no arquivo
			system("cls");
			printf("Gravacao OK\n");
			system("pause");
		}
		
		//chama a fclose e guarda o seu retorno na variavel
		ret_fclose = fclose(arq);
		
		//se tudo der certo...
		if(ret_fclose == 0)
		{
			system("cls");
			printf("FECHAR: Sucesso no fechamento\n");
			system("pause");
		}
		
		//se der algum erro...
		else
		{
			system("cls");
			printf("\nFECHAR: Erro no fechamento\n");
			system("pause");
		}
	}
}

//funcao que mostra os clientes cadastrados
void consulta ()
{
	FILE *arq;
	struct cliente c;
	system("cls");
	
	//abre o arquivo na funcao de leitura
	arq = fopen("cliente", "rt");
	
	if (arq == NULL)
	{
		//caso de algum erro
		system("cls");
 		printf("Erro de abertura de arquivo"); 
 	}
 	
 	else
 	{
 		//ciclo que printa as informacoes, enquanto elas nao acabam
	 	while (fread (&c, sizeof(struct cliente), 1, arq) == 1)
	 	{
		 	printf("Nome.............: %s", c.nome); 
			printf("\nCPF..............: %s", c.cpf);
		 	printf("\nTelefone.........: %s", c.telefone);
		 	printf("\nCEP..............: %s", c.cep);
			printf("\nEmail............: %s\n\n", c.email);
		}
	}
	fclose (arq);
}

//funcao que altera um certo dado dentro do arquivo
void alterar ()
{
	system("cls");
	int flag = 0; //variavel usada pra indicar sucesso ou falha na busca pelo cpf
	char cpf[13]; //variavel que armazena o cpf que o usuario deseja buscar
	FILE *arq;
	arq = fopen("cliente", "r+");
	struct cliente c;
	
	printf("Informe seu cpf: ");
	fflush(stdin);
	fgets(cpf, 13, stdin);
	cpf[strcspn(cpf, "\n")] = '\0';
	
	if(arq == NULL)
	{
		//caso de erro na abertura do arquivo
		printf("Erro na abertura do arquivo\n\n\n");
	}
	
	else
	{
		//funcao que le o arquivo ate achar o cpf desejado
		while(fread(&c, sizeof(struct cliente), 1, arq) == 1)
		{
			//comparacao do cpf informado com os cpfs guardados
			if(strcmp(cpf, c.cpf) == 0)
			{
				flag = 1; //caso ache a flag ganha valor 1, logo nao cai no if mais pra frente;
				
				//novas informacoes sao dadas
				printf("Novo nome: ");
				fflush(stdin);
				fgets(c.nome, 50, stdin);
				c.nome[strcspn(c.nome, "\n")] = '\0'; 
				
				printf("Email: ");
				fflush(stdin);
				fgets(c.email, 50, stdin);
				c.email[strcspn(c.email, "\n")] = '\0';
				
				printf("Telefone: ");
				fflush(stdin);
				fgets(c.telefone, 13, stdin);
				c.telefone[strcspn(c.telefone, "\n")] = '\0';	
				
				printf("CEP: ");
				fflush(stdin);
				fgets(c.cep, 10, stdin);
				c.cep[strcspn(c.cep, "\n")] = '\0';
				
				fseek(arq, -sizeof(struct cliente), 1); //volta uma struct, a partir do arquivo que contem o cpf desejado
				fwrite(&c, sizeof(struct cliente), 1, arq); //e reescreve por cima dela, colocando os novos dados
				fflush(arq);
			}
		}
		
		if(flag == 0)
		{
			//a flag continuando com o valor 0, entra nesse "if"
			printf("Cliente nao encontrado\n");
			system("pause");
		}
	}
	fclose(arq);
}

void excluir ()
{
	system("cls");
	struct cliente c;
	
	//abre dois arquivos
	FILE *arq = fopen("cliente", "r+w");
    FILE *novoarq = fopen("temp", "w+");
    char cpf[13];

	//informa o cpf da conta a ser excluida
    printf("Informe o CPF do cliente a ser exlcuido: ");
    fflush(stdin);
	fgets(cpf, 13, stdin);
	cpf[strcspn(cpf, "\n")] = '\0';
	
	//ciclo que le o arquivo ate achar o cpf desejado
    while(fread (&c, sizeof(struct cliente), 1, arq) == 1)
	{
     	//comparacao do cpf informado com os cpfs do arquivo   
		if(strcmp(cpf, c.cpf))
		{
			//se nao for igual, escreve os dados do primeiro arquivo no segundo
            fwrite(&c, sizeof(struct cliente), 1, novoarq);
        }
    }
    
    //fecham os dois arquivos
    fclose(novoarq);
    fclose(arq);
    
    //deleta o antigo que contem a informacao indesejada, e renomeia o novo com o nome do antigo
    remove("cliente");
    rename("temp", "cliente");
}

int main ()
{
	int resp, resp2;
	
	printf("Ola, seja bem-vindo ao banco de dados dos calouros\n\n\n");
	system("pause");
	
	do
	{
		//chama a funcao menu e guarda seu retorno na variavel resp
		resp = menu();
		
		//se esolhido 1...
		if(resp == 1)
		{
			do
			{
				//chama a funcao cadastro
				cadastro();
				
				do
				{
					//reprocessamento
					system("cls");
					printf("Gostaria de repetir o processo?\n");
					printf("[1] Sim\n");
					printf("[2] Nao\n");
					scanf("%d", &resp2);
				}while(resp2 != 1 && resp2 != 2);
			}while(resp2 == 1);
		}
		
		//se 2...
		else if(resp == 2)
		{
			//chama a funcao consulta
			consulta();
			printf("\n\n");
			system("pause");
		}
		
		//se 3...
		else if(resp == 3)
		{
			do
			{
				//chama a funcao altera
				alterar();
				system("pause");
				do
				{
					//reprocessamento
					system("cls");
					printf("Gostaria de repetir o processo?\n");
					printf("[1] Sim\n");
					printf("[2] Nao\n");
					scanf("%d", &resp2);
				}while(resp2 != 1 && resp2 != 2);
			}while(resp2 == 1);	
		}
		
		//se 4...
		else if(resp == 4)
		{
			do
			{
				//chama a funcao excluir
				excluir();
				system("pause");
				
				do
				{
					//reprocessamento
					system("cls");
					printf("Gostaria de repetir o processo?\n");
					printf("[1] Sim\n");
					printf("[2] Nao\n");
					scanf("%d", &resp2);
				}while(resp2 != 1 && resp2 != 2);
			}while(resp2 == 1);	
		}
		
		do
		{
			system("cls");
			printf("Retornar ao menu?\n");
			printf("[1] Sim\n");
			printf("[2] Nao\n");
			scanf("%d", &resp2);
		}while(resp2 != 1 && resp != 2);
	}while(resp2 == 1);
	
	return 0;
}
