/**
* Nome: Bruno Ferreira
* Número: 13227
* email: a13227@alunos.ipca.pt
* Curso: Engenharia em desenvolvimento jogos digitais
* Cadeira: Estruturas de dados Avançados
* Descrição:Trabalho prático Fase 1
*/

#include"Dados.h"
#include<stdio.h>

#pragma region FuncoesListasMaquinas
/*---------Criar uma maquina--------------*/
//Uma maquina possui um id e um tempo para executar uma tarefa
Maquina* CriarMaquina(int id, int tempoTarefa) {
	Maquina* novaMaquina = (Maquina*)malloc(sizeof(Maquina));
	if (novaMaquina == NULL) return NULL;	//em caso de nao haver memoria para criar uma maquina 
	novaMaquina->id = id;
	novaMaquina->tempoTarefa = tempoTarefa;
	novaMaquina->next = NULL;
	return novaMaquina;
}

/*---------Inserir Maquina numa lista de maquinas----------------------------*/
//Insere maquina ordenadamente pelo id numa lista de maquinas 
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

#pragma endregion
