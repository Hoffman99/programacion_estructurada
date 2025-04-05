#include <cstddef>
#include <iostream>

using namespace std;

class Nodo{
    friend class Listadoble;
    private:
        Nodo* siguiente;
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
            if(tam==0){
                cola=nuevoNodo;
            }
            cabeza=nuevoNodo;
            tam++;
        }
        void agregarfinal(){
            Nodo* nuevoNodo=new Nodo();
            nuevoNodo->agregardato();
            nuevoNodo->siguiente=cabeza;
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
                                eliminarbuscar(respuesta);
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
            actual->siguiente=nuevoNodo;
            tam++;
            }
        }
        void eliminarbuscar(int valor){
            Nodo* actual = cabeza;
        Nodo* anterior = NULL;
        
        // Buscar el nodo a eliminar
        while (actual != NULL && actual->dato != valor) {
            anterior = actual;
            actual = actual->siguiente;
        }
        
        // Si no se encontró el valor
        if (actual == NULL) {
            return;
        }
        
        // Caso 1: Eliminar el primer nodo
        if (actual == cabeza) {
            cabeza = cabeza->siguiente;
            // Si era el único nodo, actualizar cola
            if (cabeza == NULL) {
                cola = NULL;
            }
        }
        // Caso 2: Eliminar nodo intermedio o final
        else {
            anterior->siguiente = actual->siguiente;
            // Si era el último nodo, actualizar cola
            if (actual == cola) {
                cola = anterior;
            }
        }
        
        delete actual;
        return;
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
        void mostraranillo(){
            int cantidad;
            Nodo* actual = cabeza;
            cout<<"Ingrese el numero de nodos que quiere que aparezcan ==> ";
            cin>>cantidad;
            for(int i=0;i<cantidad;i++) {
                cout << actual->dato << " ";
                actual = actual->siguiente;
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
        cout<<"Mostrar n cantidad de nodos de la lista (6)"<<endl;
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
                lista_.mostraranillo();
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