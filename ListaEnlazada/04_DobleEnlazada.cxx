#include <cstddef>
#include <iostream>

using namespace std;

class Nodo{
    friend class Listadoble;
    private:
        Nodo* siguiente;
        Nodo* anterior;
        int dato;
    public:
        //Leer
        int leerdato(){
            return this->dato;
        }
        //Agregar
        void agregardato(){
            int _dato;
            cout<<"Dato ==> ";
            cin>>_dato;
            this->dato=_dato;
        }
};
class Listadoble{
    private:
        Nodo* cabeza;
        Nodo* cola;
        int tam=0;
    public:
        //Constructor lista vacia    
        Listadoble(): cabeza(NULL), cola(NULL), tam(0){}
        
        bool verificar(){
            return cabeza==NULL;
        }
        void agregarinicio(){
            Nodo* nuevoNodo = new Nodo();
            nuevoNodo->agregardato();
            nuevoNodo->siguiente=cabeza;
            nuevoNodo->anterior=NULL;
            if(tam==0){
                cola=nuevoNodo;
            }else{
                cabeza->anterior=nuevoNodo;
            }
            cabeza=nuevoNodo;
            tam++;
        }
        void agregarfinal(){
            Nodo* nuevoNodo=new Nodo();
            nuevoNodo->agregardato();
            nuevoNodo->siguiente=NULL;
            nuevoNodo->anterior=cola;
            if(tam==0){
                cabeza=nuevoNodo;
            }else{
                cola->siguiente=nuevoNodo;
            }
            cola=nuevoNodo;
            tam++;
        }
        

        void buscarElemento(){
            if(verificar()==true){
                cout<<"La lista esta vacia"<<endl;
                return;
            }
            Nodo* actual = cabeza;
            int valor=0;
            cout<<"Ingrese el valor a buscar"<<endl;
            cin>>valor;
            while (actual != NULL) {
                if (actual->leerdato() == valor) {
                    bool salir=true;
                    int respuesta=1;
                    cout<<"Se encontró el dato!"<<endl;
                    cout<<"¿Qué desea realizar?"<<endl;
                    cout<<"Regresar al menu (1)"<<endl;
                    cout<<"Agregar un valor después de este (2)"<<endl;
                    cout<<"Eliminarlo (3)"<<endl;
                    cout<<"Modificar el valor (4)"<<endl;
                    cin>>respuesta;
                    while(salir!=false){ 
                        switch(respuesta){
                            case 1:
                                return;
                            case 2:
                                agregarBuscar(actual);
                                return;
                            case 3:
                                eliminarbuscar(actual);
                                return;
                            case 4:
                                actual->agregardato();
                                return;
                            default:
                                cout<<"Opcion invalida"<<endl;
                        }
                    }
                    return;  // Elemento encontrado
                }
                actual = actual->siguiente;
            }
            return;
        }
        void agregarBuscar(Nodo* actual){
            if(actual==cola){
                agregarfinal();
            }else{
                Nodo* nuevoNodo=new Nodo();
            nuevoNodo->agregardato();
            nuevoNodo->siguiente=actual->siguiente;
            nuevoNodo->anterior=actual;
            actual->siguiente->anterior=nuevoNodo;
            actual->siguiente=nuevoNodo;
            tam++;
            }
        }
        void eliminarbuscar(Nodo* actual){
            if(actual==cabeza&&actual==cola){
                cabeza=NULL;
                cola=NULL;
            }else if(actual==cabeza){
                actual->siguiente->anterior=NULL;
                cabeza=actual->siguiente;
            }else if(actual==cola){
                actual->anterior->siguiente=NULL;
                cola=actual->anterior;
            }else{
                actual->anterior->siguiente=actual->siguiente;
                actual->siguiente->anterior=actual->anterior;
            }
            delete actual;
            tam--;
        }
        void sublista(Listadoble& sublista){
            if(verificar()==true){
                cout<<"La lista esta vacia"<<endl;
                return;
            }else{
                Nodo* actual = cabeza;
                int j, valor=0, k=0, i=0;
                cout<<"De qué tamaño requieres tu sublista?"<<endl;
                cin>>i;
                if(i>tam){
                    cout<<"La lista supera el número de nodos agregados"<<endl;
                    i=0;
                    return;
                }
                cout<<"A partir de qué dato deseas crear la sublista?"<<endl;
                cin>>valor;
                while (actual != NULL) {
                    if (actual->leerdato() == valor){
                        if(i>(tam-k)){
                            cout<<"El tamaño de la sublista es mayor a los nodos restantes"<<endl;
                            i=0;
                            return;
                        }
                        sublista.cabeza=actual;
                        sublista.tam++;
                        if(i==1){
                            sublista.cola=actual;
                        }else{
                            actual=actual->siguiente;
                            for(j=1;j<i;j++){
                               sublista.cola=actual;
                               actual=actual->siguiente;
                               sublista.tam++;
                            }
                        }      
                    }
                    actual = actual->siguiente;
                    k++;
                }
            }
        }
        void concatenar(Listadoble& l1, Listadoble& l2){
            l1.cola->siguiente=l2.cabeza;
            l2.cabeza->anterior=l1.cola;
            return;
        }
        void mostrar(Listadoble& lista){
            Nodo* actual = lista.cabeza;
            for(int i=0;i<lista.tamanio();i++) {
                cout << actual->dato << " ";
                actual = actual->siguiente;
            }
            cout << endl;
        }
        void mostrarinverso(Listadoble& lista){
            Nodo* actual = lista.cola;
            for(int i=0;i<lista.tamanio();i++) {
                cout << actual->dato << " ";
                actual = actual->anterior;
            }
            cout << endl;
        }
        int tamanio(){
            return tam;
        }
        ~Listadoble() {
            Nodo* actual = cabeza;
            while (actual != NULL) {
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            }
            cabeza = cola = NULL;
        }
};

