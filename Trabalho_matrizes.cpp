#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double sec (double a)
{
	return 1 / cos(a);
}

double cossec (double a)
{
	return 1 / sin(a);
}

double cotan (double a)
{
	return 1 / tan(a);
}

int main ()
{
	system ("color 06");
	int rp, rp2, f1, f2, f3, f4, r1, r2, r3;
	double a1, a2;
	
	printf("Ola, sou a calculadora trigonometrica!\n\n");
	do
	{
		do
		{
			system("cls");
			printf("\nO que gostaria de calcular?\n");
			printf("[1] Funcoes trigonometricas\n");
			printf("[2] Arcos\n");
			printf("Resposta: ");
			scanf("%d", &rp);
		}while(rp != 1 && rp != 2);
		
		if(rp == 1)
		{
			do
			{
				do
				{
					printf("\nGostaria de calcular seu angulo em radianos(1) ou em graus(2)?\n");
					printf("Resposta: ");
					scanf("%d", &f1);
				}while((f1 != 1) && (f1 != 2));
		
				printf("\nqual o angulo desejado?\n");
				printf("Resposta: ");
				scanf("%lf", &a1);
			
				if(f1 == 2)
				{
					a1 = a1 * (M_PI / 180);
				}
		
				do
				{
					printf("\nO que gostaria de saber desse angulo?\n");
					printf("[1] Seno\n");
					printf("[2] Cosseno\n");
					printf("[3] Tangente\n");
					printf("[4] Cossecante\n");
					printf("[5] Secante\n");
					printf("[6] Cotangente\n");
					printf("Resposta: ");
					scanf("%d", &f2);
			
					if(f2 == 1)
					{
						printf("\nSeno = %.3lf\n\n", sin(a1));			
					}
			
					else if(f2 == 2)
					{
						printf("\nCosseno = %.3lf\n\n", cos(a1));
					}
			
					else if(f2 == 3)
					{
						printf("\nTangente = %.3lf\n\n", tan(a1));
					}
			
					else if(f2 == 4)
					{
						printf("\nCossecante = %.3lf\n\n", cossec(a1));
					}
			
					else if(f2 == 5)
					{
						printf("\nSecante = %.3lf\n\n", sec(a1));
					}
			
					else if(f2 == 6)
					{
						printf("\nCotangente = %.3lf\n\n", cotan(a1));
					}
			
					do
					{
						printf("Gostaria de calcular mais alguma opcao?\n");
						printf("[1] Sim\n");
						printf("[2] Nao\n");
						printf("Resposta: ");
						scanf("%d", &f3);
					}while(f3 != 1 && f3 != 2);
				}while(f3 != 2);
					
					do
					{
					printf("\nGostaria de utilizar um novo angulo? ");
					printf("\n[1] Sim");
					printf("\n[2] Nao\n");
					printf("Resposta: ");
					scanf("%d", &f4);
					}while(f4 != 1 && f4 != 2);
			}while(f4 != 2);
	 	}
	 	
	 	else if(rp == 2)
	 	{
	 		do
	 		{
				printf("\nQual o valor desejado?\n");
				printf("Resposta: ");
				scanf("%lf", &a2);
				do
				{
					do
					{
						printf("\nEscolha a opcao\n");
						printf("[1] Arco Seno\n");
						printf("[2] Arco Cosseno\n");
						printf("[3] Arco Tangente\n");
						printf("Resposta: ");
						scanf("%d", &r1);
					}while(r1 != 1 && r1 != 2 && r1 != 3);
				
					if(r1 == 1)
					{
						printf("=%.3lf radianos\n\n", asin(a2));
					}
					
					else if(r1 == 2)
					{
						printf("=%.3lf radianos\n\n", acos(a2));
					}
				
					else if(r1 == 3)
					{
						printf("=%.3lf radianos\n\n", atan(a2));
					}
					
					do
					{
						printf("\nGostaria de calcular mais alguma opcao?\n");
						printf("[1] Sim\n");
						printf("[2] Nao\n");
						printf("Resposta: ");
						scanf("%d", &r2);
					}while(r2 != 1 && r2 != 2);
					
				}while(r2 != 2);
				
					do
					{
						printf("\nGostaria de usar outro valor?\n");
						printf("[1] Sim\n");
						printf("[2] Nao\n");
						printf("Resposta: ");
						scanf("%d", &r3);
					}while(r3 != 1 && r3 != 2);
				
			}while(r3 != 2);
		}
	 	
	 	do
	 	{
	 		printf("\nGostaria de voltar ao menu inicial?\n");
	 		printf("[1] Sim\n");
		 	printf("[2] Nao\n");
	 		printf("Resposta: ");
	 		scanf("%d", &rp2);
	 	}while(rp2 != 1 && rp2 != 2);
		 
	}while(rp2 != 2);
	
	return 0;
}
