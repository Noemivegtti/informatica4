
#include <iostream>
#include <ctime>


using namespace std;

struct Nodo {
	int info; 
	Nodo* next;
};typedef struct Nodo nodo;
class Lista {
	private:
		nodo* s;
	public:
		Lista() {
			s = NULL;
		}
		nodo * insertTesta()   // Inserimento in testa 
        {                         
			nodo *p;
			p = new Nodo;
			cin >> p->info;
			p->next = s;
			s = p;
			return p;
		}
		void stampaLista()   	// Stampa lista
        {
			nodo *q;
			q = s;
			while(q != NULL) {
			cout << q->info << " ";
			q = q->next;
			}
			cout << endl;
		}
		void insertUltimo() {	// Inserisci ultimo elemento nella lista 
			Nodo *p = new Nodo;
			cin >> p -> info;
			p-> next = NULL;
			if(s == NULL) {
				s = p;
			}
			else {
				nodo *q = s;
				while( q->next != NULL) {
					q = q->next;
				}
			q -> next = p;
			}
		}
		int getElemento() {  // Restituisce l'elemento
			return s->info;
		}
		void setElemento(int x) { // Setto il valore dell'elemento
			s->info = x;
		}
		int cancellaNodo() { // Cancellazione in testa del nodo
			if (s == NULL) {
				return 1; 
			}
			else {
				nodo *p;
				p = s;
				s = s ->next;
				delete(p);
			}
			return 0;
		} 
		int cancellaUltimo() { // Cancellazione dell'ultimo nodo
			if(s == NULL) { 		// Se la lista è vuota 
				return 1;
			}
			if(s->next== NULL) { 		// Se la lista ha solo un nodo, cancello il primo 
				return cancellaNodo();
			}
			else { 
				nodo *q,*p;
				q = s;
				while(q->next != NULL) { // Scorro il nodo fino all'ultimo nodo
					p = q;
					q = q->next;
				}
				delete (q);
				p->next=NULL;
				
			}
			return 0;
		}
		int ricercaNodo(int valore) { // Ricerca di un nodo
			nodo *q;
			q = s;
			while(q != NULL) {
				if(q->info == valore) { // Se il nodo è uguale al valore cercato
					return 1;
				}
				q = q->next;
			}
			return 0;
		}
		int contaNodo() { // Conta il numero dei nodi
			nodo *q;
			int cont = 0;
			q = s;
			while(q != NULL) {
				cont++;
				q = q->next;
			}
			return cont;
		}
		void eliminaDuplicati() { // Elimina i duplicati
			nodo *q,*p,*r;
			q = s;
			while(q->next != NULL) { // Scorro la lista
				p = q;
				r = q->next;
				while(r != NULL) { 
					if(q->info == r->info) { // Se il nodo è uguale al nodo successivo, lo elimino
						p->next = r->next; 
						delete(r);
						r = p->next;
					}
					else { // Altrimenti scorro la lista
						p = r;
						r = r->next;
					}
				}
				q = q->next;
			}
		}
}; 
	int main () {
	srand(time(0));
	Lista L1;
	for(int i = 0; i<4; i++) {
		L1.insertTesta();
	}
	L1.stampaLista();
	int k = L1.cancellaUltimo();
	if(k ==1) {
		cout << "no" << endl;
	}
	else
	L1.stampaLista();
	return 0;
}