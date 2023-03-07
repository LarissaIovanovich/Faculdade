/*
Uma clínica necessita controlar a agenda de seus médicos, registrando
seus pacientes e as consultas, de acordo com as estruturas a seguir:
-----------------------
		paciente
texto codigopaciente
texto nome
texto telefone
inteiro idade
texto sexo
-----------------------
		medico
texto codigomedico
texto nome
texto especialidade
real valorconsulta
-----------------------
		consulta
texto codigopaciente
texto codigomedico
texto dataconsulta
texto diadasemana
-----------------------
Escreva um programa para:
a)Cadastrar pacientes (não deve haver códigos repetidos para pacientes e os
  mesmos devem ser informados pelo usuário);
b)Cadastrar médicos (não deve haver códigos repetidos para médicos e os
  mesmos devem ser informados pelo usuário);
c)Cadastrar consultas (um médico não pode realizar mais de duas consultas na
  mesma data e uma consulta só pode ser cadastrada se o código do paciente
  e o código do médico existirem);
d)Mostrar um relatório com o nome do médico, sua especialidade e todos os
  pacientes que ele atendeu;

Cada um dos itens acima deve ser realizado em uma função.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <unistd.h>

struct p
{
	char codigopaciente[10];
	char nome[50];
	char telefone[20];
	int idade;
	char sexo;
} typedef paciente;

struct m
{
	char codigomedico[10];
	char nome[50];
	char especialidade[50];
	float valorconsulta;
} typedef medico;

struct c
{
	char codigopaciente[10];
	char codigomedico[10];
	char dataconsulta[9];
	char diadasemana[20];
} typedef consulta;

int qtdpac = 0;
int qtdmed = 0;
int qtdcon = 0;

void gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int procura_pacientes(paciente[], char[]);
/*função procura_pacientes(pacientes[],char cod)
vetor do tipo paciente e codigo do paciente para busca
0 --> código de paciente não existe
1 --> código de paciente existe
*/
int procura_medicos(medico[], char[]);
/*função procura_medicos(medico[],char cod)
vetor do tipo paciente e codigo do medico para busca
0 --> código de medico não existe
1 --> código de medico existe
*/
int procura_data(consulta[], char[], char[]);
/*função procura_data(consulta[],char cod, char data)
vetor do tipo consulta, código do médico e data da consulta
0 --> não há data disponível para a consulta
1 --> há data disponível para consulta
*/
int cadastra_pacientes(paciente[]);
/*
vetor do tipo paciente
0 --> os dados do paciente foram cadastrados
1 --> os dados do paciente não foram cadastrados
*/
int cadastra_medicos(medico[]);
/*
vetor do tipo medico
0 --> os dados do médico foram cadastrados
1 --> os dados do médico não foram cadastrados
*/
int cadastra_consultas(medico[],paciente[],consulta[]);
/*
vetor do tipo medico, vetor do tipo paciente e vetor do tipo consulta
0 --> os dados da consulta foram cadastrados
1 --> o código do medico não existe
2 --> não há data disponível para esta consulta
3 --> codigo de paciente nao existe
*/
void relatorio_medicos(medico[]);
/*
vetor do tipo medico
*/
void relatorio_pacientes(paciente[]);
/*
vetor do tipo paciente
*/
void relatorio_consultas(medico[],paciente[],consulta[]);
/*
vetor do tipo medico, vetor do tipo paciente e vetor do tipo consulta
*/
void dia_da_semana(char[], char[]);
/*
data da consulta - string no formato DDMMAAAA e
dia da semana - domingo, segunda-feira, ..., sábado

Apenas o primeiro parâmetro é informado quando a função é chamada.
O segundo parâmetro conterá a resposta calculada pela função.

char dat[9], ds[15];
...
  printf("\nInforme a data da consulta: ");
	fflush(stdin);
	gets(dat);
...
  dia_da_semana(dat,ds);
	printf("\nDia da semana -->  %s",ds);
...
*/

