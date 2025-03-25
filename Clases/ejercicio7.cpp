#include <iostream>
using namespace std;
#define tam 2

class matriz{//Crea la clase matriz y agrega sus caracteristicas
	private:
		double fila1[tam];
        double fila2[tam];
	public:
		void llenarmatriz();
        friend void sumar(const matriz& m1, const matriz& m2);//Declaración friend del constructor sumar, para que las funciones que no son miembro de la clase puedna acceder a ellas
		void multiplicar();	
};

void matriz::llenarmatriz(){//Constructor para llenar las filas de la matriz
    cout<<"==> Primera fila (2 valores): ";
    for(int i=0; i<tam; i++){
        cin>>fila1[i];
    }
    cout<<"==> Segunda fila (2 valores): ";
    for(int i=0; i<tam; i++){
        cin>>fila2[i];
    }
}

void sumar(const matriz& m1, const matriz& m2){//Constructor para sumar las matrices
    matriz resultado;
    for(int i=0; i<tam; i++){//Suma los elementos de ambas filas y los almacena en "resultado"
        resultado.fila1[i]=m1.fila1[i]+m2.fila1[i];
        resultado.fila2[i]=m1.fila2[i]+m2.fila2[i];
    }
    cout<<"El resultado es: \n";
        cout<<resultado.fila1[0]<<"  "<<resultado.fila1[1]<<endl;
        cout<<resultado.fila2[0]<<"  "<<resultado.fila2[1]<<endl;
}

void matriz::multiplicar(){//Constructor para multiplicar la primera matriz por un número proporcionado
    matriz resultado;
    double numero;
    cout<<"Por qué número deseas multiplicar la matriz?: ";
    cin>>numero;
    for(int i=0; i<tam; i++){//Multiplica los valores de las filas por el número proporcionado
        resultado.fila1[i]=fila1[i]*numero;
        resultado.fila2[i]=fila2[i]*numero;
    }
    cout<<"El resultado es: \n";
    cout<<resultado.fila1[0]<<"  "<<resultado.fila1[1]<<endl;
    cout<<resultado.fila2[0]<<"  "<<resultado.fila2[1]<<endl;
}

int main(void){
    matriz matriz, otramatriz;
    int band=1;
    cout<<"Ingrese los datos de la primera matriz 2x2:"<<endl;
    matriz.llenarmatriz();
    cout<<"Ingrese los datos de la segunda matriz 2x2:"<<endl;
    otramatriz.llenarmatriz();
    while(band==1){
        int respuesta;
        cout<<"Qué desea realizar? (ingrese el número)"<<endl;
        cout<<" ==> Sumar matrices(1)"<<endl;
        cout<<" ==> Multiplicar la primera matriz(2)"<<endl;
        cout<<" ==> Salir (3)"<<endl;
        cin>>respuesta;
        switch(respuesta){
            case 1:
                sumar(matriz, otramatriz);//Como sumar se declaró como friend no es necesairo agregar "matriz" u "otramatriz" para acceder a este constructor
                break;
            case 2:
                matriz.multiplicar();
                break;
            case 3:
                band=0;
            default:
                cout<<"Opción inválida";
        }
    }
    return 0;
}
