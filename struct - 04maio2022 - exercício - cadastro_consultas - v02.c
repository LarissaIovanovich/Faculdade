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
#include <locale.h>
#include <windows.h>

struct p{
	char codigopaciente[10];
  char nome[50];
  char telefone[20];
  int idade;
  char sexo;
}typedef paciente;

struct m{
  char codigomedico[10];
  char nome[50];
  char especialidade[50];
  float valorconsulta;
}typedef medico;

struct c{
  char codigopaciente[10];
  char codigomedico[10];
  char dataconsulta[9];
  char diadasemana[20];
}typedef consulta;

int qtdpac = 0;
int qtdmed = 0;
int qtdcon = 0;

int procura_pacientes(paciente *, char[]); 
/*função  procura_pacientes(pacientes[],char cod)
vetor do tipo paciente e codigo do paciente para busca
0 --> c�digo de paciente n�o existe
1 --> c�digo de paciente existe
*/
int procura_medicos(medico *, char[]);
/*fun��o procura_medicos(medico[],char cod)
vetor do tipo paciente e codigo do medico para busca
0 --> c�digo de medico n�o existe
1 --> c�digo de medico existe
*/
int procura_data(consulta *, char[], char[]);
/*fun��o procura_data(consulta[],char cod, char data)
vetor do tipo consulta, c�digo do m�dico e data da consulta
0 --> n�o h� data dispon�vel para a consulta
1 --> h� data dispon�vel para consulta 
*/
int cadastra_pacientes(paciente *);
/*
vetor do tipo paciente
0 --> os dados do paciente foram cadastrados
1 --> os ados do paciente n�o foram cadastrados
*/
int cadastra_medicos(medico *);
/*
vetor do tipo medico
0 --> os dados do m�dico foram cadastrados
1 --> os dados do m�dico n�o foram cadastrados
*/
int cadastra_consultas(medico *, paciente *, consulta *);
/*
vetor do tipo medico, vetor do tipo paciente e vetor do tipo consulta
0 --> os dados da consulta foram cadastrados
1 --> o c�digo do medico n�o existe
2 --> n�o h� data dispon�vel para esta consulta
3 --> codigo de paciente nao existe
*/
void relatorio_medicos(medico *);
/*
vetor do tipo medico
*/
void relatorio_pacientes(paciente *);
/*
vetor do tipo paciente
*/
void relatorio_consultas(medico *, paciente *, consulta*);
/*
vetor do tipo medico, vetor do tipo paciente e vetor do tipo consulta
*/
void dia_da_semana(char[], char[]);
/*
data da consulta - string no formato DDMMAAAA e
dia da semana - domingo, segunda-feira, ..., s�bado

Apenas o primeiro par�metro � informado quando a fun��o � chamada. 
O segundo par�metro conter� a resposta calculada pela fun��o.

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

paciente * aloca_vetor_paciente(int);
medico * aloca_vetor_medico(int);
consulta * aloca_vetor_consulta(int);
paciente * realocar_memoria_paciente(paciente *, int);
medico * realocar_memoria_medico(medico *, int);
consulta * realocar_memoria_consulta(consulta *, int);
paciente * liberar_memoria_paciente(paciente *);
medico * liberar_memoria_medico(medico *);
consulta * liberar_memoria_consulta(consulta *);

int main(){		
//**Define o valor das páginas de código UTF8 e default do Windows**
	UINT CPAGE_UTF8 = 65001;
	UINT CPAGE_DEFAULT = GetConsoleOutputCP();
//**Define codificação como sendo UTF-8**
	SetConsoleOutputCP(CPAGE_UTF8);
	
	paciente *pac;
	medico *med;
	consulta *con;	
	int op;
	
	pac = aloca_vetor_paciente(3);
	med = aloca_vetor_medico(3);
	con = aloca_vetor_consulta(3);
	
	do{
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
		switch(op){
			case 1:
				if(qtdmed % 3 == 0) {
					med = realloc(med,(qtdmed + 3) * sizeof(medico));
				}
				if(cadastra_medicos(med) == 1){
					printf("\nERRO ao cadastrar médico. Verifique o código\n");
		      		printf("\n");
	        		system("pause");	 	
				}
				break;
			case 2:
				if(qtdpac % 3 == 0) {
					pac = realloc(pac,(qtdpac + 3) * sizeof(paciente));
				}
				if(cadastra_pacientes(pac) == 1){
	 	      		printf("\nERRO ao cadastrar paciente. Verifique o código\n");
		      		printf("\n");
	        		system("pause");	 					
				}
				break;
			case 3:
				if(qtdcon % 3 == 0) {
					con = realloc(con,(qtdcon + 3) * sizeof(consulta));
				} 
				switch(cadastra_consultas(med,pac,con)){
				  case 1:
		 	      	printf("\nERRO ao cadastrar consulta. Verifique o código do médico\n");
	        		printf("\n");
	          		system("pause");   			  	
					break;
				  case 2:  	
				  	printf("\nERRO ao cadastrar consulta. Verifique se há data disponível para o médico\n");
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
        		relatorio_medicos(med);
				break;				
			case 5:
        		relatorio_pacientes(pac);
				break;	
			case 6:
        		relatorio_consultas(med,pac,con);
				break;					
		}
		system("cls");		
	}while(op != 7);
	
	pac = liberar_memoria_paciente(pac);
	med = liberar_memoria_medico(med);
	con = liberar_memoria_consulta(con);

//**Retorna codificação padrão do Windows**
	SetConsoleOutputCP(CPAGE_DEFAULT);
		
	return 0;	
}

//return 0 --> codigo de paciente nao existe
//return 1 --> codigo de paciente existe 
int procura_pacientes(paciente *p, char cod[]){
	int i = 0;
	
  while (i < qtdpac){
    if (strcmp(p->codigopaciente, cod) == 0)
      return 1;
    i = i + 1;
    p = p + 1;   //incrementa endereço de memoria de p
   }
   return 0;   
}

//return 0 --> c�digo de m�dico n�o existe
//return 1 --> codigo de medico existe 
int procura_medicos(medico *m, char cod[]){
	int i = 0;
	
  while (i < qtdmed){
    if (strcmp(m->codigomedico, cod) == 0)
      return 1;   
    i = i + 1;
    m = m + 1;
   }
   return 0;   
}

//return 0 --> n�o h� data dispon�vel para a consulta
//return 1 --> h� data dispon�vel para consulta 
int procura_data(consulta *c, char cod[], char dat[]){
	int i = 0, medico = 0;
	
//conta a quantidade de consultas de um m�dico em uma determina data
	while(i < qtdcon){
	  if((strcmp(c->codigomedico, cod) ==0) && (strcmp(c->dataconsulta, dat) == 0))
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
//return 1 --> os dados do paciente n�o foram cadastrados
int cadastra_pacientes(paciente *p){
	 char cod[10];
	 
	 printf("\nInforme o código do paciente: ");
	 fflush(stdin);
	 gets(cod);                              //quando a fun��o procura_pacientes retorna 0
	 if(procura_pacientes(p, cod) == 0){      //o c�digo do paciente n�o existe, podendo ser
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
	 else{
     return 1;
	 }
 } 

//return 0 --> os dados do m�dico foram cadastrados
//return 1 --> os dados do m�dico n�o foram cadastrados
int cadastra_medicos(medico *m){
	 char cod[10];
	 
	 printf("\nInforme o código do médico: ");
	 fflush(stdin);
	 gets(cod);                            //quando a fun��o procura_medicos retorna 0
	 if(procura_medicos(m, cod) == 0){      //o c�digo do m�dico n�o existe, podendo ser
	   strcpy(m[qtdmed].codigomedico,cod); //cadastrado
	   printf("\nInforme o nome do médico: ");
	   fflush(stdin);
	   gets(m[qtdmed].nome);
	   printf("\nInforme a especialidade do médico: ");
	   fflush(stdin);
	   gets(m[qtdmed].especialidade);
     printf("\nInforme o valor da consulta do médico: ");
     scanf("%f",&m[qtdmed].valorconsulta);
	   qtdmed = qtdmed + 1;
	   return 0;
	 }
	 else{
     return 1;
	 }
} 

//return 0 --> os dados da consulta foram cadastrados
//return 1 --> o c�digo do medico n�o existe
//return 2 --> n�o h� data dispon�vel para esta consulta
//return 3 --> codigo de paciente nao existe
int cadastra_consultas(medico *m, paciente *p, consulta *c){
	 char codm[10], codp[10], dat[9], ds[15];
	 
	 printf("\nInforme o codigo do médico: ");
	 fflush(stdin);
	 gets(codm);
	 if(procura_medicos(m, codm) == 1){ //m�dico existe, consulta pode ser cadastrada
	   printf("\nInforme a data da consulta: ");
	   fflush(stdin);
	   gets(dat);
	   if(procura_data(c, codm, dat) == 1){ //h� data dispon�vel para o m�dico, consulta pode ser cadastrada
	   	  printf("\nInforme o código do paciente: ");
	   	  fflush(stdin);
	   	  gets(codp);
	   	  if(procura_pacientes(p, codp) == 1){ //paciente existe, consulta pode ser cadastrada
	   	  	 strcpy(c[qtdcon].codigopaciente,codp);
	   	  	 strcpy(c[qtdcon].codigomedico,codm);
	   	  	 strcpy(c[qtdcon].dataconsulta,dat);
	   	  	 dia_da_semana(dat,ds);
					 strcpy(c[qtdcon].diadasemana,ds);
	         qtdcon = qtdcon + 1;
	        return 0; //os dados da consulta foram cadastrados
			 }	
			 else{
			 	 return 3; //os dados n�o foram cadastrados, o c�digo do paciente n�o existe
			 }
	   }
	   else{
			 return 2; //os dados n�o foram cadastrados, n�o h� data dispon�vel para o m�dico
		 }
	 }
	 else{  
		 return 1; //os dados n�o foram cadastrados, o c�digo do m�dico n�o existe
	 }
} 
 
void relatorio_medicos(medico *med){
	int i;
	
	printf("Relatório de Médicos\n");
	printf("--------------------\n");
	for(i = 0;i < qtdmed; i = i + 1){
		printf("\nCódigo ---------> %s",med->codigomedico);
		printf("\nNome  ----------> %s",med->nome);
		printf("\nEspecialidade --> %s",med->especialidade);
		printf("\nValor Consulta -> %2.2f",med->valorconsulta);
		printf("\n-----------------------------------------------");
		med = med + 1;
	}
	printf("\n");
	system("pause");
}

void relatorio_pacientes(paciente *pac){
	int i;
	
	printf("Relatório de Pacientes\n");
	printf("----------------------\n");
	for(i = 0;i < qtdpac; i = i + 1){
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
	
void relatorio_consultas(medico *med, paciente *pac, consulta *con){
	int i, j, dia, mes, ano;
	char valor[] = "\0\0\0\0";
	consulta *conCopia;
	
	printf("Relatório de Consultas\n");
	printf("----------------------\n");
	
	conCopia = con;
	for(i = 0;i < qtdcon; i = i + 1){
		for(j = 0;j < qtdmed;j = j + 1) {
			if(strcmp(conCopia->codigomedico, med->codigomedico) == 0){
		    	printf("\nMédico ------------> %s",med->nome);
		    	conCopia = conCopia + 1;
		    	med = med + 1;
		    }
		}
		conCopia = con;
		for(j = 0;j < qtdpac;j = j + 1)	{
			if(strcmp(conCopia->codigopaciente, pac->codigopaciente) == 0){
		    	printf("\nPaciente ----------> %s",pac->nome);
				conCopia = conCopia + 1;
				pac = pac + 1;
			}
		}
		conCopia = con;
		printf("\nData da consulta --> %s - ",conCopia->diadasemana);
    	dia = atoi(strncpy(valor, &conCopia->dataconsulta[0], 2));
   		mes = atoi(strncpy(valor, &conCopia->dataconsulta[2], 2));
    	ano = atoi(strncpy(valor, &conCopia->dataconsulta[4], 4));	  
		  		  
		printf("%d/%d/%d",dia,mes,ano);
		printf("\n-----------------------------------------------");	
 }
	printf("\n");
	system("pause"); 
}
  
//o par�matros dias[] � um ponteiro para char[] 
//que conter� o dia da semana ao final da fun��o 
void dia_da_semana(char dt[], char dias[]){
  int d, m, a, n, g, f, delta, ds;
  float resto;
  char valor[]="\0\0\0\0";
  
  d = atoi(strncpy(valor, &dt[0], 2));
  m = atoi(strncpy(valor, &dt[2], 2));
  a = atoi(strncpy(valor, &dt[4], 4));
	
  if (m <= 2){
	  g = a - 1;
	  f = m + 13;
    }
    else{
	    g = a;
		  f = m + 1;	
	  }
	  
  n = (int)(365.25 * g) + (int)(30.6 * f) - 621049 + d;	  
  
  if (n < 36523)
  	delta = 2;
    else
	    if (n < 73048)
	   	  delta = 1;
          else 
         	  delta = 0;
	 
  resto = (n / 7.0) - trunc(n/ 7.0); 
  if (((resto * 7) - trunc(resto * 7)) > 0.5)  
  	 ds = trunc(resto * 7) + 1 + delta + 1;
     else
       ds = trunc(resto * 7) + delta + 1;
  
	switch (ds){
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

paciente * aloca_vetor_paciente(int qtd)
{
	paciente *pac;
	int i;
	if(malloc(qtd*sizeof(paciente)) == NULL)
		{
			printf("\nErro ao alocar memória para o vetor\n");
			exit(0);
		}
	pac = malloc(qtd*sizeof(paciente));
	return pac;
}

medico * aloca_vetor_medico(int qtd)
{
	medico *med;
	int i;
	if(malloc(qtd*sizeof(medico)) == NULL)
		{
			printf("\nErro ao alocar memória para o vetor\n");
			exit(0);
		}
	med = malloc(qtd*sizeof(medico));
	return med;
}

consulta * aloca_vetor_consulta(int qtd)
{
	consulta *con;
	int i;
	if(malloc(qtd*sizeof(consulta)) == NULL)
		{
			printf("\nErro ao alocar memória para o vetor\n");
			exit(0);
		}
	con = malloc(qtd*sizeof(consulta));
	return con;
}

paciente * realocar_memoria_paciente(paciente *pac, int q)
{
	if(realloc(pac, q * sizeof(paciente))	== NULL)
		{
			printf("\nNão há memória suficiente\n");
			exit(0);
		}
	pac = realloc(pac, q * sizeof(paciente));
	return pac;
}

medico * realocar_memoria_medico(medico *med, int q)
{
	if(realloc(med, q * sizeof(medico))	== NULL)
		{
			printf("\nNão há memória suficiente\n");
			exit(0);
		}
	med = realloc(med, q * sizeof(medico));
	return med;
}

consulta * realocar_memoria_consulta(consulta *con, int q)
{
	if(realloc(con, q * sizeof(consulta))	== NULL)
		{
			printf("\nNão há memória suficiente\n");
			exit(0);
		}
	con = realloc(con, q * sizeof(consulta));
	return con;
}

paciente * liberar_memoria_paciente(paciente *pac)
{
	free(pac);
	return NULL;
}

medico * liberar_memoria_medico(medico *med)
{
	free(med);
	return NULL;
}

consulta * liberar_memoria_consulta(consulta *con)
{
	free(con);
	return NULL;
}