int main()
{
//**Define o valor das páginas de código UTF8 e default do Windows**
	UINT CPAGE_UTF8 = 65001;
	UINT CPAGE_DEFAULT = GetConsoleOutputCP();
//**Define codificação como sendo UTF-8**
	SetConsoleOutputCP(CPAGE_UTF8);

	paciente pac[10];
	medico med[10];
	consulta con[50];
	int op;

	do
		{
			printf("\nCadastro de Médicos, Pacientes e Consultas\n");
			printf("------------------------------------------");
			printf("\n1 - Cadastra Médico");
			printf("\n2 - Cadastra Paciente");
			printf("\n3 - Cadastra Consulta");
			printf("\n4 - Relatório de Médicos");
			printf("\n5 - Relatório de Pacientes");
			printf("\n6 - Relatório de Consultas");
			printf("\n7 - Encerrar");
			printf("\n--> ");
			scanf("%d",&op);
			switch(op)
				{
					case 1:
						if(cadastra_medicos(&med[0]) == 1)
							{
								printf("\nERRO ao cadastrar médico. Verifique o código\n");
								printf("\n");
								system("pause");
							}
						break;
					case 2:
						if(cadastra_pacientes(&pac[0]) == 1)
							{
								printf("\nERRO ao cadastrar paciente. Verifique o código\n");
								printf("\n");
								system("pause");
							}
						break;
					case 3:
						switch(cadastra_consultas(&med[0],&pac[0],&con[0]))
							{
								case 1:
									printf("\nERRO ao cadastrar consulta. Verifique o código do médico\n");
									printf("\n");
									system("pause");
									break;
								case 2:
									printf("\nERRO ao cadastrar consulta. Verifique se há data dispoível para o médico\n");
									printf("\n");
									system("pause");
									break;
								case 3:
									printf("\nERRO ao cadastrar consulta. Verifique o código do paciente\n");
									printf("\n");
									system("pause");
									break;
							}
						break;
					case 4:
						relatorio_medicos(&med[0]);
						break;
					case 5:
						relatorio_pacientes(&pac[0]);
						break;
					case 6:
						relatorio_consultas(&med[0],&pac[0],&con[0]);
						break;
				}
			system("cls");
		}
	while(op != 7);
//**Retorna codificação padrão do Windows**
	SetConsoleOutputCP(CPAGE_DEFAULT);
	return 0;
}

//return 0 --> código de paciente não existe
//return 1 --> codigo de paciente existe
int procura_pacientes(paciente *p, char cod[])
{
	int i = 0;

	while (i < qtdpac)
		{
			if (strcmp(p->codigopaciente,cod) == 0)
				return 1;
			i = i + 1;
			p = p + 1;
		}
	return 0;
}

//return 0 --> código de médico não existe
//return 1 --> codigo de medico existe
int procura_medicos(medico *m, char cod[])
{
	int i = 0;

	while (i < qtdmed)
		{
			if (strcmp(m->codigomedico,cod) == 0)
				return 1;
			i = i + 1;
			m = m + 1;
		}
	return 0;
}

//return 0 --> não há data disponível para a consulta
//return 1 --> há data disponível para consulta
int procura_data(consulta *c, char cod[], char dat[])
{
	int i = 0, medico = 0;

//conta a quantidade de consultas de um médico em uma determina data
	while(i < qtdcon)
		{
			if((strcmp(c->codigomedico,cod) ==0) && (strcmp(c->dataconsulta,dat) == 0))
				medico = medico + 1;
			i = i + 1;
			c = c + 1;
		}
	if(medico == 2)
		return 0;
	else
		return 1;
}

