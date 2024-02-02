#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//SENHA: 121152

void arrowHere (int realPosition, int arrowPosition);

int senha () //funcao utilizada para senha de acesso do software do banco.
{
	int pw, cont = 0, n = 2;
	
	do
	{
		printf("Por favor, digite sua senha: ");
		scanf("%d", &pw);
		
        //apenas 3 chances para entrar
		if(pw != 121152)
		{
			system("cls");
			cont++;
			printf("Senha incorreta!\n");
			printf("Voce tem mais %d chance(s)\n\n", n);
			n--;
		}
	}while(pw != 121152 && cont != 3);
	
    //retorna o cont para main que caso seja igual a senha, deixa o codigo prosseguir
	return cont;
}

void tempo () //funcao utlizada para informar a data no preenchimento do cheque.
{
    //utilizamos a biblioteca time.h em praticamente toda essa funcao
	struct tm *data_hora_atual;     
	  
	time_t segundos;
	
	time(&segundos);   
	  
	data_hora_atual = localtime(&segundos);  
	
    //primeira parte da data, o "dia".
	printf("Ilhas Weblands, %d de ", data_hora_atual->tm_mday);
	
    //transformacao dos meses para forma extensa, e sua impressao na data.
	if(data_hora_atual->tm_mon+1 == 1)
	{
		printf("Janeiro");
	}
	
	else if(data_hora_atual->tm_mon+1 == 2)
	{
		printf("Fevereiro");
	}
	
	else if(data_hora_atual->tm_mon+1 == 3)
	{
		printf("Marco");
	}
	
	else if(data_hora_atual->tm_mon+1 == 4)
	{
		printf("Abril");
	}
	
	else if(data_hora_atual->tm_mon+1 == 5)
	{
		printf("Maio");
	}
	
	else if(data_hora_atual->tm_mon+1 == 6)
	{
		printf("Junho");
	}
	
	else if(data_hora_atual->tm_mon+1 == 7)
	{
		printf("Julho");
	}
	
	else if(data_hora_atual->tm_mon+1 == 8)
	{
		printf("Agosto");
	}
	
	else if(data_hora_atual->tm_mon+1 == 9)
	{
		printf("Setembro");
	}
	
	else if(data_hora_atual->tm_mon+1 == 10)
	{
		printf("Outubro");
	}
	
	else if(data_hora_atual->tm_mon+1 == 11)
	{
		printf("Novembro");
	}
	
	else if(data_hora_atual->tm_mon+1 == 12)
	{
		printf("Dezembro");
	}
	
    //ultima parte da data, o ano.
	printf(" de %d\n\n", data_hora_atual->tm_year+1900);
}

int cedulas (float Z)//funcao utilizada para separar as cedulas e as moedas.
{
	int X, Y, peixe, onca, mico, arara, garca,tartaruga, mulher, careca, dompedro, marechal, liberdade;
	//Salvamos a variavel Z em X.
    X = Z;

    //Separamos as notas utilizando o resto.
	peixe = X/100;
	onca = (X%100)/50;
	mico = ((X%100)%50)/20;
	arara = (((X%100)%50)%20)/10;
	garca = ((((X%100)%50)%20)%10)/5;
	tartaruga = (((((X%100)%50)%20)%10)%5)/2;
	mulher = ((((((X%100)%50)%20)%10)%5)%2);
	Y = Z * 100;
	X = Y%100;

    //Separamos as moedas.
	careca = (X)/50;
	dompedro = ((X)%50)/25;
	marechal = (((X)%50)%25)/10;
	liberdade = (((((X)%50)%25)%10));
	printf("Voce recebera:\n\n");
	printf ("NOTAS:\n");
	printf ("%d nota(s) de B$ 100.00\n", peixe);
	printf ("%d nota(s) de B$ 50.00\n", onca);
	printf ("%d nota(s) de B$ 20.00\n", mico);
	printf ("%d nota(s) de B$ 10.00\n", arara);
	printf ("%d nota(s) de B$ 5.00\n", garca);
	printf ("%d nota(s) de B$ 2.00\n", tartaruga);
	printf ("\nMOEDAS:\n");
	printf ("%d moeda(s) de B$ 1.00\n", mulher);
	printf ("%d moeda(s) de B$ 0.50\n", careca);
	printf ("%d moeda(s) de B$ 0.25\n", dompedro);
	printf ("%d moeda(s) de B$ 0.10\n", marechal);
	printf ("%d moeda(s) de B$ 0.01\n\n", liberdade);
	printf("Quantidade total: %.2f B$\n\n", Z);
	return 0;
}

