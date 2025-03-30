#include <iostream>
/*SOlicitar al usuario el numero de exponentes para saber el tamaño del poliniomio
y tambien la variable general de ese polinomio
Le tienees que pedir al usuario que ingrese los datos del polinomio
Cuando haga la multiplicación puedes crear un Lista de multiplicación (datos de la multiplciación)
sumar todos los datos de la lista multiplicación en una llamada resultado y este resultado tiene que ir organizado de mayor a menor
*/
using namespace std;

typedef int Elemento;

// Clase para el nodo (valores que guardare dentro de el)
class Nodo {
    public:
        Elemento dato;
        char variable;
        Elemento exponente;
        Nodo *siguiente;
        
        // Constructor
        Nodo(Elemento valor, char var = ' ', Elemento exp = 0) : dato(valor), variable(var), exponente(exp), siguiente(NULL) {}
};

// Clase para la la lista enlazada
class polinomio {
    public:

        Nodo *cabeza;  // Puntero al primer nodo
        Nodo *cola;    // Puntero al último nodo
    
        // Constructor: crea mi lista vacia
        polinomio() : cabeza(NULL), cola(NULL) {}

        // Verifica si mi lista esta vacia
        bool estaVacia() const {
            return cabeza == NULL;
        }
        
        // Insertar terminos al polinomio
        void insertar_termino(Elemento valor,char var,int exp) {         
            if (exp<0)
            {
                cout<<"Un polinomio no puede tener exponentes negativos. Intentalo de nuevo \n\n";
            }else
            {
                Nodo *nuevoNodo = new Nodo(valor,var,exp);
                nuevoNodo->siguiente = NULL;
                if (estaVacia()){
                    cabeza=nuevoNodo;
                    cola=nuevoNodo;
                }else{
                    cola->siguiente = nuevoNodo;
                    cola=nuevoNodo;
                }
            }
        }
        
        // Mostrar todos los elementos del polinomio
        void mostrar(){
            if (estaVacia())
            {
                cout<<"Aun no has ingresado nada!!\n";
            }else
            {
                Nodo *actual = cabeza;
                cout << "Polinomio: ";
                while (actual != NULL) {
                    if (actual->dato>=0 && actual!=cabeza)
                    {
                        cout <<"+"<<actual->dato <<actual->variable<<"^"<<actual->exponente;
                    }else
                    {
                        cout <<actual->dato <<actual->variable<<"^"<<actual->exponente;      
                    }
    
                    actual = actual->siguiente;
                }
                cout <<'\n';
            }
            
            
        }
        // Destructor: libera todos los nodos de la lista
        ~polinomio() {
            Nodo* actual = cabeza;
            while (actual != NULL) {
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            }
            cabeza = cola = NULL;
        }
};

void sumar(const polinomio& p1, const polinomio& p2){
    Nodo *punt_1 = p1.cabeza;
    Nodo *punt_2 = p2.cabeza;
    bool primerTermino = true;
    bool band_suma=false;
    cout<<"El resultado de la suma es: ";
    while (punt_1 != NULL) {
        band_suma = false;
        while (punt_2 != NULL) {
            if (punt_1->exponente == punt_2->exponente && punt_1->variable == punt_2->variable) {
                int result = punt_1->dato + punt_2->dato;
                if (result != 0) {
                    if (primerTermino==false) { 
                        cout << (result > 0 ? " +" : " ");
                    }
                    cout << result << punt_1->variable << "^" << punt_1->exponente;
                    primerTermino = false;
                }
            band_suma=true;
            }
            punt_2 = punt_2->siguiente;
        }
        if (band_suma==false) {
            if (primerTermino==false) {
                cout << (punt_1->dato > 0 ? " +" : " ");
            }
            cout << punt_1->dato << punt_1->variable << "^" << punt_1->exponente;
            primerTermino = false;
        }
        punt_2 = p2.cabeza;
        punt_1 = punt_1->siguiente;
    }
    cout << '\n';
}

void restar(const polinomio& p1, const polinomio& p2){
    Nodo *punt_1 = p1.cabeza;
    Nodo *punt_2 = p2.cabeza;
    bool primerTermino = true;
    bool band_suma=false;
    cout<<"El resultado de la resta es: ";
    while (punt_1 != NULL) {
        band_suma = false;
        while (punt_2 != NULL) {
            if (punt_1->exponente == punt_2->exponente && punt_1->variable == punt_2->variable) {
                int result = punt_1->dato + (punt_2->dato*-1);
                if (result != 0) {
                    if (primerTermino==false) { 
                        cout << (result > 0 ? " +" : " ");
                    }
                    cout << result << punt_1->variable << "^" << punt_1->exponente;
                    primerTermino = false;
                }
            band_suma=true;
            }
            punt_2 = punt_2->siguiente;
        }
        if (band_suma==false) {
            if (primerTermino==false) {
                cout << (punt_1->dato > 0 ? " +" : " ");
            }
            cout << punt_1->dato << punt_1->variable << "^" << punt_1->exponente;
            primerTermino = false;
        }
        punt_2 = p2.cabeza;
        punt_1 = punt_1->siguiente;
    }
    cout << '\n';
}

void multiplicar(const polinomio& p1, const polinomio& p2){
    Nodo *punt1=p1.cabeza;
    Nodo *punt2=p2.cabeza;
    bool primer_termino=true;
    cout<<"El resultado de la multiplicacion es: ";
    while (punt1!=NULL)
    {
        cout<<'(';
        while (punt2!=NULL)
        {
            int result=punt1->dato*punt2->dato;
            if (primer_termino)
            {
                cout<<result<<punt1->variable<<"^"<<punt1->exponente+punt2->exponente;
                primer_termino=false;
            }else
            {
                cout<<(result > 0 ? " +" : " ")<<result<<punt1->variable<<"^"<<punt1->exponente+punt2->exponente;
            }
            punt2=punt2->siguiente;
        }
        cout<<')';
        if (punt1->siguiente!=NULL)
        {
            cout<<" + ";
        }
        punt2 = p2.cabeza;
        punt1=punt1->siguiente;
    }
    
}

int main() {
    polinomio p1,p2;
    p1.insertar_termino(10,'x',2);
    p1.insertar_termino(-8,'x',1);
    p1.mostrar();

    p2.insertar_termino(20,'x',2);
    p2.insertar_termino(-2,'x',1);
    p2.mostrar();

    sumar(p1,p2);

    restar(p1,p2);
    multiplicar(p1,p2);
    return 0;   
}
