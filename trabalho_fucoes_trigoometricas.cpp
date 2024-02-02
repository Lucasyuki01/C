#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

void arrowHere (int realPosition, int arrowPosition);

int menu ()
{
	system("cls");
	int position = 1;
	int keyPressed = 0;
	
	#define MAX 9
	#define MIN 1
	
	while (keyPressed != 13)
	{
		system("cls");
		
		printf("O que gostaria de fazer nessa matriz?\n\n");
	
		arrowHere(1, position); printf("|1| Mostrar como esta a matriz\n\n");
		arrowHere(2, position); printf("|2| Trocar as linhas da matriz\n\n");
		arrowHere(3, position); printf("|3| Trocar as colunas da matriz\n\n");
		arrowHere(4, position); printf("|4| Trocar as diagonais da matriz\n\n");
		arrowHere(5, position); printf("|5| Verificar se eh simetrica\n\n");
		arrowHere(6, position); printf("|6| Verificar se eh um quadrado magico\n\n");
		arrowHere(7, position); printf("|7| Verificar se eh um quadrado latino\n\n");
		arrowHere(8, position); printf("|8| Verificar se eh uma matriz de permutacao\n\n");
		arrowHere(9, position); printf("|9| SAIR\n");
		
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
	
	return position;	
}

void arrowHere (int realPosition, int arrowPosition)
{
	if(realPosition == arrowPosition)
	{
		printf(" --->>> - ");
	}
	
	else
	{
		printf("          ");
	}
}

void imprima (int m[][100], int linha, int coluna)
{
	int i, n;
	
	printf("\n\n");
	for (i=0; i < linha; i++)
		{
			printf("\t\t");
			for(n =0; n < coluna; n++)
			{
				printf("%d\t", m[i][n]);
			}
			printf("\n\n\n");
		}
		
		printf("\n\n");
}
int elementos (int m[][100], int y, int x)
{
	
	int i, n;
	
	for (i = 0; i < y; i++)
		{
			for (n = 0; n < x; n++)
			{
				printf("Escolha o valor da casa %d %d: ", i, n);
				scanf("%d", &m[i][n]);
			}
		}
	
}
 
 int trocalinha (int m[][100], int linha1, int linha2, int x)
{
	
	int i, j, z;
	for(i = 0; i < x; i++)
	{
		z = m[linha2][i];
		m[linha2][i] = m[linha1][i];
		m[linha1][i] = z;
	}
}

int trocoluna (int m[][100], int coluna1, int coluna2, int y)
{
	
	int i, j, z;
	for(i = 0; i < y; i++)
	{
		z = m[i][coluna2];
		m[i][coluna2] = m[i][coluna1];
		m[i][coluna1] = z;
	}
}

int trocadiagonal (int m[][100], int linha, int coluna)
{
	if (linha != coluna)
	{
		return 0;
	}
	
	int i, n, z;
	for (i = 0, n = linha-1; i < linha; i++, n--)
    {
        z = m[i][n];
        m[i][n] = m[i][i];
		m[i][i] = z;
	}
	return 1;
}

int simetrica (int m[][100], int linha, int coluna)
{
	int i, n, mt[linha][coluna];
	
	for(i = 0; i < linha; i++)
    {
        for(n = 0; n < coluna; n++)
        {
            mt[i][n] = m[n][i];
        }
    }
    
    for (i = 0; i < linha; i++)
    {
        for(n = 0; n < coluna; n++)
        {
            if(m[i][n] != mt[i][n])
            {
                return 0;
            }
        }
    }

    return 1;
}

int magico (int m[][100], int linha, int coluna)
{
	
	if (linha != coluna)
	{
		return 0;
	}
	
	int sumlinha, sumcoluna, sumdp, sumds, suml0 = 0, n, i;

	for(i = 0; i < coluna; i++)
	{
		suml0 += m[0][i];
	}
	
	for(i = 1; i < linha; i++)
	{
		sumlinha = 0;
		
		for(n = 0; n < coluna; n++)
		{
			sumlinha += m[i][n];	
		}
		
		if(sumlinha != suml0)
		{
			return 0;
		}
	}
	
	for(i = 0; i < coluna; i++)
	{
		sumcoluna = 0;
		
		for(n = 0; n < linha; n++)
		{
			sumcoluna += m[n][i];	
		}
		
		if(sumcoluna != suml0)
		{
			return 0;
		}
	}
	
	for (i = 0, n = linha-1; i < linha; i++, n--)
    {
        sumdp += m[i][i];
        sumds += m[i][n];
	}
	
	if(suml0 != sumdp)
	{
		return 0;
	}
	
	else if(suml0 != sumds)
	{
		return 0;
	}
	
	return 1;
}

int permutacao (int m[][100], int linha, int coluna)
{
	int cont0, cont1, i, n;
	for (i = 0; i < linha; i++)
	{
	    cont0 = 0;
	    cont1 = 0;
	    for (n = 0; n < linha; n++)
		{
	    	if (m[i][n] == 0)
			{
				cont0++;
			}
			 
	    	else
			{
				if (m[i][n] == 1)
				{
					cont1++;
				}
				
				else
				{
					return 0;
				}
	      	}
	    }
	    
	    if (cont0 != linha-1 || cont1 != 1)
		{
			return 0;
	    }
	}
	
	for (n = 0; n < linha; n++)
	{
		cont0 = 0;
	    cont1 = 0;
	    for (i = 0; i < linha; i++)
		{
	    	if (m[i][n] == 0)
			{
				cont0++;
	    	}
	    	
	      	else
			{
				if (m[i][n] == 1)
				{
		  			cont1++;
				}
				
				else
				{
					return 0;
				}
	      	}
	    }
	    
	    if (cont0 != linha-1 || cont1 != 1)
		{
			return 0;
	    }
	}
	  return 1;
}
int latino(int m[][100], int linha, int coluna)
{
    if (linha != coluna)
    {
        return 0;
    }
    
    int i, n, k, vet[linha];

    for (i = 0; i < linha; i++)
    {
        vet[i] = 0;
        
        for (n = 0; n < linha; n++) 
        {
            vet[i] += m[i][n];
            
            for (k = 0; k < linha; k++)
			{
                
                if (m[i][n] == m[i][k] && n != k)
				{
                    return 0;
                }
            }
                
        }
    }

    for (i = 0; i < linha - 1; i++)
	{
        
        if (vet[i] != vet[i + 1])
		{
            return 0;
        }
    }
        
    for (n = 0; n < linha; n++){
        vet[n] = 0;
        
        for (i = 0; i < linha; i++) 
        {
            vet[n] += m[i][n];
            
            for (k = 0; k < linha; k++){
                if (m[i][n] == m[k][n] && i != k){
                    return 0;
                }
            }
        }
    }

    for (i = 0; i < linha - 1; i++){
        if (vet[i] != vet[i + 1]){
            return 0;
        }
    }
        
    return 1;
    
}
int main()
{
	int m[100][100], x, y, w, i, n, r1, r2, position, linha1, linha2, coluna1, coluna2;
	
	printf("Ola, eu sou a calculadora de matrizes!\n\n");
	do
	{
		printf("Digite quantas colunas voce quer na matriz: ");
		scanf("%d", &x);
		
		printf("\nAgora, o numero de linhas: ");
		scanf("%d", &y);
		
		printf("\n");
		
		elementos(m, y, x);
		printf("\n");
		do
		{
			printf("Gostaria de utiliza-la[1], ou de montar uma nova[2]?\n");
			printf("Resposta: ");
			scanf("%d", &r1);
			system("cls");
			
			if(r1 == 1)
			{
				printf("\nO que gostaria de fazer nessa matriz?\n");
				
			}
			
			else if(r1 == 2)
			{
				printf("\n");
			}
			
		}while(r1 != 1 && r1 != 2);
		
	}while(r1 == 2);
	
	do
	{	
		position = menu();
	
		if(position == 1)
		{
			system("cls");
			imprima(m, y, x);
			do
			{
				printf("Gostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);
		}
		
		else if(position == 2)
		{
			system("cls");
			printf("Esolha as linhas que quer trocar:\n");
			
			do
			{
				printf("Primeira linha: ");
				scanf("%d", &linha1);	
			}while(linha1 < 0 || linha1 >= y);
			
			do
			{
				printf("Segunda linha: ");
				scanf("%d", &linha2);	
			}while(linha2 < 0 || linha2 >= y);
			
			trocalinha(m, linha1, linha2, x);
			
			printf("\nLinhas trocadas com sucesso!\n");
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);
		}
		
		else if(position == 3)
		{
			system("cls");
			printf("Esolha as colunas que quer trocar:\n");
			
			do
			{
				printf("Primeira coluna: ");
				scanf("%d", &coluna1);	
			}while(coluna1 < 0 || coluna1 >= x);
			
			do
			{
				printf("Segunda coluna: ");
				scanf("%d", &coluna2);	
			}while(coluna2 < 0 || coluna2 >= x);
			
			trocoluna(m, coluna1, coluna2, y);
			
			printf("\nColunas trocadas com sucesso!\n");
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);
		}
		
		else if(position == 4)
		{
			system("cls");
			w = trocadiagonal(m, y, x);
			if (w == 0)
			{
				printf("Nao existe diagonal de uma matriz nao quadrada...\n");
			}
			
			else
			{
				
				printf("\nDiagonais trocadas com sucesso!\n");
			}
			
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);
		}
		
		else if(position == 5)
		{
			system("cls");
			w = simetrica(m, y, x);
			
			if(w == 0)
			{
				printf("\nMatriz nao simetrica\n\n");
			}
			
			else
			{
				printf("\nMatriz simetrica!\n\n");
			}
			
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);	
		}
		
		else if(position == 6)
		{
			system("cls");
			w = magico(m, y, x);
			
			if(w == 0)
			{
				printf("\nMatriz nao eh quadrado magico\n\n");
			}
			
			else
			{
				printf("\nMatriz eh um quadrado magico!\n\n");
			}
			
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);	
		}
		
		else if(position == 7)
		{
			system("cls");
			w = latino(m, y, x);
			
			if(w == 0)
			{
				printf("\nMatriz nao eh quadrado latino\n\n");
			}
			
			else
			{
				printf("\nMatriz eh um quadrado latino!\n\n");
			}
			
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);	
		}
		
		else if(position == 8)
		{
			system("cls");
			w = permutacao(m, y, x);
			
			if(w == 0)
			{
				printf("\nNao eh matriz de permucao\n\n");
			}
			
			else
			{
				printf("\nEh matriz de permutacao!\n\n");
			}
			
			do
			{
				printf("\nGostaria de retornar ao menu?\n");
				printf("Sim [1]\n");
				printf("Nao [2]\n");
				scanf("%d", &r2);
			}while(r2 != 1 && r2 != 2);
		}
		
	}while(position != 9 && r2 != 2);

	return 0;
}