int preenche () //funcao utilizada para o preenchimento do cheque
{
	double a, temp, temp2, cents, uni;
    int b, dec, cen, vuti, vuti2, i;
    
    system("cls");
    
    printf("(ATENCAO: Cheques somente abaixo de um bilhao de Bits!)\n");
    printf("Digite o valor do cheque: ");
    scanf("%lf", &a);
    
    b = a;
    temp = a;
    temp = temp - b;
    temp = temp * 100;
    cents = temp; 
	
	system("cls");
    printf("B$ #%d,%.0lf#\n\n", b, temp); //primeiramente eh escrito o valor numerico da quantia
      
    printf("Pague por este cheque a quantia de: ");
    
    
    //AQUI COMECAM AS NOTAS INTEIRAS, NAO CENTAVOS 
    /*  As anotacoes escritas com letras maiusculas foram utilizadas durante a escrita do codigo
    para me ajudar a saber em que seccao eu estava, entre notas inteiras (divididas entre milhao, milhar e centena)
    e centavos.*/
    

    /*  Aqui comeca a divisao de variaveis para os milhoes, o processo foi dividir temp por 1000000
    pegando apenas a parte inteira (tendo sido guardado em temp todo o valor int do cheque), assim
    temos separadas as 3 casas do milhao: centena de milhao (cen), dezena de milhao (dec) e unidade de milhao (uni).
        A partir disso foram utilizadas sequencias de if baseadas no valor dessas 3 variaveis (cen, dec e uni)
    para escrever palavra por palavra o valor final do cheque. Esse processo foi repetido para todas as 3 sessoes
    de valores inteiros (milhao, milhar e centena), utilizando as mesmas variaveis, com apenas pequenas
    diferencas que serao comentadas a medida que aparecerem*/

    temp = b;
    temp = (int)temp / 1000000;
    cen = temp / 100;
    cen = cen * 100;
    dec = (temp - cen) / 10;
    dec = dec * 10;
    uni = temp - cen - dec;
    temp2 = dec + uni; //variavel utilizada para testar os casos especificos no qual o decimal eh 10, pois nao seguem nomenclatura normal (ex. "treze")
    vuti = (cen + dec + uni)*1000000; //valor utilizado (vuti) eh uma variavel que vai guardar qual parte do valor ja foi escrita, para ser eliminada nas proximas seccoes
    
    if((cen >= 100 && cen <=900)) //escrita das centenas (nesse caso de milhao)
    {
        if(cen == 100)
        {
        	if(uni == 0 && dec == 0)
        	printf("cem");
        	else
            printf("cento");
        }
        
        else if(cen == 200)
        {
            printf("duzentos");
        }
        
        else if(cen == 300)
        {
            printf("trezentos");
        }
        
        else if(cen == 400)
        {
            printf("quatrocentos");
        }
        
        else if(cen == 500)
        {
            printf("quinhentos");
        }
        
        else if(cen == 600)
        {
            printf("seiscentos");
        }
        
        else if(cen == 700)
        {
            printf("setecentos");
        }
        
        else if(cen == 800)
        {
            printf("oitocentos");
        }
        
        else if(cen == 900)
        {
            printf("novecentos");
        }
        
        if(dec != 0 || uni != 0) //varios testes similares a esse estao ao longo do programa, com o intuito de colocar um "e" entre partes do numero quando necessario
    	{
    	printf(" e ");
		}
	}
    if (dec >= 10 && dec <=90) //escrita das dezenas (nesse caso de milhao)
	{
        if(dec == 10)
        {
        	if(temp2 == 10) printf("dez"); //sessao especifica para os casos anomalos
        	if(temp2 == 11) printf("onze");
        	if(temp2 == 12) printf("doze");
        	if(temp2 == 13) printf("treze");
        	if(temp2 == 14) printf("quatorze");
        	if(temp2 == 15) printf("quinze");
        	if(temp2 == 16) printf("dezesseis");
        	if(temp2 == 17) printf("dezessete");
        	if(temp2 == 18) printf("dezoito");
        	if(temp2 == 19) printf("dezenove");
        }
        
        else if(dec == 20)
        {
            printf("vinte");
        }
        
        else if(dec == 30)
        {
            printf("trinta");
        }
        
        else if(dec == 40)
        {
            printf("quarenta");
        }
        
        else if(dec == 50)
        {
            printf("cinquenta");
        }
        
        else if(dec == 60)
        {
            printf("sessenta");
        }
        
        else if(dec == 70)
        {
            printf("setenta");
        }
        
        else if(dec == 80)
        {
            printf("oitenta");
        }
        
        else if(dec == 90)
        {
            printf("noventa");
        }
    }
    
    if((uni != 0 && dec != 0) && (temp2 < 10 || temp2 > 19))
    {
    	printf(" e ");
	}
	
    if((uni >= 0 && uni <=9) && (temp2 < 10 || temp2 > 19)) //escrita das unidades (nesse caso de milhao)
    {
        if(uni == 1)
        {
            printf("um");
        }
        
        else if(uni == 2)
        {
            printf("dois");
        }
        
        else if(uni == 3)
        {
            printf("tres");
        }
        
        else if(uni == 4)
        {
            printf("quatro");
        }
        
        else if(uni == 5)
        {
            printf("cinco");
        }
        
        else if(uni == 6)
        {
            printf("seis");
        }
        
        else if(uni == 7)
        {
            printf("sete");
        }
        
        else if(uni == 8)
        {
            printf("oito");
        }
        
        else if(uni == 9)
        {
            printf("nove");
        }    
	}
	if(vuti != 0 && vuti !=1000000) //variacoes de plural, alem de checar a existencia de vuti para que nao apareca escrito milhoes quando nao ha nada nas casas dos milhoes
    printf(" milhoes ");
    if(vuti != 0 && vuti ==1000000)
    printf(" milhao ");
	
    //MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO MILHAO 

    /*  E aqui chegamos as casas dos milhares. Como a maior parte do codigo de cada parte eh identica, apenas as maiores diferencas serao apontadas,
    pois as estruturas gerais e as variaveis utilizadas sao as mesmas*/


    temp = b - vuti; //o valor de temp utilizado dessa vez tem o valor utilizado (vuti) da ultima vez subtraido, para que nao utilize numeros que ja foram escritos
    temp = (int)temp / 1000; //a divisao muda porque dessa vez queremos os milhares, nao milhoes
    cen = temp / 100;
    cen = cen * 100;
    dec = (temp - cen) / 10;
    dec = dec * 10;
    uni = temp - cen - dec;
    temp2 = dec + uni;
    vuti2 = (cen + dec + uni)*1000; //assim como antes o valor utilizado eh guardado, dessa vez em uma nova variavel (vuti2)                       
    
    /*aqui ha um caso extremamente especifico de colocacao de "e" que vale a pena ser comentado a parte, pois esse eh um e extremamente
    irregular que so existe para numeros montados de determinadas formas (ex: 1003456 = um milhao tres mil quatrocentos e cinquenta e 6 nao tem esse e, porem
    1003000 = um milhao "e" tres mil, 1053000 = um milhao "e" cinquenta e tres mil). Ele precisa checar casos especificos de existencia ou nao de centena, 
    dezena e unidade do proprio milhar e de existencia ou nao das outras duas seccoes (milhoes e centenas) para saber quando colocar ou nao o "e"*/

    //vale notar que na proxima seccao ha outro extremamente parecido com esse, porem com uma restricao a menos e um caso a mais

    if(vuti != 0)
	{
    	if((((cen == 0 || (dec == 0 && uni ==0)) || (cen == 0 && dec == 0)) && b%1000 == 0) && ((cen != 0 || dec != 0) || uni != 0))printf("e ");     //calculo do resto de b por mil eh necessario para para saber se ha algo na seccao das centenas
    }
    
	if((cen >= 100 && cen <=900))
    
    if((cen >= 100 && cen <=900))
    {
        if(cen == 100)
        {
        	if(uni == 0 && dec == 0)
        	printf("cem");
        	else
            printf("cento");
        }
        
        else if(cen == 200)
        {
            printf("duzentos");
        }
        
        else if(cen == 300)
        {
            printf("trezentos");
        }
        
        else if(cen == 400)
        {
            printf("quatrocentos");
        }
        
        else if(cen == 500)
        {
            printf("quinhentos");
        }
        
        else if(cen == 600)
        {
            printf("seiscentos");
        }
        
        else if(cen == 700)
        {
            printf("setecentos");
        }
        
        else if(cen == 800)
        {
            printf("oitocentos");
        }
        
        else if(cen == 900)
        {
            printf("novecentos");
        }
        
        if(dec != 0 || uni != 0)
    	{
    	printf(" e ");
		}
	}
    
    if (dec >= 10 && dec <=90)
	{
        if(dec == 10)
        {
        	if(temp2 == 10) printf("dez");
        	if(temp2 == 11) printf("onze");
        	if(temp2 == 12) printf("doze");
        	if(temp2 == 13) printf("treze");
        	if(temp2 == 14) printf("quatorze");
        	if(temp2 == 15) printf("quinze");
        	if(temp2 == 16) printf("dezesseis");
        	if(temp2 == 17) printf("dezessete");
        	if(temp2 == 18) printf("dezoito");
        	if(temp2 == 19) printf("dezenove");
        }
        
        else if(dec == 20)
        {
            printf("vinte");
        }
        
        else if(dec == 30)
        {
            printf("trinta");
        }
        
        else if(dec == 40)
        {
            printf("quarenta");
        }
        
        else if(dec == 50)
        {
            printf("cinquenta");
        }
        
        else if(dec == 60)
        {
            printf("sessenta");
        }
        
        else if(dec == 70)
        {
            printf("setenta");
        }
        
        else if(dec == 80)
        {
            printf("oitenta");
        }
        
        else if(dec == 90)
        {
            printf("noventa");
        }
    }
    
    if((uni != 0 && dec != 0) && (temp2 < 10 || temp2 > 19))
    {
    	printf(" e ");
	}
	
    if((uni >= 0 && uni <=9) && (temp2 < 10 || temp2 > 19))
    {
        if(uni == 1)
        {
        	if(dec != 0 && cen != 0)
            printf("um");
        }
        
        else if(uni == 2)
        {
            printf("dois");
        }
        
        else if(uni == 3)
        {
            printf("tres");
        }
        
        else if(uni == 4)
        {
            printf("quatro");
        }
        
        else if(uni == 5)
        {
            printf("cinco");
        }
        
        else if(uni == 6)
        {
            printf("seis");
        }
        
        else if(uni == 7)
        {
            printf("sete");
        }
        
        else if(uni == 8)
        {
            printf("oito");
        }
        
        else if(uni == 9)
        {
            printf("nove");
        }    
	}
	if(vuti2 !=0 )
	printf(" mil ");
    //MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL MIL 

    //casa das centenas, agora como valor de tanto vuti quanto vuti2 subtraido

    temp = b - vuti - vuti2;
    cen = temp / 100;
    cen = cen * 100;
    dec = (temp - cen) / 10;
    dec = dec * 10;
    uni = temp - cen - dec;
    temp2 = dec + uni;
    
    if(vuti != 0 || vuti2 != 0)
	{
        if(((cen == 0 || (dec == 0 && uni ==0)) || (cen == 0 && dec == 0)) && ((cen != 0 || dec != 0) || uni != 0))printf("e "); // "e" similar que foi comentado anteriormente
    }
    
    if((cen >= 100 && cen <=900))
    {
        if(cen == 100)
        {
        	if(uni == 0 && dec == 0)
        	printf("cem");
        	else
            printf("cento");
        }
        
        else if(cen == 200)
        {
            printf("duzentos");
        }
        
        else if(cen == 300)
        {
            printf("trezentos");
        }
        
        else if(cen == 400)
        {
            printf("quatrocentos");
        }
        
        else if(cen == 500)
        {
            printf("quinhentos");
        }
        
        else if(cen == 600)
        {
            printf("seiscentos");
        }
        
        else if(cen == 700)
        {
            printf("setecentos");
        }
        
        else if(cen == 800)
        {
            printf("oitocentos");
        }
        
        else if(cen == 900)
        {
            printf("novecentos");
        }
        
        if(dec != 0 || uni != 0)
    	{
    	printf(" e ");
		}
	}
    if (dec >= 10 && dec <=90)
	{
        if(dec == 10)
        {
        	if(temp2 == 10) printf("dez");
        	if(temp2 == 11) printf("onze");
        	if(temp2 == 12) printf("doze");
        	if(temp2 == 13) printf("treze");
        	if(temp2 == 14) printf("quatorze");
        	if(temp2 == 15) printf("quinze");
        	if(temp2 == 16) printf("dezesseis");
        	if(temp2 == 17) printf("dezessete");
        	if(temp2 == 18) printf("dezoito");
        	if(temp2 == 19) printf("dezenove");
        }
        
        else if(dec == 20)
        {
            printf("vinte");
        }
        
        else if(dec == 30)
        {
            printf("trinta");
        }
        
        else if(dec == 40)
        {
            printf("quarenta");
        }
        
        else if(dec == 50)
        {
            printf("cinquenta");
        }
        
        else if(dec == 60)
        {
            printf("sessenta");
        }
        
        else if(dec == 70)
        {
            printf("setenta");
        }
        
        else if(dec == 80)
        {
            printf("oitenta");
        }
        
        else if(dec == 90)
        {
            printf("noventa");
        }
    }
    
    if((uni != 0 && dec != 0) && (temp2 < 10 || temp2 > 19))
    {
    	printf(" e ");
	}
	
    if((uni >= 0 && uni <=9) && (temp2 < 10 || temp2 > 19))
    {
        if(uni == 1)
        {
            printf("um");
        }
        
        else if(uni == 2)
        {
            printf("dois");
        }
        
        else if(uni == 3)
        {
            printf("tres");
        }
        
        else if(uni == 4)
        {
            printf("quatro");
        }
        
        else if(uni == 5)
        {
            printf("cinco");
        }
        
        else if(uni == 6)
        {
            printf("seis");
        }
        
        else if(uni == 7)
        {
            printf("sete");
        }
        
        else if(uni == 8)
        {
            printf("oito");
        }
        
        else if(uni == 9)
        {
            printf("nove");
        }    
    }
    if(vuti != 0 && b % 1000000 == 0)printf(" de"); // caso necessario para quando so ha casas nos milhoes (mil bits - um milhao "de" bits)
    printf(" Bits e ");
    
    //AQUI ACABAM AS NOTAS INTEIRAS, NAO CENTAVOS

    //aqui tem a parte dos centavos, que segue o modelo das anteriores porem mais curta (por lidar apenas com dezenas e unidades)

    temp = lround(cents); //cents eh a variavel que estava guardando a quantidade de centavos enquanto temp era usada nas outras seccoes
    dec = (int)temp / 10;
    dec = dec * 10;
    uni = (int)temp - dec;
    
    if (dec >= 10 && dec <=90)
	{
        if(dec == 10)
        {
        	if(temp == 10) printf("dez");
        	if(temp == 11) printf("onze");
        	if(temp == 12) printf("doze");
        	if(temp == 13) printf("treze");
        	if(temp == 14) printf("quatorze");
        	if(temp == 15) printf("quinze");
        	if(temp == 16) printf("dezesseis");
        	if(temp == 17) printf("dezessete");
        	if(temp == 18) printf("dezoito");
        	if(temp == 19) printf("dezenove");
        }
        
        else if(dec == 20)
        {
            printf("vinte");
        }
        
        else if(dec == 30)
        {
            printf("trinta");
        }
        
        else if(dec == 40)
        {
            printf("quarenta");
        }
        
        else if(dec == 50)
        {
            printf("cinquenta");
        }
        
        else if(dec == 60)
        {
            printf("sessenta");
        }
        
        else if(dec == 70)
        {
            printf("setenta");
        }
        
        else if(dec == 80)
        {
            printf("oitenta");
        }
        
        else if(dec == 90)
        {
            printf("noventa");
        }
    }
    
    if((uni != 0 && dec != 0) && (temp < 10 || temp > 19))
    {
    	printf(" e ");
	}
	
	else if(uni ==0 && dec == 0) //caso para quando nao ha centavos no valor
	{
		printf("zero");
	}
	
    if((uni >= 0 && uni <=9) && (temp < 10 || temp > 19))
    {
        if(uni == 1)
        {
            printf("um");
        }
        
        else if(uni == 2)
        {
            printf("dois");
        }
        
        else if(uni == 3)
        {
            printf("tres");
        }
        
        else if(uni == 4)
        {
            printf("quatro");
        }
        
        else if(uni == 5)
        {
            printf("cinco");
        }
        
        else if(uni == 6)
        {
            printf("seis");
        }
        
        else if(uni == 7)
        {
            printf("sete");
        }
        
        else if(uni == 8)
        {
            printf("oito");
        }
        
        else if(uni == 9)
        {
            printf("nove");
        }    
    }
    printf(" CentBits\n\n");
    
    tempo(); //para finalizar o cheque, puxamos a data que foi feita na funcao tempo e terminamos com uma repeticao de linhas para marcar a borda inferior do cheque
   
    for(i = 0; i <= 80; i++)
    {
    	printf("-");
	}
	
	printf("\n");
}

