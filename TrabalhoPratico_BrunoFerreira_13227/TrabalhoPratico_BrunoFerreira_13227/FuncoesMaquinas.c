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

#pragma region FuncoesListasMaquinas

/**
 * Cria uma maquina com um id e tempo de tarefa.
 * 
 * \param id
 * \param tempoTarefa
 * \return nova maquina
 */
Maquina* CriarMaquina(int id, int tempoTarefa) {
	Maquina* novaMaquina = (Maquina*)malloc(sizeof(Maquina));
	if (novaMaquina == NULL) return NULL;	//em caso de nao haver memoria para criar uma maquina 
	novaMaquina->id = id;
	novaMaquina->tempoTarefa = tempoTarefa;
	novaMaquina->next = NULL;
	return novaMaquina;
}

/**
 * Inserir Maquina numa lista de maquinas.
 * 
 * \param header
 * \param novaMaquina
 * \return header da lista de maquinas
 */
Maquina* InserirMaquinaLista(Maquina* header, Maquina* novaMaquina) {

	//if (ExisteMaquina(header, novaMaquina->id)) return header;    Pode haver maquinas iguais ?

	if (header == NULL) {
		header = novaMaquina;     //insere no inicio
	}
	else {
		Maquina* aux = header;
		Maquina* auxAnterior = NULL;

		while (aux && aux->id < novaMaquina->id)
		{
			auxAnterior = aux;
			aux = aux->next;
		}
		if (auxAnterior == NULL)
		{
			novaMaquina->next = header;
			header = novaMaquina;         //insere no meio
		}
		else
		{
			auxAnterior->next = novaMaquina;
			novaMaquina->next = aux;         //insere no fim 
		}
	}
	return header;
}

/*-----------Inserir Maquina na lista de maquinas de uma Operacao------------*/
//recebo o header da lista operacao, o id da operacao onde quero inserir uma maquina e a maquina a inserir

/**
 * Inserir Maquina na lista de maquinas de uma Operacao.
 * recebo o header da lista operacao, o id da operacao onde quero inserir uma maquina e a maquina a inserir
 * 
 * \param headerListaOperacao
 * \param id
 * \param maq
 * \return header da lista de operacoes
 */
Operacao* InserirMaquinaNaOperacao(Operacao* headerListaOperacao, int id, Maquina* maq)
{
	Operacao* aux = ProcuraOperacao(headerListaOperacao, id);  
	if (aux == NULL) return NULL;
	else {
		aux = headerListaOperacao;
		while (aux != NULL)
		{
			if (aux->id != id)
			{
				aux = aux->next;
			}
			else
			{
				aux->listaMaquinas = InserirMaquinaLista(aux->listaMaquinas, maq);
				return (aux);
			}
		}
	}
}


/**
 * Gravar lista de maquinas em ficheiro binario .
 * 
 * \param headerListaMaquinas
 * \return true se conseguiu gravar, false se não conseguiu
 */
bool GravarMaquinas(Maquina* headerListaMaquinas) 
{
	FILE* file;

	if (headerListaMaquinas == NULL) return false;

	if ((file = fopen("maquinas.bin", "wb")) == NULL) {
		return false;
	}
	Maquina* auxMaquinas = headerListaMaquinas;
	Maquina* proxMaquina;
	while (auxMaquinas != NULL) {
		proxMaquina = auxMaquinas->next;
		auxMaquinas->next = NULL;
		fseek(file, 0, SEEK_END);
		fwrite(auxMaquinas, sizeof(Maquina), 1, file);
		auxMaquinas = proxMaquina;
		proxMaquina = NULL;
	}
	fclose(file);
	file = NULL;

	return true;
}

#pragma endregion
