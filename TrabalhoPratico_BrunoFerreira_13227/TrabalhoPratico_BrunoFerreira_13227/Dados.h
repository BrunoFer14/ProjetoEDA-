/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 2 
*/

#ifndef Global
#define Global

#define MAX 9

#include <stdbool.h>
#include <stdlib.h>

//#define N 50  para descricao de maquina e operacao


#pragma region Estruturas

 //Estruturas:

typedef struct Maquina {
	int id;              // cada maquina tem um id unico que a diferencia das outras
	int tempoTarefa;
    struct Maquina* next;
}Maquina;

typedef struct Operacao {     
	int id;                // cada operacao tem um id unico que a diferencia das outras
	Maquina* listaMaquinas;    
	struct Operacao* next;
}Operacao;

typedef struct Job {
	char* id;
	Operacao* listaOperacoes;
	struct Job* next;
}Job;


#pragma endregion

#pragma region AssinaturasFuncoes

#pragma region FuncoesListasMaquinas
/*Funcoes Maquinas*/
Maquina* CriarMaquina(int id, int tempoTarefa);
Maquina* InserirMaquinaLista(Maquina* header, Maquina* novaMaquina);
Operacao* InserirMaquinaNaOperacao(Operacao* headerListaOperacao, int id, Maquina* maq);
#pragma endregion

#pragma region FuncoesComListasOperacoes
/*Funcoes Listas Operacoes*/
Operacao* CriarOperacao(int id);
Operacao* InserirOperacaoListaOrdenadamente(Operacao* headerListaOperacao, Operacao* novaOperacao);
Operacao* RemoverOperacao(Operacao* headerListaOperacao, int idOperacaoRemover);
bool ExisteOperacao(Operacao* headerListaOperacao, int id);
Operacao* ProcuraOperacao(Operacao* headerListaOperacao, int id);
Operacao* AlterarIdOperacao(Operacao* headerListaOperacao, int id, int novoID);
#pragma endregion

#pragma region CalculosNasOperacoes
/*Calculo de operacoes*/
int TempoMinimoOperacao(Maquina* listaMaquinas);
int TempoMaximoOperacao(Maquina* listaMaquinas);
int SomaMenorValorOperacoes(Operacao* headerListaOperacoes);
int SomaMaiorValorOperacoes(Operacao* headerListaOperacoes);
int ContarMaquinasOperacao(Operacao* operacao);
float MediaTempoOperacao(Operacao* listaOperacoesHeader, int id);
#pragma endregion

#pragma region FuncoesNosJobs
Job* CriarJob(char* id);
Job* InserirJob(Job* headerListaJob, Job* novoJob);
Job* ProcurarJob(char* id, Job* headerJob);
Job* InserirNodeJob(Job* node, Job* jobsHeader);

#pragma endregion

#pragma region FuncoesDeHash
void InicializarHashTable(Job* hashTable[]);
int Chave(char* id);
Job** InserirJobHashTable(Job* job, Job* hashTable[]);
Job* ProcurarJobNaHash(char* id, Job* hashTable[]);
void RemoverJobDaHashtable(char* id, Job* hashTable[]);


#pragma endregion

#pragma region FuncoesMostrarEcra
/*------Funcoes Mostrar ecra---------*/
//Operacoes
void MostrarListaOperacao(Operacao* headerDaLista);
void MostraOperacao(Operacao* operacao);

//Maquinas
void MostrarListaMaquinas(Maquina* headerDaLista);
void MostrarMaquina(Maquina* listaMaquinas);

//Jobs
void MostrarListaDeJobs(Job* headerJobs);

//HashTable
void MostrarHashTable(Job* hashTable[]);
#pragma endregion

#pragma region GravarFicheiros
bool GravarEmBinarioJobs(Job* hashTable[]);
bool GravarJob(Job* headerJob);
bool GravarOperacoes(Operacao* headerListaOperacao);
bool GravarMaquinas(Maquina* headerListaMaquinas);

#pragma endregion

#endif 
#pragma endregion
