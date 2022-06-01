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

#pragma region FuncoesGestaoListasOperacoes

/**
 * .
 * Cria uma nova operacao
 * \param id
 * \return retorna operacao criada
 */

Operacao* CriarOperacao(int id){

	Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));
	if (novaOperacao == NULL) return NULL;

	novaOperacao->id = id;
	novaOperacao->next = NULL;
	novaOperacao  -> listaMaquinas = NULL;

	return novaOperacao;
}

/**
 * Insere Operacao na lista ordenadamente.
 * 
 * \param headerListaOperacao
 * \param novaOperacao
 * \return header da lista Operacao
 */
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


/**
 * Verificar se Operacao com o id x existe na Lista.
 * 
 * \param headerListaOperacao
 * \param id
 * \return true se operacao existir na lista, false se não existir na lista
 */
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

/**
 * Remover Operação da lista pelo id.
 * 
 * \param headerListaOperacao
 * \param idOperacaoRemover
 * \return header lista operacao 
 */

Operacao* RemoverOperacao(Operacao* headerListaOperacao, int idOperacaoRemover) {

	if (headerListaOperacao == NULL) return NULL;  // se a lista estiver vazia retorno NULL 
	
	if (headerListaOperacao->id == idOperacaoRemover) {
		Operacao* aux = headerListaOperacao;
		headerListaOperacao = headerListaOperacao->next;
		free(aux->listaMaquinas);
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
			free(aux->listaMaquinas);
			free(aux);
		}
	}
	return headerListaOperacao;
}

/**
 * .
 * Se encontrar a operaçao devolvo a operaçao que estou à procura
 * \param headerListaOperacao
 * \param id
 * \return 
 */

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

/**
 * Alterar operacao pelo id recebido.
 * 
 * \param headerListaOperacao
 * \param id
 * \param novoID
 * \return header da lista de operacoes
 */
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

/**
 * Encontra a maquina que demora menos unidades de tempo a fazer operacao x.
 * 
 * \param listaMaquinas
 * \return menor tempo que operacao consegue ser feita
 */
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



/**
 * Encontra a maquina que demora mais unidades de tempo a fazer operacao x.
 * 
 * \param listaMaquinas
 * \return maior tempo 
 */
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

/*
* Update 3/04/2022
* Já funciona e retorna a soma de menores valores de uma operacao
*/

/**
 * Soma o menor tempo para fazer um job, percorrendo a lista de maquinas de cada operacao e analisa que maquina em cada operacao o faz em menor tempo.
 * 
 * \param headerListaOperacoes
 * \return valor de quantas unidades de tempo um job consegue ser feito de maneira mais rapida
 */
int SomaMenorValorOperacoes(Operacao* headerListaOperacoes) {
	if (headerListaOperacoes == NULL) return NULL;

	int soma = 0;
	Operacao* aux = headerListaOperacoes;

	while (aux != NULL) {
		soma += TempoMinimoOperacao(aux->listaMaquinas);
		aux = aux->next;
	}
	return soma;
}


/**
* Update 3/04/2022
* Já funciona e retorna a soma de maiores valores de uma operacao
*/

/**
 * Soma o maior tempo para fazer um job, percorrendo a lista de maquinas de cada operacao e analisa que maquina em cada operacao o faz em maior tempo.
 * 
 * \param headerListaOperacoes
 * \return maior tempo de um job
 */
int SomaMaiorValorOperacoes(Operacao* headerListaOperacoes) {
	if (headerListaOperacoes == NULL) return NULL;

	int soma = 0;
	Operacao* aux = headerListaOperacoes;

	while (aux != NULL) {
		//soma += TempoMaximoOperacao(headerListaOperacoes->listaMaquinas);   
		soma += TempoMaximoOperacao(aux->listaMaquinas);
		aux = aux->next;
	}

	return soma;
}


/**
* Update 3 / 04 / 2022
* média já retorna a média direito e a funcionar
*/

/**
 * Calcula a media de tempo de uma operacao tendo em conta todas as maquinas possiveis.
 * 
 * \param listaOperacoesHeader
 * \param id
 * \return media de tempo de uma operacao
 */
float MediaTempoOperacao(Operacao* listaOperacoesHeader, int id)
{
	if (listaOperacoesHeader == NULL) return -1;

	Operacao* aux = listaOperacoesHeader;
	//Maquina* listaMaquinaAux = aux->listaMaquinas;
	Operacao* auxOP = ProcuraOperacao(aux, id);
	Maquina* listaMaquinaAux = auxOP->listaMaquinas;

	float soma = 0;
	float count = ContarMaquinasOperacao(auxOP);

	while (listaMaquinaAux != NULL)
	{
		//listaMaquinaAux->tempoTarefa += soma;  
		soma += listaMaquinaAux->tempoTarefa;
		//listaMaquinaAux->next;
		listaMaquinaAux=listaMaquinaAux->next;
	}

	return(soma / count);
	
}

/**
 * Conta quantas maquinas disponiveis tem uma operacao.
 * 
 * \param operacao
 * \return numero da maquinas que uma operacao tem a seu dispor
 */
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

/**
 * Mostra a lista de operacoes.
 * 
 * \param headerDaLista
 */
void MostrarListaOperacao(Operacao* headerDaLista) {

	Operacao* aux = headerDaLista;

	while (aux)   // enquanto aux nao for nulo
	{
		MostraOperacao(aux);
		MostrarListaMaquinas(aux->listaMaquinas);   
		aux = aux->next;
	}
}

/**
 * Mostra uma operacao x.
 * 
 * \param operacao
 */
void MostraOperacao(Operacao* operacao) {
	if (operacao != NULL)
	{
		printf("----------------\nOperacao com Id= %d\n\n  Maquinas associadas:", operacao->id);

	}
}


/**
 * Mostra uma maquina x.
 * 
 * \param listaMaquinas
 */
void MostrarMaquina(Maquina* listaMaquinas) {
	if (listaMaquinas != NULL)
	{
		printf("\n\n    Maquina com ID: %d", listaMaquinas->id);
		printf("\n      Tempo de tarefa: %d\n", listaMaquinas->tempoTarefa);
	}
}

/**
 * Mostra lista de maquinas de uma operacao.
 * 
 * \param headerDaLista
 */
void MostrarListaMaquinas(Maquina* headerDaLista){

		Maquina* aux = headerDaLista;

		while (aux)
		{
			MostrarMaquina(aux);
			aux = aux->next;
		}
}

/**
 * Escreve em ficheiro a lista de operacoes em binario.
 * 
 * \param headerListaOperacao
 * \return true se conseguiu escrever , false se nao conseguiu
 */
bool GravarOperacoes(Operacao* headerListaOperacao) {
	FILE* file;

	if (headerListaOperacao == NULL) return false;

	if ((file = fopen("operacoes.bin", "wb")) == NULL) {
		return false;
	}
	Operacao* auxOperacoes = headerListaOperacao;
	Operacao* nextOperacoes;
	while (auxOperacoes != NULL) {
		nextOperacoes = auxOperacoes->next;
		auxOperacoes->next = NULL;
		fseek(file, 0, SEEK_END);
		fwrite(auxOperacoes, sizeof(Operacao), 1, file);
		auxOperacoes = nextOperacoes;
		nextOperacoes = NULL;
	}
	fclose(file);
	file = NULL;

	return true;
}

#pragma endregion