//return 0 --> os dados do paciente foram cadastrados
//return 1 --> os dados do paciente não foram cadastrados
int cadastra_pacientes(paciente p[])
{
	char cod[10];

	printf("\nInforme o codigo do paciente: ");
	fflush(stdin);
	gets(cod);                              //quando a função procura_pacientes retorna 0
	if(procura_pacientes(p,cod) == 0)       //o código do paciente não existe, podendo ser
		{
			strcpy(p[qtdpac].codigopaciente,cod); //cadastrado
			printf("\nInforme o nome do paciente: ");
			fflush(stdin);
			gets(p[qtdpac].nome);
			printf("\nInforme o telefone do paciente: ");
			fflush(stdin);
			gets(p[qtdpac].telefone);
			printf("\nInforme a idade do paciente: ");
			scanf("%d",&p[qtdpac].idade);
			printf("\nInforme 1 para Feminino ou 2 para Masculino: ");
			fflush(stdin);
			p[qtdpac].sexo = getchar();
			if (p[qtdpac].sexo == '1')
				p[qtdpac].sexo = 'F';
			else
				p[qtdpac].sexo = 'M';
			qtdpac = qtdpac + 1;
			return 0;
		}
	else
		{
			return 1;
		}
}

//return 0 --> os dados do médico foram cadastrados
//return 1 --> os dados do médico não foram cadastrados
int cadastra_medicos(medico m[])
{
	char cod[10];

	printf("\nInforme o codigo do medico: ");
	fflush(stdin);
	gets(cod);                            //quando a função procura_medicos retorna 0
	if(procura_medicos(m,cod) == 0)       //o código do médico não existe, podendo ser
		{
			strcpy(m[qtdmed].codigomedico,cod); //cadastrado
			printf("\nInforme o nome do medico: ");
			fflush(stdin);
			gets(m[qtdmed].nome);
			printf("\nInforme a especialidade do medico: ");
			fflush(stdin);
			gets(m[qtdmed].especialidade);
			printf("\nInforme o valor da consulta do medico: ");
			scanf("%f",&m[qtdmed].valorconsulta);
			qtdmed = qtdmed + 1;
			return 0;
		}
	else
		{
			return 1;
		}
}

//return 0 --> os dados da consulta foram cadastrados
//return 1 --> o código do medico não existe
//return 2 --> não há data disponível para esta consulta
//return 3 --> codigo de paciente nao existe
int cadastra_consultas(medico m[], paciente p[], consulta c[])
{
	char codm[10], codp[10], dat[9], ds[15];

  relatorio_medicos(&m[0]);
	
	gotoxy(01,11);	
	
	printf("\nInforme o codigo do medico: ");
	fflush(stdin);
	gets(codm);
	if(procura_medicos(m,codm) == 1)  //médico existe, consulta pode ser cadastrada
		{
			printf("\nInforme a data da consulta: ");
			fflush(stdin);
			gets(dat);
			if(procura_data(c,codm,dat) == 1)  //há data disponível para o médico, consulta pode ser cadastrada
				{
					printf("\nInforme o codigo do paciente: ");
					fflush(stdin);
					gets(codp);
					if(procura_pacientes(p,codp) == 1)  //paciente existe, consulta pode ser cadastrada
						{
							strcpy(c[qtdcon].codigopaciente,codp);
							strcpy(c[qtdcon].codigomedico,codm);
							strcpy(c[qtdcon].dataconsulta,dat);
							dia_da_semana(dat,ds);
							strcpy(c[qtdcon].diadasemana,ds);
							qtdcon = qtdcon + 1;
							return 0; //os dados da consulta foram cadastrados
						}
					else
						{
							return 3; //os dados não foram cadastrados, o código do paciente não existe
						}
				}
			else
				{
					return 2; //os dados não foram cadastrados, não há data disponível para o médico
				}
		}
	else
		{
			return 1; //os dados não foram cadastrados, o código do médico não existe
		}
}

