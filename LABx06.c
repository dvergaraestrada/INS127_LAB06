#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct NodoArbol{
	int dato;
	struct NodoArbol *izq;
	struct NodoArbol *der;
}NodoArbol;

typedef NodoArbol *pNodo;
typedef NodoArbol *raiz;

NodoArbol *crearNodoArbol(int dato){
	NodoArbol *n=(NodoArbol*)malloc(sizeof(NodoArbol));
	n->dato=dato;
	n->izq=NULL;
	n->der=NULL;
	
	return n;
}

void addNodoIzq(NodoArbol *donde, NodoArbol *cual){
	donde->izq=cual;
}

void addNodoDer(NodoArbol *donde, NodoArbol *cual){
	donde->der=cual;
}

void imprimirNodoArbol(NodoArbol *n){
	printf("%d",n->dato);
}

int Vacio(NodoArbol *raiz)
{
   return raiz==NULL;
}

int EsHoja(NodoArbol *raiz)
{
   return !raiz->der && !raiz->izq;
}

/*buscar el elemento más pequeño*/
int min(int a, int b);
/*buscar el elemento más grande*/
int max(int a, int b);
/*cantidad de niveles del ABB*/
int nivel(NodoArbol *raiz);
/* Eliminar un elemento de un árbol ABB */
void Borrar(NodoArbol *raiz, int n);
/*imprimir inorden el ABB*/
void inorden(NodoArbol *raiz);

NodoArbol *ABBbuscar(NodoArbol *raiz, NodoArbol *n);
void ABBInsertarNodo(NodoArbol* raiz, NodoArbol* n);



int main(){
	NodoArbol *arbol, *encontrado;
	arbol=crearNodoArbol(9);
	int aBuscar;
	ABBinsertarNodo(arbol, crearNodoArbol(78));
	ABBinsertarNodo(arbol, crearNodoArbol(6));
	ABBinsertarNodo(arbol, crearNodoArbol(3));
	ABBinsertarNodo(arbol, crearNodoArbol(7));
	ABBinsertarNodo(arbol, crearNodoArbol(9));
	ABBinsertarNodo(arbol, crearNodoArbol(5));
	ABBinsertarNodo(arbol, crearNodoArbol(88));
	ABBinsertarNodo(arbol, crearNodoArbol(10));
	ABBinsertarNodo(arbol, crearNodoArbol(0));
	ABBinsertarNodo(arbol, crearNodoArbol(1));
	ABBinsertarNodo(arbol, crearNodoArbol(34));
	ABBinsertarNodo(arbol, crearNodoArbol(22));
	ABBinsertarNodo(arbol, crearNodoArbol(4));
	ABBinsertarNodo(arbol, crearNodoArbol(2));
	ABBinsertarNodo(arbol, crearNodoArbol(8));
	ABBinsertarNodo(arbol, crearNodoArbol(45));
	ABBinsertarNodo(arbol, crearNodoArbol(32));
	ABBinsertarNodo(arbol, crearNodoArbol(65));
	ABBinsertarNodo(arbol, crearNodoArbol(42));
	
	printf("\n\nIndique valor a buscar en el ABB");
	scanf("%d",&aBuscar);
	fgetc(stdin);
	
	encontrado= ABBbuscar(arbol, crearNodoArbol(aBuscar));
	
	if(encontrado !=NULL){
		printf("Valor encontrado: %s",encontrado->dato);
	}else{
		printf("No encontrado");
	}
	
	
	min(int a, int b);
	printf("\n");
	max(int a, int b);
	printf("\n");
	printf("\nEl nivel de el ABB es -> %d <-", nivel(arbol));
	printf("\n");
   	Borrar(arbol, 45);
   	printf("Borrar 45: ");
   	printf("\n");
	inorden(arbol);
	
}


void ABBInsertarNodo(NodoArbol* raiz, NodoArbol* n){
    if(raiz != NULL){
        if(raiz->dato > n->dato){
            if(raiz->izq == NULL){
                addNodoIzq(raiz,n);
            }{
                ABBInsertarNodo(raiz->izq, n);
            }
        }else if(raiz->dato < n->dato){
            if(raiz->der == NULL){
                addNodoDer(raiz, n);
            }else{
                ABBInsertarNodo(raiz->der, n);
            }
        }
    }
}


NodoArbol *ABBbuscar(NodoArbol *raiz, NodoArbol *n){
	if(raiz!=NULL){
		if(n->dato==raiz->dato){
			return raiz;
		}else if(n->dato > raiz->dato){
			return ABBbuscar(raiz->der, n);
		}else{
			return ABBbuscar(raiz->izq, n);
		}
	}else{
		return NULL;
	}
}

int min(int a, int b){
	if(a<b){
		return a;
	}
}

int max(int a, int b){
	if(a>b){
		return a;
	}
}

int nivel(NodoArbol* raiz){
    if(raiz == NULL){
        return 0;
    }else{
        return 1+ max(nivel(raiz->izq), nivel(raiz->der));
    }
}

void Borrar(NodoArbol *raiz, int n){
   pNodo padre = NULL;
   pNodo actual;
   pNodo nodo;
   int aux;

   actual = *raiz;
   while(!Vacio(actual)) {
      if(n == actual->dato) {
         if(EsHoja(actual)) {
            if(padre)
               if(padre->der == actual) padre->der = NULL;
               else if(padre->izq == actual) padre->izq = NULL;
            free(actual);
            actual = NULL;
            return;
         }
         else {
            padre = actual;
            if(actual->der) {
               nodo = actual->der;
               while(nodo->izq) {
                  padre = nodo;
                  nodo = nodo->izq;
               }
            }
            else {
               nodo = actual->izq;
               while(nodo->der) {
                  padre = nodo;
                  nodo = nodo->der;
               }
            }
            aux = actual->dato;
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else {
         padre = actual;
         if(n > actual->dato) actual = actual->der;
         else if(n < actual->dato) actual = actual->izq;
      }
   }
}

void inorden(NodoArbol *raiz){
	if(raiz!=NULL){
		inorden(raiz->izq);
		imprimirNodoArbol(raiz);
		inorden(raiz->der);
	}
}

