#include<stdio.h>

struct No {
    int valor;
    No *prox;
};

struct Lista {
    No *cabeca, *cauda;
    int n;

    Lista() {
        cabeca = cauda = NULL;
        n = 0;
    }

    bool vazia() { // O(1)
        return (cabeca == NULL);
    }

    void inserirInicio(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = cabeca;
            cabeca = novo;
        }
        n++;
    }

    void inserirFinal(int v) { // O(1)
        No *novo = new No();
        novo->valor = v;
        if (vazia()) {
            novo->prox = NULL;
            cabeca = novo;
            cauda = novo;
        } else {
            novo->prox = NULL;
            cauda->prox = novo;
            cauda = novo;
        }
        n++;
    }

    void imprimir() { // O(n)
        /*for (No *aux = cabeca; aux != NULL; aux = aux->prox) */
        No *aux = cabeca;
        while (aux != NULL) {
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }

    int tamanho() { // O(1)
        return n;
    }

    void removerInicio() { // O(1)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *aux = cabeca;
                cabeca = cabeca->prox;
                delete(aux);
            }
            n--;
        }
    }

    void removerFinal() { // O(n)
        if (!vazia()) {
            if (tamanho() == 1) {
                No *aux = cabeca;
                cabeca = NULL;
                cauda = NULL;
                delete(aux);
            } else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                delete(cauda);
                cauda = penultimo;
                cauda->prox = NULL;
            }
            n--;
        }
    }
    
    void removerNValores(int v) { // O(n*v)
    	while (v != 0) {
		removerFinal();	
		v--;
		}
	}
	
	void removerSegundoElemento(){
		if (!vazia()) {
			if (tamanho() == 1);
			else if (tamanho() == 2) removerFinal();
			else{
				No *aux = cabeca->prox;
				cabeca->prox = aux->prox;
				delete(aux);
				n--;
				
			}
		}
	}
	
	void inserirTamanho(){
		inserirFinal(tamanho());
	}
	
	void imprimirMenorqueN(int v){
		No *aux = cabeca;
        while (aux != NULL) {
            if (v >= aux->valor)printf("%d\n", aux->valor);
            aux = aux->prox;
        }
	}
	
	    void inserirPenultimo(int v) { // O(n)
        if (!vazia()) {
            if (tamanho() == 1);
            else {
                No *penultimo = cabeca;
                while (penultimo->prox != cauda) {
                    penultimo = penultimo->prox;
                }
                No *novo = new No();
        		novo->valor = v;
                penultimo->prox = novo;
                novo->prox = cauda;
                n++;
            }  
        }
    }
};

int main() {

    Lista l;
    l.inserirFinal(5);
    l.inserirFinal(4);
    l.inserirFinal(3);
    l.inserirFinal(2);
    l.inserirFinal(7);
    l.inserirFinal(1);
    l.inserirFinal(0);

    l.inserirPenultimo(69);
	l.imprimir();
    printf("%d\n", l.tamanho());

    return 0;
}
