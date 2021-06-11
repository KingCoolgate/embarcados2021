#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

#define MAX_FLOW_SIZE 1000

typedef struct
{
	char nome[MAX_FLOW_SIZE];
	int nro;
	float N1, N2, media;
} T_aluno;

char chk[] = "sim", nome[] = " Nome : ", nro[] = ".\n Nro USP : ", N1[] = ".\n Nota da P1 : ", N2[] = ".\n Nota da P2 : ", media[] = ".\n Media dele : ", pula[] = "\n" ;

int flag = 0, a = 0, r = 0, i, b=0;
int turma, peso1, peso2, medaprov;

void infoturma()
{
	printf ("\n -----DIGITE AS INFORMACOES DA TURMA----- \n");
	printf("\n Digite o tamanho da Turma : ");
		scanf ("%d", &turma);
	printf(" Digite a media para aprovacao : ");
		scanf ("%d", &medaprov);
	printf(" Digite o peso da prova1 : ");
		scanf ("%d", &peso1);
	printf(" Digite o peso da prova2 : ");
		scanf ("%d", &peso2);

	while ( (peso1+peso2) <= 0 )
	{
		printf (" Pesos inválidos. \n");
		printf(" Digite o peso da prova1 novamente : ");
			scanf ("%d", &peso1);
		printf(" Digite o peso da prova2 novamente : ");
			scanf ("%d ^[\n]", &peso2);
	}
	printf ("\n***************************************************************************************************\n");
}

void nomealuno(T_aluno aluno[turma])
{
	//Pega as informações do aluno
		printf ("\n -----DIGITE AS INFORMACOES DO ALUNO----- \n");
			//Nome
				fflush(stdin);
					printf ("\n Digite o nome do aluno: ");
					while(b == 0)
					{
						gets ( aluno[flag].nome);
						fflush(stdin);

						if (strlen(aluno[flag].nome) != 0)
						{
							b = 1;
						}
					}
}

void infoaluno(T_aluno aluno[turma])
{
		//NroUSP
			printf (" Digite o numero USP do aluno : ");
				scanf ("%d", &aluno[flag].nro);

		//Nota da P1
			printf (" De o valor da P1 do aluno: ");
       			scanf  ("%f", &aluno[flag].N1);
				   while (( aluno[flag].N1 > 10 ) || ( aluno[flag].N1 < 0 ))
       			 	{
       			 		printf (" Nota invalida! Insira novamente : ");
						scanf ("%f", &aluno[flag].N1);
					}

		//Nota da P2
  			printf (" De o valor da P2 do aluno: ");
        		scanf  ("%f", &aluno[flag].N2);
					while (( aluno[flag].N2 > 10 ) || ( aluno[flag].N2 < 0 ))
					{
						printf (" Nota invalida, insira novamente : ");
						scanf ("%f", &aluno[flag].N2);
					}

			aluno[flag].media = ( (aluno[flag].N1*peso1) + (aluno[flag].N2)*peso2 )/(peso1+peso2) ;

		printf ("\n***************************************************************************************************\n");
}

void printaluno(T_aluno aluno[turma])
{
//Print dos alunos independente de aprovados ou não
	for( a = 0 ; a < turma ; a++ )
		{
			printf (" Nome : %s", aluno[a].nome);
			printf ("\n Numero USP :  %d\n", aluno[a].nro);
			printf (" Media : %.2f\n\n", aluno[a].media);
		}
}

void salvando(T_aluno aluno[turma])
{
	for (i = 0 ; i < turma ; i++ )
		{
//Abre o arquivo
		FILE *pf;
			if (( pf = fopen("teste.txt", "a" )) == NULL)
				{
					printf (" Erro na abertura do arquivo! ");
					exit (1);
				}

//Grava informações
			fputs(pula, pf);
				fputs (nome, pf);
					fputs (aluno[i].nome, pf);
				fputs (nro, pf);
					fprintf (pf, "%d", aluno[i].nro);
				fputs (N1, pf);
					fprintf (pf, "%.2f", aluno[i].N1);
				fputs (N2, pf);
					fprintf (pf, "%.2f", aluno[i].N2);
				fputs (media, pf);
					fprintf (pf, "%.2f.", aluno[i].media);
			fputs(pula, pf);
			fclose(pf);

		}
}

void chkaluno(T_aluno aluno[turma], T_aluno aprov[turma], T_aluno reprov[turma])
{
	a=0;
	r=0;
	for( i = 0 ; i < turma ; i++)
		{
//Checagem para ver se vai pra lista dos aprovados ou pro reprovados
			if (aluno[i].media >= medaprov)
				{
					strcpy ( aprov[a].nome, aluno[i].nome ) ;
					aprov[a].nro = aluno[i].nro ;
					aprov[a].media = aluno[i].media ;
					a++;
				}
			else
				{
					strcpy ( reprov[r].nome, aluno[i].nome ) ;
					reprov[r].nro = aluno[i].nro ;
					reprov[r].media = aluno[i].media ;
					r++;
				}
		}
}

void alunoaprov(T_aluno aprov[turma])
{
	printf ("\n***************************************************************************************************\n");
	i = a;
	printf (" O numero de alunos aprovados sao %d\n\n", a);
	for( a = 0 ; a < i ; a++ )
		{
			printf (" Nome : %s", aprov[a].nome);
			printf ("\n Numero USP :  %d\n", aprov[a].nro);
			printf (" Media : %.2f\n\n", aprov[a].media);
		}
}

void alunoreprov(T_aluno reprov[turma])
{
	printf ("\n***************************************************************************************************\n");
	i = r;
	printf (" O numero de alunos reprovados sao %d\n\n", r);
	for( r = 0 ; r < i ; r++ )
		{
			printf (" Nome : %s", reprov[r].nome);
			printf ("\n Numero USP :  %d\n", reprov[r].nro);
			printf (" Media : %.2f\n\n", reprov[r].media);
		}
}

int main ()
{
	printf (" Esse programa vai pegar dados da turma, dos alunos, salvar e verificar");

		infoturma();

	T_aluno aluno[turma], aprov[turma], reprov[turma];

		while (flag < turma)
			{
				b = 0;
				nomealuno(aluno);
				infoaluno(aluno);
				flag++;
			}

	printf("\n");
		printaluno(aluno);
	printf("\n");
		chkaluno(aluno, aprov, reprov);
	printf("\n");
		alunoaprov(aprov);
	printf("\n");
		alunoreprov(reprov);
	printf("\n");
		salvando(aluno);

	system ("PAUSE");
	return(0);
}
