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

#pragma region FuncoesGestaoListasOperacoes

/*---------Criar uma Operacao--------------*/
//Cria uma operação com um id
Operacao* CriarOperacao(int id){

	Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));
	if (novaOperacao == NULL) return NULL;

	novaOperacao->id = id;
	novaOperacao->next = NULL;
	novaOperacao  -> listaMaquinas = NULL;

	return novaOperacao;
}

/*---------Inserir uma operaçao numa lista por ordem do seu id--------------*/
Operacao* InserirOperacaoListaOrdenadamente(Operacao* headerListaOperacao, Operacao* novaOperacao) {
	
	if (ExisteOperacao(headerListaOperacao, novaOperacao->id)) return headerListaOperacao;

	//Se não houver nenhuma operacao na lista, inserimos a nova operacao como primeira da lista de operacoes
	if (headerListaOperacao == NULL) {
		headerListaOperacao = novaOperacao;
	}
	else
	{
		Operacao* aux = headerListaOperacao;
		Operacao* auxAnterior = NULL;
		while (aux && aux->id < novaOperacao->id)
		{
			auxAnterior = aux;
			aux = aux->next;
		}
		if (auxAnterior == NULL)  
		{
			novaOperacao->next = headerListaOperacao;
			headerListaOperacao = novaOperacao;
		}
		else
		{
			auxAnterior->next = novaOperacao;	
			novaOperacao->next = aux;
		}	
	}
	return headerListaOperacao;
}

/*---------Verificar se Operacao com o id x existe na Lista--------------*/
// retorna true se operacao existir na lista, false se não existir na lista
bool ExisteOperacao(Operacao* headerListaOperacao, int id) {
	if (headerListaOperacao == NULL) return false; 

	Operacao* aux = headerListaOperacao;

	while (aux!=NULL)
	{
		if (aux->id == id)
			return true;  // retorna true se encontrar
		aux = aux->next;
	}
	return false;   // se não encontrar vai retornar falso
}

/*---------Remover Operação da lista--------------*/
//remover a operação da lista pelo id 
Operacao* RemoverOperacao(Operacao* headerListaOperacao, int idOperacaoRemover) {

	if (headerListaOperacao == NULL) return NULL;  // se a lista estiver vazia retorno NULL 
	
	if (headerListaOperacao->id == idOperacaoRemover) {
		Operacao* aux = headerListaOperacao;
		headerListaOperacao = headerListaOperacao->next;
		free(aux);
	}
	else {
		Operacao* aux = headerListaOperacao;
		Operacao* auxAnterior = aux;

		while (aux && aux->id != idOperacaoRemover)    // percorrer a lista até encontrar o id ou até chegar ao fim
		{
			auxAnterior = aux;
			aux = aux->next;
		}
		if (aux != NULL) {
			auxAnterior->next = aux->next;
			free(aux);
		}
	}
	return headerListaOperacao;
}

/*---------Procurar Operação numa lista pelo id--------------*/
// Se encontrar a operaçao devolvo a operaçao que estou à procura
Operacao* ProcuraOperacao(Operacao* headerListaOperacao, int id ) {
	if (headerListaOperacao == NULL) return NULL;
	else {
		Operacao* aux = headerListaOperacao;
		while (aux != NULL) {
			if (aux->id == id) {
				
				return(aux);
			}
			aux = aux->next;
		}
		return NULL;
	}
}

/*---------Alterar id de uma operação --------------*/
Operacao* AlterarIdOperacao(Operacao* headerListaOperacao, int id, int novoID) {

	Operacao* aux = ProcuraOperacao(headerListaOperacao, id);
	if (aux != NULL)
	{
		//aux->id = novoID;    // com o id funciona
		aux->id = novoID;
	}
	return headerListaOperacao;
}
#pragma endregion

#pragma region CalculosOperacoes 

/*---------Procura maquina mais rapida de uma operacao--------------*/
//Encontra a maquina que demora menos unidades de tempo a fazer operacao x
int TempoMinimoOperacao(Maquina* listaMaquinas) {
    	
	if (listaMaquinas == NULL)return -1;
	
			
	Maquina* aux = listaMaquinas;
	int menorTempo = 100;
		while (aux != NULL)
		{
			if (aux->tempoTarefa < menorTempo)
			{
				menorTempo = aux->tempoTarefa;
			}
			aux = aux->next;
		}
		return (menorTempo);
}

