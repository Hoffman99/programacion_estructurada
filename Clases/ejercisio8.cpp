#include <iostream>
#include<string>
#define TAM 100
using namespace std;

class Producto{
    private:
        string nombre;
        double precio;
        int cantidad;
    public:
        //Leer los valores
        string getnombre(){
            return this->nombre;
        }
        double getprecio(){
            return this->precio;
        }
        int getcantidad(){
            return this->cantidad;
        }
        //Modificar los valores
        void setnombre(){
            string _nombre;
            cin.ignore();
            getline(cin,_nombre);
            this->nombre=_nombre;
        }
        void setprecio(){
            double _precio;
            cin>>_precio;
            this->precio=_precio;
        }
        void setcantidad(){
            int _cantidad;
            cin>>_cantidad;
            this->cantidad=_cantidad;
        }

};

class Inventario{
    private:
        Producto objetos[TAM];
    public:
        void agregar(int& _i){
            cout<<"Nombre del producto ==> ";
            objetos[_i].setnombre();
            cout<<"Precio del producto ==> $";
            objetos[_i].setprecio();
            cout<<"Cantidad de productos ==> ";
            objetos[_i].setcantidad();
            _i+=1;
        }
        void buscar(int& _i){
            string _buscar;
            cout<<"Ingrese el nombre del producto que desea buscar ==> ";
            cin>>_buscar;
            for(int j=0;j<_i;j++){
                if(objetos[j].getnombre()==_buscar){
                    cout<<"Precios $"<<objetos[j].getprecio()<<endl;
                    cout<<"Cantidad "<<objetos[j].getcantidad()<<endl;
                }
            }
        }
        void total (int& _i){
            double _total=0;
            for(int j=0;j<_i;j++){
                _total+=objetos[j].getprecio()*objetos[j].getcantidad();
            }
            cout<<"El valor total del inventario es ==> $"<<_total<<endl;
        }
};

int main(){
    Inventario inventario;
    int i=0, band=1;
    while(band==1){
        int respuesta;
        cout<<"Qué desea realizar? (ingrese el número)"<<endl;
        cout<<" ==> Agregar artículo (1)"<<endl;
        cout<<" ==> Buscar artículo (2)"<<endl;
        cout<<" ==> Obtener valor total del inventario (3)"<<endl;
        cout<<" ==> Salir (4)"<<endl;
        cin>>respuesta;
        switch(respuesta){
            case 1:
                inventario.agregar(i);
                break;
            case 2:
                inventario.buscar(i);
                break;
            case 3:
                inventario.total(i);
                break;
            case 4:
                band=0;
            default:
                cout<<"Opción inválida";
        }
    }
    return 0;
}