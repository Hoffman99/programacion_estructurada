#include<iostream>

using namespace std;

class Polinomio{
    private:
        int a;
        int b;
        int c;
    public:
        friend void crear(Polinomio& p1, Polinomio& p2){
            cout<<"Crear 2 Polinomios"<<endl;
            cout<<"Considerando que ax²+bx+c, ingrese a, b, c."<<endl;
            cout<<"Primer Polinomio:"<<endl;
            cout<<"a ==> ";
            cin>>p1.a;
            cout<<"b ==> ";
            cin>>p1.b;
            cout<<"c ==> ";
            cin>>p1.c;
            cout<<"Segundo Polinomio:"<<endl;
            cout<<"a ==> ";
            cin>>p2.a;
            cout<<"b ==> ";
            cin>>p2.b;
            cout<<"c ==> ";
            cin>>p2.c;
        }
        friend void evaluar(Polinomio& p){
            double x=0, total;
            cout<<"Ingrese el punto en el que desea evaluar el polinomio ==> ";
            cin>>x;
            total=((x*x)*p.a)+(x*p.b)+p.c;
            cout<<"El resultado es ==> "<<total<<endl;
        }
        void sumar(Polinomio& p1, Polinomio& p2){
            a=p1.a+p2.a;
            b=p1.b+p2.b;
            c=p1.c+p2.c;
            cout<<"El resultado es => "<<a<<"x²+"<<b<<"x+"<<c<<endl;
        }

};

int main(){
    Polinomio polinomio1, polinomio2, polinomioTotal;
    int band=1;
    crear(polinomio1, polinomio2);
    while(band==1){
        int respuesta;
        cout<<"Qué desea realizar? (ingrese el número)"<<endl;
        cout<<" ==> Evaluar el primer Polinomio en un punto (1)"<<endl;
        cout<<" ==> Sumar los Polinomios(2)"<<endl;
        cout<<" ==> Salir (3)"<<endl;
        cin>>respuesta;
        switch(respuesta){
            case 1:
                evaluar(polinomio1);
                break;
            case 2:
                polinomioTotal.sumar(polinomio1, polinomio2);
                break;
            case 3:
                band=0;
            default:
                cout<<"Opción inválida";
        }
    }
    return 0;
}