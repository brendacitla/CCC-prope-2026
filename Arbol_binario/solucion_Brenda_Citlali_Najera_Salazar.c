#include <stdlib.h>

typedef struct nodo {
int valor;
struct nodo *izq;
struct nodo *der;
} Nodo;

/*--------------------------------------------------
CREAR NODO
--------------------------------------------------*/

static Nodo *crear_nodo(int valor) {
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));

    nuevo->valor = valor;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

/*--------------------------------------------------
INSERTAR POR NIVELES
--------------------------------------------------*/

Nodo *insertar(Nodo *raiz, int valor) {
    Nodo *nuevo = crear_nodo(valor);

    if (raiz == NULL)
    return nuevo;

    Nodo *cola[10000];

    int frente = 0;
    int fin = 0;

    cola[fin++] = raiz;

while (frente < fin) {

    Nodo *actual = cola[frente++];

    if (actual->izq == NULL) {
        actual->izq = nuevo;
        return raiz;
    }

    if (actual->der == NULL) {
        actual->der = nuevo;
        return raiz;
    }

    cola[fin++] = actual->izq;
    cola[fin++] = actual->der;
}

return raiz;
}

/*--------------------------------------------------
RECONSTRUIR
--------------------------------------------------*/

static Nodo *construir_rec(
const int *pre,
const int *in,
int n
) {

    if (n == 0)
    return NULL;

    Nodo *raiz = crear_nodo(pre[0]);

    int pos = 0;

while (pos < n && in[pos] != pre[0])
    pos++;

int tam_izq = pos;
int tam_der = n - pos - 1;

raiz->izq =
    construir_rec(
        pre + 1,
        in,
        tam_izq
    );

raiz->der =
    construir_rec(
        pre + 1 + tam_izq,
        in + pos + 1,
        tam_der
    );

return raiz;
}

/*--------------------------------------------------
CONSTRUIR DESDE PREORDEN E INORDEN
--------------------------------------------------*/

Nodo *construir(
const int *pre,
const int *in,
int n
) {
return construir_rec(pre, in, n);
}

