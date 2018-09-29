#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char patente[6];
    int valor;
    char marca[20];
}celdaAuto;

typedef struct{
    celdaAuto a;
    struct nodoAuto * sig;
}nodoAuto;

nodoAuto * iniclista(){
    return NULL;
}

//int insertarCelda(celdaAuto A [30], char patente[6], int valor, char marca[10], int c). Inserta los datos de un nuevo auto en el arreglo, de manera de conservarlo ordenado por valor en forma creciente. C es la cantidad de datos que tiene el arreglo y retorna c+1. Al inicio c vale 0.
int insertarCelda(celdaAuto A [30], char patente[], char marca[], int valor, int c){
    int i = c;
    if(c!=0){
        while(i>=0&&valor<A[i].valor){
            A[i+1] = A[i];
            i--;
        }
    }
    strcpy(A[i].patente,patente);
    A[i].valor=valor;
    strcpy(A[i].marca,marca);
    return c+1;
    /*while(c>=0&&A[c].valor>valor){
        A[c+1]=A[c];
    }
    strcpy(A[c].patente,patente);
    A[c].valor=valor;
    strcpy(A[c].marca,marca);
    return c+1;*/
}

nodoAuto * crearNodo(celdaAuto a){
    nodoAuto * nuevoNodo = (nodoAuto*)malloc(sizeof(nodoAuto));
    nuevoNodo->a=a;
    nuevoNodo->sig=NULL;
    return nuevoNodo;
}

nodoAuto * buscarUltimo(nodoAuto * lista){
    nodoAuto * cursor=lista;
    while(cursor!=NULL){
        cursor=cursor->sig;
    }
    return cursor;
}

void agregarFinal(nodoAuto  ** lista​, nodoAuto * nuevo){
    if(*lista​!=NULL){
        *lista​=nuevo;
    }else{
        nodoAuto * ultimo = buscarUltimo(*lista​);
        ultimo->sig = nuevo;
    }
}

void mostrarNodo(nodoAuto * aux){
    printf("Patente: %s\n",aux->a.patente);
    printf("Marca: %s\n",aux->a.marca);
    printf("Valor: %i\n",aux->a.valor);
}


void recorrerMostrar(nodoAuto*lista){
    nodoAuto * cursor = lista;
    while (cursor) {
        mostrarNodo(cursor);
        cursor=cursor->sig;
        
    }
}

void agregarMuchos(nodoAuto ** lista, celdaAuto A[], int c){
    char control = 's';
    char marca[20], patente[6];
    int valor;
    
    while(control=='s'){
        printf("----- CARGA DE DATOS -----\n");
        printf("Patente: ");
        fflush(stdin);
        scanf("%s",patente);
        printf("Marca: ");
        fflush(stdin);
        scanf("%s",marca);
        printf("Valor: ");
        fflush(stdin);
        scanf("%i",&valor);
        c=insertarCelda(A, patente, marca, valor, c);
        agregarFinal(lista, crearNodo(A[c]));
        printf("Desea continuar? S/N ");
        fflush(stdin);
        scanf(" %c",&control);
    }
}

int main(int argc, char const *argv[]) {
    nodoAuto * lista;
    lista=iniclista();
    int c=0;
    celdaAuto A[30];
    //c=insertarCelda(A,"abc","abc",25000,c);
    //agregarFinal(&lista,crearNodo(A[0]));
    agregarMuchos(&lista,A,c);
    recorrerMostrar(lista);
    return 0;
}
