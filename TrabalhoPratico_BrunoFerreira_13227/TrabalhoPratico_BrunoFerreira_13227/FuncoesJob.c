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
#include<stdbool.h>
#include<stdlib.h>


#pragma region GestaoDeJobs
/**
 * .
 * Criar um job com um id
 * \param id 
 * \return novo job criado
 */
Job* CriarJob(char* id) {
	Job* novoJob = (Job*)malloc(sizeof(Job));

	if(novoJob == NULL) return NULL;  // se não houver memoria nao cria

    novoJob->id = id;
	novoJob->listaOperacoes = NULL;
	novoJob->next = NULL;

	return novoJob;
}

/**
 * .
 * Insere job na lista de jobs 
 * \param headerListaJob
 * \param novoJob
 * \return retorna o header da lista de jobs 
 */
Job* InserirJob(Job* headerListaJob, Job* novoJob) {
	if (headerListaJob == NULL) {
		headerListaJob = novoJob;
	}
	else {
		novoJob->next = headerListaJob;
		headerListaJob = novoJob;
	}
	return headerListaJob;
}
/**
 * .
 * Insere Job ordenadamente na lista
 * \param node
 * \param jobsHeader
 * \return Retorna o header da lista
 */
Job* InserirNodeJob(Job* node, Job* jobsHeader) {
    if (jobsHeader == NULL)
        jobsHeader = InserirJob(jobsHeader, node);
    else {
        printf("\n\n");
        Job* auxJob = jobsHeader;
        Job* auxJob2 = auxJob;

        while (auxJob != NULL && strcmp(auxJob->id, node->id) < 0) {
            auxJob2 = auxJob;
            auxJob = auxJob->next;
        }

        if (auxJob == jobsHeader) {
            jobsHeader = InserirJob(jobsHeader, node);
        }

        else {
            if (auxJob == NULL) {
                auxJob2->next = node;
            }
            else {
                auxJob2->next = node;
                node->next = auxJob;
            }
        }
    }
    return jobsHeader;
}
/**
 * .
 * Encontra o job por id 
 * \param id
 * \param headerJob
 * \return se encontrar o job retorna o mesmo, se nao encontrar retorna NULL
 */

Job* ProcurarJob(char* id, Job* headerJob) {
    if (!headerJob) return NULL;

    Job* auxJobs = headerJob;
    while (auxJobs != NULL && strcmp(auxJobs->id, id) != 0) auxJobs = auxJobs->next;
    return auxJobs;
}

/**
 * .
 * Mostra na consola a lista de jobs , operacoes associadas e maquinas associadas a cada operacao
 * \param headerJobs
 */
void MostrarListaDeJobs(Job* headerJobs) {
	Job* auxHeaderJobs = headerJobs;
	while (auxHeaderJobs != NULL) 
    {
		printf("--------------\n");
		printf("Job: %s\n", auxHeaderJobs->id);
		MostrarListaOperacao(auxHeaderJobs->listaOperacoes);
		auxHeaderJobs = auxHeaderJobs->next;
	}
}

/**
 * Escreve em ficheiro todos os jobs que estiverem na hashtable em binario.
 * 
 * \param headerJob
 * \return retorna false se nao gravar, retorna true se conseguiu gravar 
 */
bool GravarJob(Job* headerJob) {
    FILE* file;

    if (headerJob == NULL) return false;

    if ((file = fopen("jobs.bin", "wb")) == NULL) {
        return false;
    }

    Job* auxJob = headerJob;
    Job* nextJob;

    while (auxJob != NULL) 
    {
        nextJob = auxJob->next;
        auxJob->next = NULL;
        fseek(file, 0, SEEK_END);
        fwrite(auxJob, sizeof(Job), 1, file);
        auxJob = nextJob;
        nextJob = NULL;
    }
    fclose(file);
    file = NULL;

    return true;
}
#pragma endregion