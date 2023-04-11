#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;
NO* maior = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (primeiro == NULL) {
		primeiro = novo;
		maior = novo;
	}
	//checa se o novo valor é igual ao primeiro valor
	else if (novo->valor == primeiro->valor) {
		cout << "Elemento Duplicado \n";
		return;
	}
	else 
	{
		NO* aux = primeiro;
		//checa se o valor é duplicado
		while (aux->prox != NULL) {
			aux = aux->prox;
			if (aux->valor == novo->valor) {
				cout << "Elemento Duplicado \n";
				return;
			}
		}	
		//checa se o novo valor é menor que o primeiro e se for, ele vira o primeiro
		if (novo->valor < primeiro->valor) {
			novo->prox = primeiro;
			primeiro = novo;
		}
		//checa se o novo valor é maior que o maior valor e então o novo vira o maior
		else if (novo->valor > maior->valor) {
			aux->prox = novo;
			maior = novo;
		}
		//se ele for menor que o maior (que não seja o primeiro)
		else {
			NO* aux = primeiro->prox;
			NO* ant = primeiro;
			while (aux != NULL) {
				if (aux->valor > novo->valor) {
					ant->prox = novo;
					novo->prox = aux;
					return;
				}
				ant = aux;
				aux = aux->prox;
			}
		}
	}
}

void excluirElemento()
{
	if (primeiro == NULL) {
		cout << "Lista Vazia \n";
	}
	else {
		int valor = NULL;
		cout << "Insira o valor que deseja excluir: \n";
		cin >> valor;

		NO* aux = primeiro->prox;
		NO* ant = primeiro;
		NO* paraExcluir = aux;

		if (valor < primeiro->valor || valor > maior->valor) {
			cout << "VALOR NAO ENCONTRADO \n";
			return;
		}
		else if (primeiro->prox == NULL) {
			free(primeiro);
			cout << "Elemento Excluido \n";
			primeiro = NULL;
		}
		else if (valor == primeiro->valor) {
			primeiro = primeiro->prox;
			free(ant);
			cout << "Elemento Excluido \n";
		}
		else {
			while (aux != NULL) {
				if (valor == aux->valor) {
					ant->prox = aux->prox;
					free(paraExcluir);
					cout << "Elemento Excluido \n";
					return;
				}
				aux = aux->prox;
			}
			cout << "VALOR NAO ENCONTRADO \n";
		}
	}
}

void buscarElemento()
{
	if (primeiro == NULL) {
		cout << "Lista Vazia \n";
	}
	else {
		int valor = NULL;
		cout << "Insira o valor que deseja buscar: \n";
		cin >> valor;

		NO* aux = primeiro;
		if (valor < primeiro->valor || valor > maior->valor) {
			cout << "VALOR NAO ENCONTRADO \n";
			return;
		}
		else {
			while (aux != NULL) {
				if (valor == aux->valor) {
					cout << "VALOR ENCONTRADO \n";
					return;
				}
				aux = aux->prox;
			}
			cout << "VALOR NAO ENCONTRADO \n";
		}
	}

}