void relatorio_medicos(medico *med)
{
	int i, linha;
  gotoxy(40,15);
	printf("Relatório de Médicos\n");
	gotoxy(40,16);
	printf("--------------------\n");
	for(i = 0; i < qtdmed; i = i + 1)
		{
			gotoxy(40,linha);
			printf("\nCódigo ---------> %s",med->codigomedico);
			linha = linha + 1;
			gotoxy(40,linha);
			printf("\nNome  ----------> %s",med->nome);
			linha = linha + 1;
			gotoxy(40,linha);
			printf("\nEspecialidade --> %s",med->especialidade);
			linha = linha + 1;
			gotoxy(40,linha);
			printf("\nValor Consulta -> %2.2f",med->valorconsulta);
			linha = linha + 1;
			gotoxy(40,linha);
			printf("\n-----------------------------------------------");
			linha = linha + 1;
			gotoxy(40,linha);
			med = med + 1;
		}
//	printf("\n");
//	system("pause");
}

void relatorio_pacientes(paciente *pac)
{
	int i;

	printf("Relatório de Pacientes\n");
	printf("----------------------\n");
	for(i = 0; i < qtdpac; i = i + 1)
		{
			printf("\nCódigo ---------> %s",pac->codigopaciente);
			printf("\nNome  ----------> %s",pac->nome);
			printf("\nIdade -----> %d",pac->idade);
			printf("\nSexo ------> %c",pac->sexo);
			printf("\nTelefone --> %s",pac->telefone);
			printf("\n-----------------------------------------------");
			pac = pac + 1;
		}
	printf("\n");
	system("pause");
}

void relatorio_consultas(medico med[],paciente pac[],consulta con[])
{
	int i, j, dia, mes, ano;
	char valor[] = "\0\0\0\0";

	printf("Relatório de Consultas\n");
	printf("----------------------\n");

	for(i = 0; i < qtdcon; i = i + 1)
		{
			for(j = 0; j < qtdmed; j = j + 1)
				if(strcmp(con[i].codigomedico,med[j].codigomedico) == 0)
					printf("\nMédico ------------> %s",med[j].nome);
			for(j = 0; j < qtdpac; j = j + 1)
				if(strcmp(con[i].codigopaciente,pac[j].codigopaciente) == 0)
					printf("\nPaciente ----------> %s",pac[j].nome);

			printf("\nData da consulta --> %s - ",con[i].diadasemana);

			dia = atoi(strncpy(valor, &con[i].dataconsulta[0], 2));
			mes = atoi(strncpy(valor, &con[i].dataconsulta[2], 2));
			ano = atoi(strncpy(valor, &con[i].dataconsulta[4], 4));

			printf("%d/%d/%d",dia,mes,ano);
			printf("\n-----------------------------------------------");
		}
	printf("\n");
	system("pause");
}

//o parâmatros dias[] é um ponteiro para char[]
//que conterá o dia da semana ao final da função
void dia_da_semana(char dt[], char dias[])
{
	int d, m, a, n, g, f, delta, ds;
	float resto;
	char valor[]="\0\0\0\0";

	d = atoi(strncpy(valor, &dt[0], 2));
	m = atoi(strncpy(valor, &dt[2], 2));
	a = atoi(strncpy(valor, &dt[4], 4));

	if (m <= 2)
		{
			g = a - 1;
			f = m + 13;
		}
	else
		{
			g = a;
			f = m + 1;
		}

	n = (int)(365.25 * g) + (int)(30.6 * f) - 621049 + d;

	if (n < 36523)
		delta = 2;
	else if (n < 73048)
		delta = 1;
	else
		delta = 0;

	resto = (n / 7.0) - trunc(n/ 7.0);
	if (((resto * 7) - trunc(resto * 7)) > 0.5)
		ds = trunc(resto * 7) + 1 + delta + 1;
	else
		ds = trunc(resto * 7) + delta + 1;

	switch (ds)
		{
			case 1:
				strcpy(dias,"Domingo");
				break;
			case 2:
				strcpy(dias,"Segunda-feira");
				break;
			case 3:
				strcpy(dias,"Terça-feira");
				break;
			case 4:
				strcpy(dias,"Quarta-feira");
				break;
			case 5:
				strcpy(dias,"Quinta-feira");
				break;
			case 6:
				strcpy(dias,"Sexta-feira");
				break;
			case 7:
				strcpy(dias,"Sábado");
				break;
		}
}