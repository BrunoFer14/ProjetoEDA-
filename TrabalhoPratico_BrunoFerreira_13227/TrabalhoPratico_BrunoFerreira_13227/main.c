/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 2
*/

#include<stdio.h>
#include"Dados.h"



int main() 
{

#pragma region Fase1Testing
	/*
	
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
	printf("\nmedia : %f\n", media);
	printf("\nEstou aqui\n\n");*/

#pragma endregion

#pragma region Fase2HashTable

	//Declarar uma hashtable
	Job* hashTable[MAX];

#pragma region Job1
	//Criar job 1
	Job* job1 = CriarJob("1");

	//Respetivas Operacoes
	Operacao* operacao1 = CriarOperacao(1);
	Operacao* operacao2 = CriarOperacao(2);
	Operacao* operacao3 = CriarOperacao(3);
	

	//Respetivas Maquinas
	Maquina* maquina1 = CriarMaquina(1, 1);
	Maquina* maquina2 = CriarMaquina(2, 2);
	Maquina* maquina3 = CriarMaquina(3, 3);
	Maquina* maquina4 = CriarMaquina(4, 4);
	Maquina* maquina5 = CriarMaquina(1, 1);
	Maquina* maquina6 = CriarMaquina(2, 2);
	Maquina* maquina7 = CriarMaquina(4, 4);

	//Inserir maquinas na lista de maquinas das operacoes
	
	operacao1->listaMaquinas = InserirMaquinaLista(operacao1->listaMaquinas, maquina1);
	operacao2->listaMaquinas = InserirMaquinaLista(operacao2->listaMaquinas, maquina2);
	operacao2->listaMaquinas = InserirMaquinaLista(operacao2->listaMaquinas, maquina3);
	operacao3->listaMaquinas = InserirMaquinaLista(operacao3->listaMaquinas, maquina3);

	job1->listaOperacoes = InserirOperacaoListaOrdenadamente(job1->listaOperacoes, operacao1);
	job1->listaOperacoes = InserirOperacaoListaOrdenadamente(job1->listaOperacoes, operacao2);
	job1->listaOperacoes = InserirOperacaoListaOrdenadamente(job1->listaOperacoes, operacao3);

#pragma endregion

#pragma region Job2
	//Criar job 2
	Job* job2 = CriarJob("2");

	//Respetivas Operacoes
	Operacao* operacao4 = CriarOperacao(4);
	Operacao* operacao5 = CriarOperacao(5);
	Operacao* operacao6 = CriarOperacao(6);


	//Respetivas Maquinas
	Maquina* maquina8 = CriarMaquina(8, 8);
	Maquina* maquina9 = CriarMaquina(9, 9);
	Maquina* maquina10 = CriarMaquina(10, 10);
	Maquina* maquina11 = CriarMaquina(11, 11);
	Maquina* maquina12 = CriarMaquina(12, 12);
	
	job2->listaOperacoes = InserirOperacaoListaOrdenadamente(job2->listaOperacoes, operacao4);
	job2->listaOperacoes = InserirOperacaoListaOrdenadamente(job2->listaOperacoes, operacao5);
	job2->listaOperacoes = InserirOperacaoListaOrdenadamente(job2->listaOperacoes, operacao6);

	//Inserir maquinas na lista de maquinas das operacoes
	operacao4->listaMaquinas = InserirMaquinaLista(operacao4->listaMaquinas, maquina8);
	operacao5->listaMaquinas = InserirMaquinaLista(operacao5->listaMaquinas, maquina9);
	operacao6->listaMaquinas = InserirMaquinaLista(operacao6->listaMaquinas, maquina10);
	

#pragma endregion

#pragma region Job3
	//Criar job 3
	Job* job3 = CriarJob("3");

	//Respetivas Operacoes  já criadas


	//Respetivas Maquinas   já criadas

	job3->listaOperacoes = InserirOperacaoListaOrdenadamente(job3->listaOperacoes, operacao4);
	job3->listaOperacoes = InserirOperacaoListaOrdenadamente(job3->listaOperacoes, operacao5);
	job3->listaOperacoes = InserirOperacaoListaOrdenadamente(job3->listaOperacoes, operacao6);

#pragma endregion

	Job* job5 = CriarJob("16");

	InicializarHashTable(hashTable);
	InserirJobHashTable(job1, hashTable);
	InserirJobHashTable(job2, hashTable);
	InserirJobHashTable(job3, hashTable);
	InserirJobHashTable(job5, hashTable);
	MostrarHashTable(hashTable);

	//bool gravou= GravarEmBinarioJobs(hashTable);

    //Remover Operacao 
	printf("\n------------HashTable com Operacoes removidas --------------------\n");
	
	job3->listaOperacoes = RemoverOperacao(job3->listaOperacoes, 6);
	job1->listaOperacoes = RemoverOperacao(job1->listaOperacoes, 1);
	
	MostrarHashTable(hashTable);

	// Editar Operacao
	job1->listaOperacoes = AlterarIdOperacao(job1->listaOperacoes, 3, 1);
	printf("\n------------HashTable com Operacoes Alteradas --------------------\n");
	MostrarHashTable(hashTable);

	//Remover job da Hashtable
	RemoverJobDaHashtable("1", hashTable);
	printf("\n------------HashTable com Job 1 removido --------------------\n");
	MostrarHashTable(hashTable);


#pragma endregion

}