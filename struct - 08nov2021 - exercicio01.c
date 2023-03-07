/*
1. Escreva um trecho de código para fazer a criação dos novos tipos de dados
conforme solicitado abaixo:
• Horário: composto de hora, minutos e segundos.
• Data: composto de dia, mês e ano.
• Compromisso: composto de uma data, horário e texto que descreve o
compromisso. 
*/
struct
{
	int hora;
	int min;
	int seg;
} typedef horario;

struct 
{
	int dia;
	int mes;
	int ano;
}typedef data;

struct
{
	horario h;
	data d;
	char descricao[200];
}typedef compromisso;

int main()
{
	return 0;
}