/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 2
*/

#include"Dados.h"
#include<stdio.h>
#include<string.h>


/**
 * Inicializa hashtable.
 * 
 * \param hashTable
 */
void InicializarHashTable(Job* hashTable[]) {
	for (int i = 0; i < MAX; i++) {
		hashTable[i] = NULL; // por todas as casas do array a nulo
	}
}
/**
 * Determina a chave para inserir na hashtable.
 * 
 * \param id
 * \return retorna a chave (posicao)
 */
int Chave(char*id) {
	int soma = 0;
	for (int i = 0; i < strlen(id); i++)
	{
		soma += (int)id[i];
	} return soma % MAX;
}

/**
 * Inserir um job na hashtable.
 * 
 * \param job
 * \param hashTable
 * \return hashtable
 */
Job** InserirJobHashTable(Job* job, Job* hashTable[]) {
	int posicao = Chave(job->id);
	/*job->next = hashTable[posicao];
	hashTable[posicao] = job;*/
	Job* header = hashTable[posicao];
	if (header == NULL)
		hashTable[posicao] = job;
	else
	{

		hashTable[posicao] = InserirJob(hashTable[posicao], job);
	}
	return *hashTable;
}

/**
 * Mostra a hashtable na consola.
 * 
 * \param hashTable
 */
void MostrarHashTable(Job* hashTable[]) {
	for (int i = 0; i < MAX; i++)
	{

		if (hashTable[i] != NULL) 
		{
			printf("Casa: %d\n", i);
			MostrarListaDeJobs(hashTable[i]);
			printf("\n");
		}
	}
}

/**
 * Procura job .
 * funcao seria para mais tarde usar nas outras funcoes 
 * \param id
 * \param hashTable
 * \return job encontrado
 */
Job* ProcurarJobNaHash(char* id, Job* hashTable[]) {
	int chave = Chave(id);
	if (hashTable[chave] == NULL) return NULL;

	return ProcurarJob(id, hashTable[chave]);
}

/**
 * Remove job da hashtable pelo id.
 * 
 * \param id
 * \param hashTable
 */
void RemoverJobDaHashtable(char* id, Job* hashTable[]) {
	int posicao = Chave(id);
	if (hashTable[posicao] == NULL)return;

	if (strcmp(hashTable[posicao]->id, id) == 0) {
		Job* auxJob = hashTable[posicao];
		hashTable[posicao] = hashTable[posicao]->next;
		free(auxJob);
		/*free(auxJob->listaOperacoes);
		free(auxJob->listaOperacoes->listaMaquinas);*/
	}
	else {
		Job* auxJob = hashTable[posicao];
		Job* auxJobAnt = auxJob;
		while (auxJob && strcmp(auxJob->id, id) > 0) {
			auxJobAnt = auxJob;
			auxJob = auxJob->next;
		}
		if (auxJob != NULL) {
			auxJobAnt->next = auxJob->next;
			free(auxJob);
			/*free(auxJob->listaOperacoes);
			free(auxJob->listaOperacoes->listaMaquinas);*/
		}
	}
}
/**
 * Grava a hashtable em ficheiro binario.
 * 
 * \param hashTable
 * \return 
 */
bool GravarEmBinarioJobs(Job* hashTable[]) 
{
	bool jobs, operacoes, maquinas = false;

	for (int i = 0; i < MAX; i++) {
		if (hashTable[i] != NULL) {
			jobs = GravarJob(hashTable[i]);
			operacoes = GravarOperacoes(hashTable[i]->listaOperacoes);
			maquinas = GravarMaquinas(hashTable[i]->listaOperacoes->listaMaquinas);
		}
	}
	return true;
}