void menu(Listadoble& lista_, Listadoble& sub){
    int resp=0, opcion=0;
    while(resp==0){
        cout<<"Agregar elemento al inicio (1)"<<endl;
        cout<<"Agregar elemento al final (2)"<<endl;
        cout<<"Buscar elemento (3)"<<endl;
        cout<<"Sublista (4)"<<endl;
        cout<<"Mostrar (5)"<<endl;
        cout<<"Mostrar inverso (6)"<<endl;
        cout<<"Regresar (7)"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                lista_.agregarinicio();
                break;
            case 2:
                lista_.agregarfinal();
                break;
            case 3:
                lista_.buscarElemento();
                break;
            case 4:
                lista_.sublista(sub);
                break;
            case 5:
                if(0<sub.tamanio()){
                    cout << "Elementos de la lista: "<<endl;
                    lista_.mostrar(lista_);
                    cout << "Elementos de la sublista: "<<endl;
                    sub.mostrar(sub);
                }else{
                    cout << "Elementos de la lista: "<<endl;
                    lista_.mostrar(lista_);
                }
                break;
            case 6:
                if(0<sub.tamanio()){
                    cout << "Elementos de la lista: "<<endl;
                    lista_.mostrarinverso(lista_);
                    cout << "Elementos de la sublista: "<<endl;
                    sub.mostrarinverso(sub);
                 }else{
                    cout << "Elementos de la lista: "<<endl;
                    lista_.mostrarinverso(lista_);
                }
                break;
            case 7:
                resp=1;
                break;
            default:
                cout<<"Opción inválida"<<endl;
                break;
        }
    }
    return;
}

int main(void){
    Listadoble lista, lista2, sub1, sub2;
    int resp=0, opcion=0;
    while(resp==0){
        cout<<"Lista #1 (1)"<<endl;
        cout<<"Lista #2 (2)"<<endl;
        cout<<"Concatenar (3)"<<endl;
        cout<<"Salir (4)"<<endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                menu(lista,sub1);
                break;
            case 2:
                menu(lista2,sub2);
                break;
            case 3:
                lista.concatenar(lista, lista2);
                break;
            case 4:
                resp=1;
                break;
            default:
                cout<<"Opción inválida"<<endl;
        }
    }
    return 0;
}