/*---------Procura maquina mais lenta de uma operacao--------------*/
//Encontra a maquina que demora mais unidades de tempo a fazer operacao x
int TempoMaximoOperacao(Maquina* listaMaquinas) {

	if (listaMaquinas == NULL)return -1;
	
	Maquina* aux = listaMaquinas;
	int maiorTempo = 0;

	while (aux != NULL)
	{
		if (aux->tempoTarefa > maiorTempo)
		{
			maiorTempo = aux->tempoTarefa;
		}
		aux = aux->next;
	}
	return (maiorTempo);
}

/*---------Calcula o menor tempo de um job--------------*/
//Soma o menor tempo para fazer um job, percorrendo a lista de maquinas de cada operacao e analisa que maquina em cada operacao o faz em menor tempo
int SomaMenorValorOperacoes(Operacao* headerListaOperacoes) {
	if (headerListaOperacoes == NULL) return NULL;

	int soma = 0;
	Operacao* aux = headerListaOperacoes;

	while (aux != NULL) {
		soma += TempoMinimoOperacao(headerListaOperacoes->listaMaquinas);
		aux = aux->next;
	}
	return soma;
}

/*---------Calcula o maior tempo de um job--------------*/
//Soma o maior tempo para fazer um job, percorrendo a lista de maquinas de cada operacao e analisa que maquina em cada operacao o faz em maior tempo
int SomaMaiorValorOperacoes(Operacao* headerListaOperacoes) {
	if (headerListaOperacoes == NULL) return NULL;

	int soma = 0;
	Operacao* aux = headerListaOperacoes;

	while (aux != NULL) {
		soma += TempoMaximoOperacao(headerListaOperacoes->listaMaquinas);
		aux = aux->next;
	}
	return soma;
}

/*---------Calcula a media de tempo de uma operacao tendo em conta todas as maquinas possiveis--------------*/
float MediaTempoOperacao(Operacao* listaOperacoesHeader, int id)
{
	if (listaOperacoesHeader == NULL) return -1;

	Operacao* aux = listaOperacoesHeader;
	Maquina* listaMaquinaAux = aux->listaMaquinas;
	Operacao* auxOP = ProcuraOperacao(aux, id);

	float soma = 0;
	float count = ContarMaquinasOperacao(auxOP);

	while (listaMaquinaAux != NULL)
	{
		listaMaquinaAux->tempoTarefa += soma;
		listaMaquinaAux->next;
	}
	return(soma / count);
	
}

/*---------Conta quantas maquinas disponiveis tem uma operacao--------------*/
int ContarMaquinasOperacao(Operacao* operacao) {

	int count = 0;
	Maquina* listaMaquinasAux = operacao->listaMaquinas;
	while (listaMaquinasAux != NULL)
	{
		count++;
		listaMaquinasAux = listaMaquinasAux->next;
	}
	return (count);
}

#pragma endregion

#pragma region MostrarNoEcra

/*---------Mostra a lista de operacoes (1 job)--------------*/
void MostrarListaOperacao(Operacao* headerDaLista) {

	Operacao* aux = headerDaLista;

	while (aux)   // enquanto aux nao for nulo
	{
		MostraOperacao(aux);
		MostrarListaMaquinas(aux->listaMaquinas);   
		aux = aux->next;
	}
}

/*---------Mostra uma operacao x--------------*/
void MostraOperacao(Operacao* operacao) {
	if (operacao != NULL)
	{
		printf("----------------\nOperacao com Id= %d\n", operacao->id);
	}
}

/*---------Mostra uma maquina x--------------*/
void MostrarMaquina(Maquina* listaMaquinas) {
	if (listaMaquinas != NULL)
	{
		printf("\n\n Maquina com ID: %d\n", listaMaquinas->id);
		printf("\n Tempo de tarefa: %d\n", listaMaquinas->tempoTarefa);
	}
}

/*---------Mostra a lista de maquinas de uma operacao--------------*/
void MostrarListaMaquinas(Maquina* headerDaLista){

		Maquina* aux = headerDaLista;

		while (aux)
		{
			MostrarMaquina(aux);
			aux = aux->next;
		}
}

#pragma endregion