/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 1
*/

#include<stdio.h>
#include"Dados.h"



int main() 
{

	Operacao* listaOperacoes = NULL;     // lista de operacoes que corresponde a 1 job / process plan

	Operacao* operacao1 = CriarOperacao(1);
	Operacao* operacao2 = CriarOperacao(2);
	Operacao* operacao3 = CriarOperacao(3);

	Maquina* maquina1 = CriarMaquina(1, 5);
	Maquina* maquina2 = CriarMaquina(2, 3);
	Maquina* maquina3 = CriarMaquina(3, 1);
	listaOperacoes = InserirOperacaoListaOrdenadamente(listaOperacoes, operacao1);
	listaOperacoes = InserirOperacaoListaOrdenadamente(listaOperacoes, operacao2);
	listaOperacoes = InserirOperacaoListaOrdenadamente(listaOperacoes, operacao3);

	MostrarListaOperacao(listaOperacoes);
	printf("Apos inserir 3 operacoes\n\n");

	listaOperacoes = RemoverOperacao(listaOperacoes,3);
	MostrarListaOperacao(listaOperacoes);
	printf("Lista apos remocao da terceira operacao\n\n");

	listaOperacoes = AlterarIdOperacao(listaOperacoes, 2, 5);
	MostrarListaOperacao(listaOperacoes);
	printf("Lista apos alteracao do id da operacao 3 para 5\n\n");

	InserirMaquinaNaOperacao(listaOperacoes, 1, maquina1);
	InserirMaquinaNaOperacao(listaOperacoes, 1, maquina2);
	InserirMaquinaNaOperacao(listaOperacoes, 5, maquina3);
    MostrarListaOperacao(listaOperacoes);

	int somaMenor=SomaMenorValorOperacoes(listaOperacoes);
	int somaMaior = SomaMaiorValorOperacoes(listaOperacoes);
	
	printf("\nsoma menor valor : %d\n", somaMenor);
	printf("\nsoma maior valor : %d\n", somaMaior);
	
	float media= MediaTempoOperacao(listaOperacoes, 1);

	printf("media : %f\n", media);
	printf("Estou aqui\n\n");




	
	
	


	
	

}