int menu () //funcao utilizada para introduzir um menu de opcoes. 
{
    //Criacao de um menu de "flechas".
	system("cls");
	int position = 1;
	int keyPressed = 0;
	
	#define MAX 3
	#define MIN 1
	
    //o getchar capta quando clicamos em uma das setas, caso cliquemos na de "cima" ele, subtrai da variavel posicao, quando clicamos na de "baixo", ele soma a varivel posicao.
    //a variavel position eh a resposavel pela posicao da flecha sendo que essa posicao varia de 1 a 3.
	while (keyPressed != 13)
	{
		system("cls");
		
		printf("Como posso te ajudar?\n\n");
	
		arrowHere(1, position); printf("|1| Saque\n\n");
		arrowHere(2, position); printf("|2| Preenchimento de cheque\n\n");
		arrowHere(3, position); printf("|3| SAIR\n");
		
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

int main () //funcao principal que utiliza todas as outras.
{
	int r1, position, X, cont;
	float a;
	
	system("color F0");
	printf ("Ola, seja bem vindo ao Banco Nacional de Weblands!\n\n");

    //cont que veio do "return" la da funcao "senha".
	cont = senha();

	if(cont == 3)
	{
		return 0;
	}
        /*Criamos aqui um ponto de reprocessamento para uso de goto, que foi escolhido para isso para que fosse possivel voltar ao menu principal
        do programa a partir de pontos diferentes, sem que fosse necessaria a utilizacao de varias cadeias de do while terminando em pontos diferentes.
        o goto foi utilizado nesse programa unica e exclusivamente para isso para que nao houvesse risco de desestruturacao do programa*/
		REPROCESSAMENTO:

        //chamamos a funcao "menu" e o valor de seu "return".
		position = menu();
		
        //caso a pessoa escolha a opcao 1.
		if (position == 1)
		{
			system("cls");
			printf("Informe a quantidade de B$ desejada para o saque: ");
			scanf("%f", &a);
			system("cls");
            //chamamos a funcao "cedulas, que faz a separacao do dinheiro".
			cedulas(a);
            //system pause para que o programa nao continuasse e apagasse as informacoes anteriores.
			system("pause");
			
            //reprocessamento com precaucao de erro, para caso o usuario deseje retornar ao menu.
			do
			{
				system("cls");
				printf("Deseja retornar ao menu?\n\n");
				printf("Sim[1]\n");
				printf("Nao[2]\n");
				printf("Resposta: ");
				scanf("%d", &r1);
			}while(r1!= 1 && r1 != 2);
			
            //caso ele queira, utilizamos o go to para retornar aquele ponto ja¡ mencionado anteriormente.
			if(r1 == 1)
			{
				goto REPROCESSAMENTO;
			}
		}

        //caso escolha a opcao 2.
		else if(position == 2)
		{
			do
			{
                //chamamos a funcao "preenche", que eh a responsavel por preecnher o cheque, escrevendo seus numeros por extenso e coloca a data.
				preenche();
                //reporcessamento para caso o usuario deseje refazer o cheque.
                //caso o usuario erre o programa refaz a pergunta.
				do
				{
					printf("O valor do cheque esta correto?\n\n");
					printf("Sim[1]\n");
					printf("Nao[2]\n");
					printf("Resposta: ");
					scanf("%d", &r1);
				}while(r1 != 1 && r1 != 2);
			}while(r1 != 1);
			
            //caso o usuario responda que o cheque esta correto, confirmamos a sua escolha.
			system("cls");
			printf("Cheque impresso!\n");
			system("pause");
			
            //reprocessamento para caso o usuario queira retornar ao menu.
            //caso o usuario erre o programa refaz a pergunta.
			do
			{
				system("cls");
				printf("Deseja retornar ao menu?\n\n");
				printf("Sim[1]\n");
				printf("Nao[2]\n");
				printf("Resposta: ");
				scanf("%d", &r1);	
			}while(r1!= 1 && r1 != 2);
			
            //caso ele queira, utilizamos o go to para retornar aquele ponto ja mencionado anteriormente.
			if(r1 == 1)
			{
				goto REPROCESSAMENTO;
			}
		}
    return 0;
}
