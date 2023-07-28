
#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};
void menu();
void insertarLista(Nodo*&, int);
void mostrarLista(Nodo*);
void buscarLista(Nodo*, int);
void eliminarNodo(Nodo*&, int);
// nuevos metodos
void insertarinicio(Nodo**, int);
void insertarentredos(Nodo**, Nodo *,int);
void insertarfin(Nodo*&, int);


Nodo* lista = NULL;
Nodo* anterior = NULL;

int main() {

	menu();

	system("pause");
	return 0;
}
void menu() {

	int opcion, dato;

	do {
		cout << "\t.:MENU:.\n";
		cout << "1. Insertar un numero a la lista" << endl;
		cout << "2. Mostrar todos los elementos de la lista" << endl;
		cout << "3. Buscar dato en la lista" << endl;
		cout << "4. Eliminar un nodo de la lista\n";
		cout << "--------nuevas opciones---------\n";
		cout << "5. Insertar nodo al Inicio\n";
		cout << "6. Insertar entre 2 nodos\n";
		cout << "7. Insertar al final de la fila\n";
		cout << "8. Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
		case 1: cout << "\nDigite un numero: ";
			cin >> dato;
			insertarLista(lista, dato);
			cout << "\n";

			system("pause");
			break;
		case 2: mostrarLista(lista);
			cout << "\n";
			system("pause");
			break;
		case 3: cout << "\nIngrese numero a buscar: ";
			cin >> dato;
			buscarLista(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 4: cout << "\nIngrese numero a eliminar: ";
			cin >> dato;
			eliminarNodo(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 5:
			cout << "\nIngrese numero para agregar al inicio de la lista: "; cin >> dato;
			insertarinicio(&lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 6:
			cout << "\nIngrese numero para agregar en medio de la lista: "; cin >> dato;
			 insertarentredos(&lista, anterior, dato);
			 cout << "\n";
			 system("pause");
			break;
		case 7:
			cout << "\nIngrese numero para agregar al final de la lista: "; cin >> dato;
			insertarfin(lista, dato);
			cout << "\n";
			system("pause");
			break;
		case 8:
			break;

		}
		system("cls"); //limpiar pantalla
	} while (opcion != 8);

}
//Insertar elemento en la lista
void insertarLista(Nodo*& lista, int n) {
	Nodo* nuevo_nodo = new Nodo();
	Nodo* aux;

	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;

	if (lista == NULL) {//Si la lista esta vacia
		lista = nuevo_nodo;//agregamos el primer nodo
	}
	else {
		aux = lista;
		while (aux->siguiente != NULL) {//recorremos la lista hasta llegar al final
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;//agregamos el nuevo nodo al final de la lista
	}
	cout << "\tElemento " << n << " agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo* lista) {
	Nodo* actual = new Nodo();

	actual = lista;
	while (actual != NULL) { //mientras no sea final de la lista
		cout << actual->dato << " -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}

void buscarLista(Nodo* lista, int n) {
	bool band = false;

	Nodo* actual = new Nodo();
	actual = lista;

	while ((actual != NULL) && (actual->dato <= n)) {//mientras no sea el final de la lista
		if (actual->dato == n) {
			band = true;
		}
		actual = actual->siguiente;
	}
	if (band == true) {
		cout << "Elemento " << n << " Si a sido encontrado en la lista \n";
	}
	else {
		cout << "Elemento" << n << " No a sido encontrado en lista \n";
	}
}

void eliminarNodo(Nodo*& lista, int n) {
	if (lista != NULL) {
		Nodo* aux_borrar;
		Nodo* anterior = NULL;
		aux_borrar = lista;

		while ((aux_borrar != NULL) && (aux_borrar->dato != n)) {
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		if (aux_borrar == NULL) {
			cout << "El elemento no existe";
		}
		else if (anterior == NULL) {
			lista = lista->siguiente;
			delete aux_borrar;
		}
		else {
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
		}
	}
}
void insertarinicio(Nodo** lista, int n) {
	Nodo* nuevo = new Nodo;
	nuevo->dato = n;
	nuevo->siguiente = *lista;
	*lista = nuevo;



}

void insertarentredos(Nodo** lista, Nodo* anterior, int n) {
	if (anterior==NULL || *lista==NULL)
	{
		insertarinicio(lista, n);
	}
	else {
		Nodo* nuevo = new Nodo;
		nuevo->dato = n;
		nuevo->siguiente = anterior->siguiente;
		anterior->siguiente = nuevo;
	}
}

//
void insertarfin(Nodo*& lista, int n) {
	Nodo* ultimo = new Nodo();
	Nodo* aux;

	ultimo->dato = n;
	ultimo->siguiente = NULL;

	if (lista == NULL) {//Si la lista esta vacia
		lista = ultimo;//agregamos el primer nodo
	}
	else {
		aux = lista;
		while (aux->siguiente != NULL) {//recorremos la lista hasta llegar al final
			aux = aux->siguiente;
		}
		aux->siguiente = ultimo;//agregamos el nuevo nodo al final de la lista
	}
	cout << "\tElemento " << n << " agregado a lista correctamente\n";
}
