/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 1 
*/

#ifndef Global
#define Global

#include <stdbool.h>
#include <stdlib.h>

//#define N 50  para descricao de maquina e operacao


#pragma region Estruturas

 //Estruturas

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

#pragma region FuncoesMostrarEcra
/*Funcoes Mostrar ecra*/
void MostrarListaOperacao(Operacao* headerDaLista);
void MostraOperacao(Operacao* operacao);
void MostrarListaMaquinas(Maquina* headerDaLista);
void MostrarMaquina(Maquina* listaMaquinas);
#pragma endregion

#pragma endregion


#endif 

